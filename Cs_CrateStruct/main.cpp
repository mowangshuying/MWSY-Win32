#include <stdio.h>

struct Student
{
//	Student()
	//{
		//memset(this, 0, sizeof(Student));
	//}
	int m_age;
	int m_height;
	int m_weight;
	int m_sex;
};

int main()
{
	Student sd = { 1,2,3,4 };
	return 0;
}