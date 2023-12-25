#include"contact.h"
void menu()
{
	printf("*******通讯录*******\n");
	printf("*******1.增加*******\n");
	printf("*******2.删除*******\n");
	printf("*******3.查询*******\n");
	printf("*******4.修改*******\n");
	printf("*******5.展示*******\n");
	printf("*******6.排序*******\n");
	printf("*******7.存储*******\n");
	printf("*******0.退出*******\n");
	printf("********************\n");
}


int main()
{
	struct Contact con;	//创建通讯录 
	int i/*,size=0*/;//size表示通讯录中目前有几个元素 
	Init(&con);//初始化 
	do
	{
		menu();
		printf("请输入：>\n");
		scanf("%d",&i);
		switch(i)
		{
			case ADD:
				{
					AddInfo(&con);
					break;
				}
			case DEL:
				{
					DelInfo(&con); 
					break;
					
				}
				case SEARCH:
				{
					SearchContact(&con);
					break;
				}
			case MODIFY:
				{
					EditInfo(&con);
					break;
					
				}
				case SHOW:
				{
					Showcontact(&con);
					break;
				}
			case SORT:
				{
					SortContact(&con);
					break;
				}
			case SAVE:
				{
					SaveInfo(&con);
					break;
				}
			case EXIT:
				{   
					SaveInfo(&con);
					DestroyContact(&con);//销毁通讯录 
					break;
				}
			default:
				{
					printf("输入错误请重新输入\n");
				}
		}
	}
	while(i);
	return 0;
}
