#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include "head.h"
int main()
{
	Link head;
	char administrator_name[20];
	create_user(administrator_name);//�û��˵���� 
    broadcast();  //��ӭ���涯�� 
    gotoxy(30,12); 
	printf("��ӭ\"%s\"�û�",administrator_name);
	Sleep(2000);
	head=ReadFromFile();//��ȡ������Ϣ 
	control_face(head); //������Ϣ������� 
	clearLink(head);//���ٸ�����Ϣ��ȡ���� 
	return 0;
}
