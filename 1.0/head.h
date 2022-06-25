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
	COORD coord;//设置鼠标位置
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
	printf("\t名录：\n");
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
			printf("姓名：%s ",p->name);
			gotoxy(a,b+2);
			printf("电话号码：%s",p->number);
			b+=3; 
			Sleep(500);
		}
		p=p->next;
	}
	Sleep(10000);
	if(flag==0)
	{
		gotoxy(57,19);
		printf("不存在！");
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
		printf("请输入电话号码:");
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
	printf("不存在！");
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
	printf("请选择删除项:");
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
			printf("删除成功!");
			return 1;
		}
	q=p;
	p=p->next;
	}
	printf("删除失败！\n");
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
		printf("文件打开失败！");
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
	printf("保存成功！");
	Sleep(1000);
	system("cls");
	return 1; 
}

void control_face(Link head)////////////////////////////////////////////////////////////////////通讯录 
{
	int select=0,m=1,i,flag;
	char name[20];
    system("cls");
		do
	{
		create_menu();
		gotoxy(57,12);
		printf("请选择：");
		scanf("%d",&select);
		switch(select)
		{
			case 1: displayNode(head);break;
			case 2: gotoxy(57,13);printf("按1确认");
					gotoxy(57,14);printf("按0返回");
					gotoxy(57,15);printf("请选择:");
			        scanf("%d",&m);
					if(!m)
					{
						system("cls");break;
					}
					gotoxy(57,18); 
			        printf("输入数据：");
			        scanf("%s",name);
			        system("cls");
			        create_menu();
					queryNode(head,name);system("cls");break;		
			case 3:                             gotoxy(57,13);printf("按1确认");
												gotoxy(57,14);printf("按0返回");
												gotoxy(57,15);printf("请选择:");      
												scanf("%d",&m);
					                            if(!m)
												{
													system("cls");break;
												} 
												gotoxy(57,16);printf("输入姓名：");scanf("%s",name);
												gotoxy(57,17);printf("安插序号：");scanf("%d",&i);
												gotoxy(52,18);insertNode(head,i,name);system("cls");break;
										        
			case 4:	gotoxy(57,13);printf("按1确认");
					gotoxy(57,14);printf("按0返回");
					gotoxy(57,15);printf("请选择:");   
					scanf("%d",&m);
					if(!m)
					{
						system("cls");break;
					}
					gotoxy(57,16);printf("输入姓名：");scanf("%s",name);
					system("cls");create_menu();
					flag=deleteNode_part1(head,name);
					if(flag==1)
					{deleteNode_part2(head,name);}
			        system("cls");break;
			case 5:                             gotoxy(57,13);printf("按1确认");
												gotoxy(57,14);printf("按0返回");
												gotoxy(57,15);printf("请选择:");
			                                    scanf("%d",&m);
					                            if(!m)
												{
													system("cls");break;
												} 
			                                    WriteToFile(head);break;								         
			case 7: system("cls");gotoxy(20,19);printf("欢迎使用！");break; 
			default:gotoxy(20,19);printf("输入有误！"); break;		
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
		printf("【◆◆◆◆◆菜单栏◇◇◇◇◇】\n");
		gotoxy(57,6);
		printf("1.查看所有数据");
		gotoxy(57,7);
		printf("2.查找数据");
		gotoxy(57,8);
		printf("3.加入数据");
		gotoxy(57,9);
		printf("4.删除数据");
		gotoxy(57,10);
		printf("5.保存数据");
		gotoxy(57,11);
		printf("7.退出！");
}

void perfectNode(Link node)
{	
		printf("请输入姓名\n");
    	scanf("%s",&(node->name));	
    	printf("请输入电话号码\n");
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
       	printf("停止按N，继续按Y\n");
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
		printf("数据未保存\n");
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
	//printf("\n\t->->->->->->->->->->->->读取成功！<-<-<-<-<-<-<-<-<-<-<-<-\n");
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

USER_Link ReadFromFile_user() //读取文本中的账号密码，连接账户验证的前一步 
{
	USER_Link q,p,rear,USER_head;
	FILE *fp=NULL;
	char a[20];
	USER_head=(USER_Link)malloc(sizeof(USER_Node));
	USER_head->next=NULL;

	fp=fopen("student.txt","r");
	if(fp==NULL)
	{
		printf("文件打开失败！\n");
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
	//printf("读取成功！\n");  //表明链表意境存储了文本中的数据 
	p=USER_head->next;
    return USER_head;
}

/////////////////////////////////////////////////////////////////////////////////////////////////登录界面 
int user_number()
{
	USER_Link p,q;
	int number=0;
	q=ReadFromFile_user();//申请了堆内存，必须人工清理内存   1 
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
	USER_head=ReadFromFile_user();//申请了堆内存，必须人工清理内存    1
	p=USER_head->next;
	FILE *fp=NULL;
	fp=fopen("student.txt","r");
	if(fscanf(fp,"%s",a)!=EOF)
	{
		while(p!=NULL)
		{
			if(strcmp(p->name,user_name)==0)      //输入的用户名与读取链表中的用户名逐一对比 
			{
				printf("该账户已注册\n");
				flag=0; 
			}
			p=p->next;
		} 
	}
	fclose(fp);
	clearUSER_Link(USER_head);                                      //1
	return flag; 
}

int identify_user(char user_name[],int &key1,int &key2) //中括号内为要输入的用户名和密码，用于验证用户 
{
	char a;
	char user_password[20];
	USER_Link p,USER_head;
	int sign=0;
	FILE *fp=NULL;
	fp=fopen("student.txt","r");
	if(fp==NULL)
	{
		printf("读取失败！"); 
	}
	printf("登录界面----------\n"); 
	printf("请输入用户名：");
	scanf("%s",user_name);
	printf("请输入密码：");
	scanf("%s",user_password); 
	USER_head=ReadFromFile_user();//申请了堆内存，必须人工清理内存   1 
	p=USER_head->next;
	while(p!=NULL)
	{
		if(strcmp(user_name,p->name)==0&&strcmp(user_password,p->password)==0)
		{
			printf("验证成功！\n");
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
		printf("目前无账户！\n");
		fclose(fp);
		key1=1;
	}
	fp=fopen("student.txt","r");
	if(sign==0&&fscanf(fp,"%c",&a)!=EOF)
	{
		printf("用户名或密码错误！\n");
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
	USER_head=ReadFromFile_user();//申请了堆内存，必须人工清理内存   1 
	p=USER_head->next;
	fp=fopen("student.txt","r");
	if(fp==NULL)
	{
		printf("文件打开失败！");
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
    	printf("请输入账户用户名：");
		scanf("%s",&user_name);
		fflush(stdin); 
		printf("请输入密码:");
		scanf("%s",&user_password);
		fflush(stdin);
		USER_head=ReadFromFile_user();  //申请了堆内存，必须人工清理内存   1
		p=USER_head->next;
		while(p!=NULL)
		{
			if(strcmp(p->name,user_name)==0&&strcmp(p->password,user_password)==0)
			{
				printf("验证成功！\n");
				flag=1;
				sign=1;
				clearUSER_Link(USER_head); //到这里只是清理了一遍 （验证成功销毁）        1
				break; 
			}
			p=p->next;
		}
		clearUSER_Link(USER_head); //一次循环失败执行一次（验证失败销毁） 
		
		if(flag==0)
	    {
			printf("验证失败,请重新验证\n"); 
		}
	
	}while(sign!=1);
	//只有flag=1和sign=1,结束内外循环，即验证成功 
	clear_user(user_name);
	printf("请输入新密码：");
	scanf("%s",&user_password);
	fflush(stdin);
	FILE *fp=NULL;
	fp=fopen("student.txt","r");
	if(fp==NULL)
	{
		printf("文件打开失败！");
		exit(1); 
	}
	fclose(fp);
	fp=fopen("student.txt","a");
	fprintf(fp,"%s\t",user_name);
	fprintf(fp,"%s",user_password);
	fputc('\n',fp);
	fclose(fp);
    printf("密码修改成功！\n");
	return 0; 
}

int delete_user_prime()
{
	char a[20];
	FILE *fp=NULL;	
	fp=fopen("student.txt","r");
	if(fscanf(fp,"%s",a)==EOF)
	{
	printf("不存在该用户，注销失败！\n");
	fclose(fp);
	exit(1); 
	}
	fclose(fp);
    return 0;
}

int delete_user(char user_name[])  //与函数clear_user(char user_name,char user_password) 中的两个字符串是同一个 
{
	char a[20];
	FILE *fp=NULL;	
	fp=fopen("student.txt","r");
	if(fscanf(fp,"%s",a)==EOF)
	{
	printf("不存在该用户，注销失败！\n");
	fclose(fp);
	return 0; 
	}
	clear_user(user_name);
	printf("账户注销成功！\n");
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
		printf("无用户！\n\n"); 
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
	fp=fopen("student.txt","r"); //打开失败表明文本未创建,用"r"只是用来判断是否有文本创建
	if(fp==NULL)
	{
		printf("当前无用户，为您创建新用户\n");
	}
	fp=fopen("student.txt","a"); //追加方式使用"a" 	
	number=user_limit();
	printf("目前有%d位用户，允许新创建%d位用户\n",number,3-number);
		do{
				key1=1,key2=1;
				flag=0,sign=0,number=user_limit();
			    printf("1.创建新用户\n2.登录账户\n3.查看已建账户\n4.修改密码\n5.注销账户\n0,退出！\n请选择：");
			    scanf("%d",&select);
		    	switch(select)
				{
					case 1:				if(number==3)
					                    {
											printf("用户名已达到3位，无法创建,请登录\n");
											flag=2; 
										}
					            while(flag==0)
								{
									flag=1;
									do
									{										 
										printf("请输入用户名："); //将用户名和密码写入字符数组中 
										scanf("%s",user_name);
										fflush(stdin);
										printf("请输入密码：");
										scanf("%s",user_password);
										fflush(stdin);
										printf("请再次输入密码：");
										scanf("%s",user_password_);
										fflush(stdin);
										flag=unique_user(user_name);	
									}while(flag==0);			
									if(strcmp(user_password,user_password_)!=0)
									{
										printf("密码不一致！\n");
										flag=0; 
									}			
									for(i=0;user_name[i]!='\0';i++)
									{
										if((user_name[i]<'a'||user_name[i]>'z')&&(user_name[i]<'A'||user_name[i]>'Z')&&(user_name[i]<'0'||user_name[i]>'9'))
										{
											printf("不能含有'_',汉字等特殊符号，允许数字、字母混合。\n\n");
											printf("请重新输入！\n"); 
											flag=0;
											break;				 
										}
									}
									if(flag==1)
									{
								        fprintf(fp,"%s\t",user_name);  //将字符数组中的用户名和密码写入文本中 
    									fprintf(fp,"%s",user_password);
										fputc('\n',fp);
										fflush(stdin);
										fclose(fp);
										printf("创建成功！");
										printf("你的账户已生效，请妥善保管\n");
										printf("用户名：%s\n",user_name);
										printf("密码：%s\n",user_password);				
									}
								 
								}
								break;
					case 2: identify_user(administrator_name,key1,key2);break;
					case 3: display_user();break;
					case 4: remove_user_password();flag=0;break;
					case 5:     do
							    {
							    	printf("请输入账户用户名：");
									scanf("%s",&user_name);
									fflush(stdin); 
									printf("请输入密码:");
									scanf("%s",&user_password);
									fflush(stdin);
								    delete_user_prime(); //必须在申请之前，否则在注销失败时就会遗留内存没有清理 
									USER_head=ReadFromFile_user();  //申请了堆内存，必须人工清理内存   1
									p=USER_head->next;
									while(p!=NULL)
									{
										if(strcmp(p->name,user_name)==0&&strcmp(p->password,user_password)==0)
										{
											printf("验证成功！\n");
											flag=1;
											sign=1;
											break; 
										}
										p=p->next;
									}
									if(p==NULL){
										printf("不存在该用户，注销失败！\n");
										
									}
									clearUSER_Link(USER_head); //这一步非常重要，没有这一步，将会泄露很多内存 
									
									if(flag==0)
								    {
										printf("验证失败,请重新验证\n"); 
									}
								
								}while(sign!=1);
					            delete_user(user_name);
								flag=0;break;
		    		case 0:	printf("已退出！\n");ch=getchar();exit(0);
				    default : printf("输入错误！请重新输入！\n");break;
				}
				
		  }while(!(key1==0 && key2==0)); //key1、key2初始值都为 1，两者执行后都为才表示成功 


		 
	return 0;
}












