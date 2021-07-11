#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		m_x = 0;
		m_y = 0;
	}

	~A()
	{

	}

	int m_x;
	int m_y;
};

class S
{
public:
	A* m_A;
	void setA()
	{
		A a;
		a.m_x = 1;
		a.m_y = 2;
		m_A = &a;
	}
	void printS()
	{
		std::cout <<m_A->m_x<<m_A->m_y << std::endl;
	}
};


int main(int argc, char** argv)
{
	S s;
	s.setA();
	s.printS();
	return 0;
}