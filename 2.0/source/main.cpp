 #include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include "head.h"
int main()
{
	Link head;
	system("mode con cols=120 lines=30");
	char administrator_name[20];
	create_user(administrator_name);//用户菜单面板 
    broadcast();  //欢迎界面动画
    gotoxy(45,24); 
	printf("\"%s\"用户",administrator_name);
	Sleep(3000);
	system("cls"); 
	head=ReadFromFile();//读取个人信息 
	control_face(head); //个人信息管理面板 
	clearLink(head);//销毁个人信息读取数据 
	return 0;
}
