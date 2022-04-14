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
	printf("m_age:%d,m_height:%d,m_weight:%d,m_sex:%d\n", sd.m_age, sd.m_height, sd.m_weight, sd.m_sex);
	return 0;
}