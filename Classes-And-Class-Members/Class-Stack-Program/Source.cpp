#include <iostream>
#include <vector>
#include <cassert>

class Stack
{
	static const int m_maxStackLength{ 10 };
	int m_array[m_maxStackLength];
	int m_length;

public:
	Stack()
	{
		m_length = { 0 };



	}
	void reset()
	{
		m_length = 0;
	}
	bool push(int num)
	{
		if (m_length == m_maxStackLength)
			return false;
		else
		{
			m_array[m_length++] = num;
			//length++;
			return true;
		}
	}
	int pop()
	{
		assert(m_length > 0 && "Array is empty!");

		return m_array[--m_length];
		//length--;
	}

	void print()
	{
		std::cout << "( ";
		for (int i = 0; i < m_length; ++i)
			std::cout << m_array[i] << " ";
		std::cout << " )\n";

	}
};

int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}