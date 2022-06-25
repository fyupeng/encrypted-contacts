void create_menu();
typedef struct USER_node
{
	char name[20];
	char password[20]; 
	struct USER_node *next;
} USER_Node,*USER_Link;


typedef struct node
{
	char name[20];
	char number[20];
	struct node *next;
} Node,*Link;

void gotoxy(int x,int y)
{
	COORD coord;//�������λ��
	coord.X=x-1;
	coord.Y=y-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void clearLink(Link head)
{
	Link p; 
	while(head!=NULL)
	{
		p=head;
		head=head->next;
		free(p);
	}
}

void broadcast()
{
	int i,j;
	int a[12][75]={	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0},
	                {0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0},
                    {0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0},
                    {0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,1,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0},
				    {0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0},
			        {0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0}};
   for(i=0;i<75;i++)
   for(j=0;j<12;j++)
   {
   		if(a[j][i]==1)
		   {
		   		gotoxy(i,j);printf("*");
		   		Sleep(60);
		   }
   }
   for(i=0;i<75;i++)
   for(j=0;j<12;j++)
   {
   		if(a[j][i]==1)
		   {
		   		gotoxy(i,j);printf(" ");
		   		Sleep(60);
		   }
   }  
}

void displayNode(Link head)
{
	Link p;
	int x=1,y=1;
	p=head->next;
	int count=1;
	gotoxy(1,1);
	printf("\t��¼��\n");
	while(p!=NULL)
	{
		if((y-1)%20==0&&y!=1)
		{
			x+=20;
			y=1;
		}
	    y++;	
	    gotoxy(x,y);
		printf("%d:%s",count,p->name);
		printf("\n");
		count++;
		p=p->next;
	}
}

int queryNode(Link head,char x[])
{
	Link p;
	int count,flag=0;
	int a=1,b=1;
	p=head->next;
	count=0;
	while(p!=NULL)
	{
		count++;
		if(strcmp(p->name,x)==0)
		{
			flag=1;
			gotoxy(a,b);
			printf("%d:",count);
			gotoxy(a,b+1);
			printf("������%s ",p->name);
			gotoxy(a,b+2);
			printf("�绰���룺%s",p->number);
			b+=3; 
			Sleep(500);
		}
		p=p->next;
	}
	Sleep(10000);
	if(flag==0)
	{
		gotoxy(57,19);
		printf("�����ڣ�");
	}
	return 0;
}

int insertNode(Link head,int i,char x[])
{
	Link p,q,node;
	int count;
	p=head;
	count=0;
	while(p!=NULL&&count<i-1)
	{
		p=p->next;
		count++;
	}
	if(p==NULL)
	{
		return 0;
	}
	else
	{
		node=(Link)malloc(sizeof(Node));
		node->next=NULL;
		q=node;
		strcpy(q->name,x);
		gotoxy(55,19);
		printf("������绰����:");
		scanf_s("%s",&(q->number));
		q->next=p->next;
		p->next=q;
		return 1;
	}
}

int deleteNode_part1(Link head,char x[])
{
	Link p,q;
    int count=0,flag=0;	
    int a=1,b=1;
	if(head==NULL||head->next==NULL)
	{
		return 0;
	}
	p=head->next;
	q=head;
	while(p!=NULL)
	{
		if(strcmp(p->name,x)==0)
		{
			flag=1;
			count++;
			gotoxy(a,b);
			printf("%d:%s",count,p->name);
			b++;
		}		
    	q=p;
	    p=p->next;			
	}
	if(flag==1)
	{
		return 1;
	}
	gotoxy(1,19);
	printf("�����ڣ�");
	Sleep(3000);
	return 0;	
}
int deleteNode_part2(Link head,char x[])
{
	Link p,q;
	int count=0,select;
	if(head==NULL||head->next==NULL)
	{
		return 0;
	}
	p=head->next;
	q=head;
	gotoxy(57,18);
	printf("��ѡ��ɾ����:");
	scanf("%d",&select);
	while(p!=NULL)
	{
		if(strcmp(p->name,x)==0)
		{
			count++;
		}
		if(strcmp(p->name,x)==0&&select==count)
		{
			q->next=p->next;
		    printf("\n\t%d:%s",count,p->name);
			free(p);
			gotoxy(57,19);
			printf("ɾ���ɹ�!");
			return 1;
		}
	q=p;
	p=p->next;
	}
	printf("ɾ��ʧ�ܣ�\n");
	return 0; 
}

int WriteToFile(Link head)
{
	Link p;
	int count,x=1,y=1;
	p=head->next;
	FILE *fp=NULL;
	fp=fopen("telephbook.txt","w");
	if(fp==NULL)
	{
		gotoxy(1,19);
		printf("�ļ���ʧ�ܣ�");
		clearLink(head);
		exit(1); 
	}
	count=0;
	while(p!=NULL)
	{
		y++;
		if(y%20==0)x++;
		gotoxy(x,y);
		count++;
		printf("%d:%s",count,p->name);
		fprintf(fp,"\t\t%s\t",p->name);
		fprintf(fp,"\t%s",p->number);
		printf("\n");
		fputc('\n',fp);
		fflush(stdin);
		p=p->next;
	}
	fclose(fp);
	gotoxy(57,20);
	printf("����ɹ���");
	Sleep(1000);
	system("cls");
	return 1; 
}

void control_face(Link head)////////////////////////////////////////////////////////////////////ͨѶ¼ 
{
	int select=0,m=1,i,flag;
	char name[20];
    system("cls");
		do
	{
		create_menu();
		gotoxy(57,12);
		printf("��ѡ��");
		scanf("%d",&select);
		switch(select)
		{
			case 1: displayNode(head);break;
			case 2: gotoxy(57,13);printf("��1ȷ��");
					gotoxy(57,14);printf("��0����");
					gotoxy(57,15);printf("��ѡ��:");
			        scanf("%d",&m);
					if(!m)
					{
						system("cls");break;
					}
					gotoxy(57,18); 
			        printf("�������ݣ�");
			        scanf("%s",name);
			        system("cls");
			        create_menu();
					queryNode(head,name);system("cls");break;		
			case 3:                             gotoxy(57,13);printf("��1ȷ��");
												gotoxy(57,14);printf("��0����");
												gotoxy(57,15);printf("��ѡ��:");      
												scanf("%d",&m);
					                            if(!m)
												{
													system("cls");break;
												} 
												gotoxy(57,16);printf("����������");scanf("%s",name);
												gotoxy(57,17);printf("������ţ�");scanf("%d",&i);
												gotoxy(52,18);insertNode(head,i,name);system("cls");break;
										        
			case 4:	gotoxy(57,13);printf("��1ȷ��");
					gotoxy(57,14);printf("��0����");
					gotoxy(57,15);printf("��ѡ��:");   
					scanf("%d",&m);
					if(!m)
					{
						system("cls");break;
					}
					gotoxy(57,16);printf("����������");scanf("%s",name);
					system("cls");create_menu();
					flag=deleteNode_part1(head,name);
					if(flag==1)
					{deleteNode_part2(head,name);}
			        system("cls");break;
			case 5:                             gotoxy(57,13);printf("��1ȷ��");
												gotoxy(57,14);printf("��0����");
												gotoxy(57,15);printf("��ѡ��:");
			                                    scanf("%d",&m);
					                            if(!m)
												{
													system("cls");break;
												} 
			                                    WriteToFile(head);break;								         
			case 7: system("cls");gotoxy(20,19);printf("��ӭʹ�ã�");break; 
			default:gotoxy(20,19);printf("��������"); break;		
		} 
	}while(select==1||select==2||select==3||select==4||select==5); 	
	
	
}
void create_menu()
{
	gotoxy(50,3);
		printf("|");
		gotoxy(50,4);
		printf("|");
		gotoxy(50,5);
		printf("|");
		gotoxy(50,6);
		printf("|");
		gotoxy(50,7);
		printf("|");
		gotoxy(50,8);
		printf("|");
		gotoxy(50,9);
		printf("|");
		gotoxy(50,10);
		printf("|");
		gotoxy(50,11);
		printf("|");
		gotoxy(50,12);
		printf("|");
		gotoxy(50,13);
		printf("|");
		gotoxy(50,14);
		printf("|");
		gotoxy(50,15);
		printf("|");
		gotoxy(50,5);
		printf("�������������˵���������\n");
		gotoxy(57,6);
		printf("1.�鿴��������");
		gotoxy(57,7);
		printf("2.��������");
		gotoxy(57,8);
		printf("3.��������");
		gotoxy(57,9);
		printf("4.ɾ������");
		gotoxy(57,10);
		printf("5.��������");
		gotoxy(57,11);
		printf("7.�˳���");
}

void perfectNode(Link node)
{	
		printf("����������\n");
    	scanf("%s",&(node->name));	
    	printf("������绰����\n");
    	scanf("%s",&(node->number));
		fflush(stdin);	
}

Link new_build()
{
	Link head,rear,node;
	char flag='Y';
	head=(Link)malloc(sizeof(Node));
	head->next=NULL;
	rear=head;
	while(flag=='Y'||flag=='y')
	{
		node=(Link)malloc(sizeof(Node));
	    node->next=NULL; 
        perfectNode(node);
        rear->next=node;
       	rear=rear->next;
       	printf("ֹͣ��N��������Y\n");
       	scanf("%c",&flag);	
	}
	return head; 
}


Link ReadFromFile()
{
	Link q,head,rear;
	char a[20];
	head=(Link)malloc(sizeof(Node));
	head->next=NULL;
	FILE *fp=NULL;
	fp=fopen("telephbook.txt","r");
	if(fp==NULL)
	{
		printf("����δ����\n");
		clearLink(head);
		head=new_build();
	}
	rear=head;
	while(fscanf(fp,"%s",a)!=EOF)
	{
		q=(Link)malloc(sizeof(Node));
		q->next=NULL;
		strcpy(q->name,a);
		fscanf(fp,"%s",&(q->number));
		rear->next=q;
		rear=rear->next; 
	}
	fclose(fp);
	//printf("\n\t->->->->->->->->->->->->��ȡ�ɹ���<-<-<-<-<-<-<-<-<-<-<-<-\n");
    return head;
}

void clearUSER_Link(USER_Link USER_head)
{
	USER_Link p;
	while(USER_head!=NULL)
	{
		p=USER_head;
		USER_head=USER_head->next;
		free(p);
	}
}

USER_Link ReadFromFile_user() //��ȡ�ı��е��˺����룬�����˻���֤��ǰһ�� 
{
	USER_Link q,p,rear,USER_head;
	FILE *fp=NULL;
	char a[20];
	USER_head=(USER_Link)malloc(sizeof(USER_Node));
	USER_head->next=NULL;

	fp=fopen("student.txt","r");
	if(fp==NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		clearUSER_Link(USER_head);
		exit(1);
	}
	rear=USER_head;	
	while(fscanf(fp,"%s",a)!=EOF)
	{
		q=(USER_Link)malloc(sizeof(USER_Node));
		q->next=NULL;
		strcpy(q->name,a);
		fscanf(fp,"%s",&(q->password));
		rear->next=q;
		rear=rear->next; 
	}
	fclose(fp);
	//printf("��ȡ�ɹ���\n");  //���������⾳�洢���ı��е����� 
	p=USER_head->next;
    return USER_head;
}

/////////////////////////////////////////////////////////////////////////////////////////////////��¼���� 
int user_number()
{
	USER_Link p,q;
	int number=0;
	q=ReadFromFile_user();//�����˶��ڴ棬�����˹������ڴ�   1 
	p=q->next;
	while(p!=NULL)
	{
		number++;
		p=p->next;
	}
	clearUSER_Link(q);                                           //1
	return number;
}
int user_limit()
{
	int number=0;
	number=user_number();
	return number;
} 

int unique_user(char user_name[])
{
	USER_Link USER_head,p;
	char a[20];
	int flag=1;
	USER_head=ReadFromFile_user();//�����˶��ڴ棬�����˹������ڴ�    1
	p=USER_head->next;
	FILE *fp=NULL;
	fp=fopen("student.txt","r");
	if(fscanf(fp,"%s",a)!=EOF)
	{
		while(p!=NULL)
		{
			if(strcmp(p->name,user_name)==0)      //������û������ȡ�����е��û�����һ�Ա� 
			{
				printf("���˻���ע��\n");
				flag=0; 
			}
			p=p->next;
		} 
	}
	fclose(fp);
	clearUSER_Link(USER_head);                                      //1
	return flag; 
}

int identify_user(char user_name[],int &key1,int &key2) //��������ΪҪ������û��������룬������֤�û� 
{
	char a;
	char user_password[20];
	USER_Link p,USER_head;
	int sign=0;
	FILE *fp=NULL;
	fp=fopen("student.txt","r");
	if(fp==NULL)
	{
		printf("��ȡʧ�ܣ�"); 
	}
	printf("��¼����----------\n"); 
	printf("�������û�����");
	scanf("%s",user_name);
	printf("���������룺");
	scanf("%s",user_password); 
	USER_head=ReadFromFile_user();//�����˶��ڴ棬�����˹������ڴ�   1 
	p=USER_head->next;
	while(p!=NULL)
	{
		if(strcmp(user_name,p->name)==0&&strcmp(user_password,p->password)==0)
		{
			printf("��֤�ɹ���\n");
			key1=key2=0;
			system("cls");
			sign=1;
			break; 
		}
		p=p->next;
	}
	clearUSER_Link(USER_head);                                          //1 
	if(fscanf(fp,"%c",&a)==EOF)
	{
		printf("Ŀǰ���˻���\n");
		fclose(fp);
		key1=1;
	}
	fp=fopen("student.txt","r");
	if(sign==0&&fscanf(fp,"%c",&a)!=EOF)
	{
		printf("�û������������\n");
		fclose(fp);
		key2=1;
	}
	fclose(fp);
	return 0;
}

int clear_user(char user_name[])
{
	FILE *fp=NULL;
	USER_Link USER_head,p;
	USER_head=ReadFromFile_user();//�����˶��ڴ棬�����˹������ڴ�   1 
	p=USER_head->next;
	fp=fopen("student.txt","r");
	if(fp==NULL)
	{
		printf("�ļ���ʧ�ܣ�");
		clearUSER_Link(USER_head);                                        //1
		exit(1); 
	}
	fclose(fp);
	fp=fopen("student.txt","w");
	while(p!=NULL)
	{
		if(strcmp(p->name,user_name)!=0)
		{			
	    	fprintf(fp,"%s\t",p->name);
			fprintf(fp,"%s",p->password);
			fputc('\n',fp);
			fflush(stdin);		
		}
		p=p->next;
	}
	fclose(fp);	
	clearUSER_Link(USER_head);                                            //1
}

int remove_user_password()
{
	char user_name[20],user_password[20];
	int flag=0,sign=0;
    USER_Link USER_head,p;
    do
    {
    	printf("�������˻��û�����");
		scanf("%s",&user_name);
		fflush(stdin); 
		printf("����������:");
		scanf("%s",&user_password);
		fflush(stdin);
		USER_head=ReadFromFile_user();  //�����˶��ڴ棬�����˹������ڴ�   1
		p=USER_head->next;
		while(p!=NULL)
		{
			if(strcmp(p->name,user_name)==0&&strcmp(p->password,user_password)==0)
			{
				printf("��֤�ɹ���\n");
				flag=1;
				sign=1;
				clearUSER_Link(USER_head); //������ֻ��������һ�� ����֤�ɹ����٣�        1
				break; 
			}
			p=p->next;
		}
		clearUSER_Link(USER_head); //һ��ѭ��ʧ��ִ��һ�Σ���֤ʧ�����٣� 
		
		if(flag==0)
	    {
			printf("��֤ʧ��,��������֤\n"); 
		}
	
	}while(sign!=1);
	//ֻ��flag=1��sign=1,��������ѭ��������֤�ɹ� 
	clear_user(user_name);
	printf("�����������룺");
	scanf("%s",&user_password);
	fflush(stdin);
	FILE *fp=NULL;
	fp=fopen("student.txt","r");
	if(fp==NULL)
	{
		printf("�ļ���ʧ�ܣ�");
		exit(1); 
	}
	fclose(fp);
	fp=fopen("student.txt","a");
	fprintf(fp,"%s\t",user_name);
	fprintf(fp,"%s",user_password);
	fputc('\n',fp);
	fclose(fp);
    printf("�����޸ĳɹ���\n");
	return 0; 
}

int delete_user_prime()
{
	char a[20];
	FILE *fp=NULL;	
	fp=fopen("student.txt","r");
	if(fscanf(fp,"%s",a)==EOF)
	{
	printf("�����ڸ��û���ע��ʧ�ܣ�\n");
	fclose(fp);
	exit(1); 
	}
	fclose(fp);
    return 0;
}

int delete_user(char user_name[])  //�뺯��clear_user(char user_name,char user_password) �е������ַ�����ͬһ�� 
{
	char a[20];
	FILE *fp=NULL;	
	fp=fopen("student.txt","r");
	if(fscanf(fp,"%s",a)==EOF)
	{
	printf("�����ڸ��û���ע��ʧ�ܣ�\n");
	fclose(fp);
	return 0; 
	}
	clear_user(user_name);
	printf("�˻�ע���ɹ���\n");
	fclose(fp);
	return 0;
}

void display_user()
{
	USER_Link head,p;
	int count=0;
	head=ReadFromFile_user();
	p=head->next;
	while(p!=NULL){
		count++;
		printf("%d.%s\n",count,p->name);
		p=p->next;
	}
	printf("\n");
	if(count==0)
		printf("���û���\n\n"); 
	clearUSER_Link(head);
}

int create_user(char administrator_name[])
{
	int key1=1,key2=1;
	char ch;
	char user_name[20];
	char user_password[20];
	char user_password_[20];
	int flag=0,sign=0,number=0,i,select;
	USER_Link p,USER_head;
	FILE *fp=NULL;
	fp=fopen("student.txt","r"); //��ʧ�ܱ����ı�δ����,��"r"ֻ�������ж��Ƿ����ı�����
	if(fp==NULL)
	{
		printf("��ǰ���û���Ϊ���������û�\n");
	}
	fp=fopen("student.txt","a"); //׷�ӷ�ʽʹ��"a" 	
	number=user_limit();
	printf("Ŀǰ��%dλ�û��������´���%dλ�û�\n",number,3-number);
		do{
				key1=1,key2=1;
				flag=0,sign=0,number=user_limit();
			    printf("1.�������û�\n2.��¼�˻�\n3.�鿴�ѽ��˻�\n4.�޸�����\n5.ע���˻�\n0,�˳���\n��ѡ��");
			    scanf("%d",&select);
		    	switch(select)
				{
					case 1:				if(number==3)
					                    {
											printf("�û����Ѵﵽ3λ���޷�����,���¼\n");
											flag=2; 
										}
					            while(flag==0)
								{
									flag=1;
									do
									{										 
										printf("�������û�����"); //���û���������д���ַ������� 
										scanf("%s",user_name);
										fflush(stdin);
										printf("���������룺");
										scanf("%s",user_password);
										fflush(stdin);
										printf("���ٴ��������룺");
										scanf("%s",user_password_);
										fflush(stdin);
										flag=unique_user(user_name);	
									}while(flag==0);			
									if(strcmp(user_password,user_password_)!=0)
									{
										printf("���벻һ�£�\n");
										flag=0; 
									}			
									for(i=0;user_name[i]!='\0';i++)
									{
										if((user_name[i]<'a'||user_name[i]>'z')&&(user_name[i]<'A'||user_name[i]>'Z')&&(user_name[i]<'0'||user_name[i]>'9'))
										{
											printf("���ܺ���'_',���ֵ�������ţ��������֡���ĸ��ϡ�\n\n");
											printf("���������룡\n"); 
											flag=0;
											break;				 
										}
									}
									if(flag==1)
									{
								        fprintf(fp,"%s\t",user_name);  //���ַ������е��û���������д���ı��� 
    									fprintf(fp,"%s",user_password);
										fputc('\n',fp);
										fflush(stdin);
										fclose(fp);
										printf("�����ɹ���");
										printf("����˻�����Ч�������Ʊ���\n");
										printf("�û�����%s\n",user_name);
										printf("���룺%s\n",user_password);				
									}
								 
								}
								break;
					case 2: identify_user(administrator_name,key1,key2);break;
					case 3: display_user();break;
					case 4: remove_user_password();flag=0;break;
					case 5:     do
							    {
							    	printf("�������˻��û�����");
									scanf("%s",&user_name);
									fflush(stdin); 
									printf("����������:");
									scanf("%s",&user_password);
									fflush(stdin);
								    delete_user_prime(); //����������֮ǰ��������ע��ʧ��ʱ�ͻ������ڴ�û������ 
									USER_head=ReadFromFile_user();  //�����˶��ڴ棬�����˹������ڴ�   1
									p=USER_head->next;
									while(p!=NULL)
									{
										if(strcmp(p->name,user_name)==0&&strcmp(p->password,user_password)==0)
										{
											printf("��֤�ɹ���\n");
											flag=1;
											sign=1;
											break; 
										}
										p=p->next;
									}
									if(p==NULL){
										printf("�����ڸ��û���ע��ʧ�ܣ�\n");
										
									}
									clearUSER_Link(USER_head); //��һ���ǳ���Ҫ��û����һ��������й¶�ܶ��ڴ� 
									
									if(flag==0)
								    {
										printf("��֤ʧ��,��������֤\n"); 
									}
								
								}while(sign!=1);
					            delete_user(user_name);
								flag=0;break;
		    		case 0:	printf("���˳���\n");ch=getchar();exit(0);
				    default : printf("����������������룡\n");break;
				}
				
		  }while(!(key1==0 && key2==0)); //key1��key2��ʼֵ��Ϊ 1������ִ�к�Ϊ�ű�ʾ�ɹ� 


		 
	return 0;
}












