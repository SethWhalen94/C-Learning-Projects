#include <iostream>

class IntPair
{
public:
	int m_int1;
	int m_int2;

	void set(int a, int b)
	{
		m_int1 = a;
		m_int2 = b;

	}
	void print()
	{
		std::cout << "Pair (" << m_int1 << ", " << m_int2 << ")" << std::endl;
	}


};

int main()
{
	IntPair p1;
	p1.set(1, 1);

	IntPair p2{ 2, 2 };

	p1.print();
	p2.print();

	return 0;
}