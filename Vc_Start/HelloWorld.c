/*
* L - long(32λ��ָ�룩
* P - point
* STR - �ַ���
* T - TCHAR - char
*/

/*
* ��Ҫ����window����
*/
#include<windows.h>

/*������ windows api������
����Ҫ�� WINAPI*/
int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR pszCmdLine,int nShow)
{
    MessageBox(NULL,"Hello-world-text","Hello-world-title",MB_OKCANCEL);
    return 0;
}

/*�������Ӳ��貽�裺
* 1����Developer Command Prompt for VS 2019
* 2������cl
* 3������helloworld.c�ļ���
* 4�����벢���� 
    cl helloworld.c /c
    link helloworld.obj
  5��ִ��helloworld
    helloworld
*/