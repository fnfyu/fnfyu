#include"contact.h"
void menu()
{
	printf("*******ͨѶ¼*******\n");
	printf("*******1.����*******\n");
	printf("*******2.ɾ��*******\n");
	printf("*******3.��ѯ*******\n");
	printf("*******4.�޸�*******\n");
	printf("*******5.չʾ*******\n");
	printf("*******6.����*******\n");
	printf("*******7.�洢*******\n");
	printf("*******0.�˳�*******\n");
	printf("********************\n");
}


int main()
{
	struct Contact con;	//����ͨѶ¼ 
	int i/*,size=0*/;//size��ʾͨѶ¼��Ŀǰ�м���Ԫ�� 
	Init(&con);//��ʼ�� 
	do
	{
		menu();
		printf("�����룺>\n");
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
					DestroyContact(&con);//����ͨѶ¼ 
					break;
				}
			default:
				{
					printf("�����������������\n");
				}
		}
	}
	while(i);
	return 0;
}
