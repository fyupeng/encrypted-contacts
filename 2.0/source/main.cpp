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
	create_user(administrator_name);//�û��˵���� 
    broadcast();  //��ӭ���涯��
    gotoxy(45,24); 
	printf("\"%s\"�û�",administrator_name);
	Sleep(3000);
	system("cls"); 
	head=ReadFromFile();//��ȡ������Ϣ 
	control_face(head); //������Ϣ������� 
	clearLink(head);//���ٸ�����Ϣ��ȡ���� 
	return 0;
}
