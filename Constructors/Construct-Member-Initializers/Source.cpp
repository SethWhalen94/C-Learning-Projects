#include <iostream>
#include <cstdint>


class RGBA
{
private:
	std::uint_fast8_t m_red, m_green, m_blue, m_alpha;

public:
	RGBA(std::uint_fast8_t red = 0, std::uint_fast8_t green=0, std::uint_fast8_t blue=0, std::uint_fast8_t alpha=255)
		: m_red (red),
		m_green (green),
		m_blue (blue),
		m_alpha (alpha)
	{
	}
	void print()
	{
		std::cout << 
		"r=" << static_cast<int>(m_red) <<
		" g=" << static_cast<int>(m_green) << 
		" b=" << static_cast<int>(m_blue) <<
		" a=" << static_cast<int>(m_alpha) << '\n';

	}

};

int main(int argc, char* argv[])
{
	long x = strtol(argv[1], NULL, 10);
	long y = strtol(argv[2], NULL, 10);
	long z = strtol(argv[3], NULL, 10);
	RGBA teal(static_cast<std::uint_fast8_t>(x), static_cast<std::uint_fast8_t>(y), static_cast<std::uint_fast8_t>(z));
	teal.print();

	return 0;

}