#include <stdio.h>

struct tagPerson1 
{
	char m_name[10];
	int m_age;
};

struct tagPerson2
{
	int m_age;
	char m_name[10];
};


int main(int argc, char** argv) 
{
	tagPerson1 p1;
	tagPerson2 p2;

	printf("&p1 = %p,p1.m_name = %p\n",&p1,p1.m_name);
	printf("&p2 = %p,&(p2.m_age) = %p\n",&p2,&(p2.m_age));

	return 0;
}