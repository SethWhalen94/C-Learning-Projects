#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>


void display_usage(const char* argv0_)
{
	std::cout << "Usage: " << argv0_ << "<DLL File> <[-c < Program Path to Execute >] | [-p < Process Name >] | [-w < Window Title >]>" << std::endl;
}

DWORD get_process_id_by_creation(char* program_path_, HANDLE* creation_handle_)
{
	// Initialize variables.
	STARTUPINFO startup_information;
	PROCESS_INFORMATION process_information;
	// Fill startup_information and process_information with 0's
	memset(&startup_information, 0, sizeof(startup_information));
	memset(&process_information, 0, sizeof(process_information));

	startup_information.cb = sizeof(startup_information);

	// Create the process
	if (CreateProcess(NULL, program_path_, 0, 0, false, CREATE_SUSPENDED, 0, 0, &startup_information, &process_information))
	{
		*creation_handle_ = process_information.hThread;

		return process_information.dwProcessId;

	}

	return NULL;
}

DWORD get_process_id_by_process_name(const char* process_name_)
{
	PROCESSENTRY32 process_entry = { 0 };
	HANDLE processes_snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	process_entry.dwSize = sizeof(PROCESSENTRY32);

	if (processes_snapshot == INVALID_HANDLE_VALUE) return 0;

	// Convert process_entry.szExeFile to char[] array
	// char szANSIString[MAX_PATH];

	// WideCharToMultiByte(CP_ACP,
	// 	WC_COMPOSITECHECK,
	//	process_entry.szExeFile,
	//	-1,
	//	szANSIString,
	//	sizeof(szANSIString),
	//	NULL,
	//	NULL);

	// Loop to find the process we're after.

	if ( Process32First( processes_snapshot, &process_entry ) )
	{
		do
		{
			if (strcmp(process_entry.szExeFile, process_name_) == 0)
			{
				CloseHandle(processes_snapshot);

				return process_entry.th32ProcessID;
			}
		} while (Process32Next(processes_snapshot, &process_entry));
	}

	CloseHandle(processes_snapshot);

	return NULL;
}

DWORD get_process_id_by_window_title(const char* window_title_)
{
	// Get handle to the process using the name of its window.
	HWND window_handle = FindWindow(NULL, window_title_);

	if (window_handle == NULL)
	{
		return NULL;
	}

	// Return process ID of window if not NULL
	DWORD process_id;

	GetWindowThreadProcessId(window_handle, &process_id);

	return process_id;
}


bool dll_injection(DWORD process_id_, const char* dll_file_)
{
	// Get full Dll file path.
	TCHAR dll_path[MAX_PATH];

	GetFullPathName(dll_file_, MAX_PATH, dll_path, NULL);

	// Get LoadLibraryA function.


	// LPVOID load_library = GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");
	DWORD dWord;
	LPTHREAD_START_ROUTINE load_library_address = (LPTHREAD_START_ROUTINE)GetProcAddress(LoadLibrary("kernel32.dll"), "LoadLibraryA");

	std::cout << "[+] Grabbing LoadLibraryA @ address: " << load_library_address << std::endl;
	if (load_library_address == NULL)
	{
		std::cerr << "[!] Unable to get LoadLibraryA from kernel32.dll" << std::endl;

		return false;
	}


	// Load the process.
	HANDLE process_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, process_id_);

	std::cout << "[+] Getting a handle to the target process." << std::endl;

	if (process_handle == NULL)
	{
		std::cerr << "[!] Failed to open target process." << std::endl;

		return false;
	}

	// Allocate space for the DLL to be put.
	LPVOID dll_address = VirtualAllocEx(process_handle, 0, strlen(dll_path), MEM_RESERVE | MEM_COMMIT,
		PAGE_EXECUTE_READWRITE);

	std::cout << "[+] Attempting to allocate " << strlen(dll_path) << " bytes of memory." << std::endl;

	if (dll_address == NULL)
	{
		std::cerr << "[!] Unable to allocate memory in target process." << std::endl;

		CloseHandle(process_handle);

		return false;
	}

	// Write DLL to allocated space.
	BOOL written_memory = WriteProcessMemory(process_handle, dll_address, dll_path, strlen(dll_path), NULL);

	std::cout << "[+] Writing memory to process @ " << dll_address << std::endl;

	if (written_memory == NULL)
	{
		std::cerr << "[!] Unable to write to memory in target process." << std::endl;

		CloseHandle(process_handle);

		return false;
	}

	// Use LoadLibraryA function that we grabbed to load our dll.
	HANDLE dll_thread_handle = CreateRemoteThread(process_handle, 0, 0, load_library_address, dll_address, 0, &dWord);

	std::cout << "[+] Creating remote thread in target process." << std::endl;

	if (dll_thread_handle == NULL)
	{
		std::cerr << "[!] Failed to create remote thread." << std::endl;

		CloseHandle(process_handle);

		return false;
	}

	CloseHandle(dll_thread_handle);
	CloseHandle(process_handle);

	return true;
}

int main(int argc_, char** argv_)
{
	// Check command line usage.
	if (argc_ != 4 || strlen(argv_[2]) != 2)
	{
		display_usage(argv_[0]);
		return -1;
	}

	// Get process ID.
	DWORD process_id = NULL;
	HANDLE creation_handle = NULL;

	switch (argv_[2][1])
	{
	case 'C':
	case 'c':
		process_id = get_process_id_by_creation(argv_[3], &creation_handle);
		break;

	case 'P':
	case 'p':
		process_id = get_process_id_by_process_name(argv_[3]);
		break;

	case 'W':
	case 'w':
		process_id = get_process_id_by_window_title(argv_[3]);
		break;

	default:
		display_usage(argv_[0]);
		return -2;
	}

	// DLL injection happens here.
	std::cout << "Process ID obtained: " << process_id << std::endl;
	std::cout << "Injection: " << (dll_injection(process_id, argv_[1]) ? "Succeeded" : "Failed") << std::endl;


	// Resume process if it was created by us(because we create it suspended).
	if (creation_handle)
	{
		ResumeThread(creation_handle);
	}

	return 0;
}