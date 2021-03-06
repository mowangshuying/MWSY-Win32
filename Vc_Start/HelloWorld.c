/*
* L - long(32位长指针）
* P - point
* STR - 字符串
* T - TCHAR - char
*/

/*
* 需要引入window函数
*/
#include<windows.h>

/*主函数 windows api函数调
用需要用 WINAPI*/
int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR pszCmdLine,int nShow)
{
    MessageBox(NULL,"Hello-world-text","Hello-world-title",MB_OKCANCEL);
    return 0;
}

/*编译连接步骤步骤：
* 1、打开Developer Command Prompt for VS 2019
* 2、输入cl
* 3、进入helloworld.c文件夹
* 4、编译并连接 
    cl helloworld.c /c
    link helloworld.obj
  5、执行helloworld
    helloworld
*/