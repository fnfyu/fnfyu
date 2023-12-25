#include"contact.h" 
void Init(struct Contact *p)
{
	p->Data=(struct PeoInfo*)malloc(DEFAULTSZ*sizeof(struct PeoInfo));
	if(p->Data ==NULL)	return;
	p->size=0;
	p->capacity=DEFAULTSZ;
	LoadContact(p);//加载文件 
}
void CheckCapacity(struct Contact *p)
{
	struct PeoInfo* ps=NULL;
	if(p->size==p->capacity)
	{
		ps=realloc(p->Data,(p->capacity+2)*sizeof(struct PeoInfo));
		if (ps != NULL) {
			p->Data = ps;
			p->capacity += 2;
		}
		else if (ps == NULL)
			printf("增容失败");
	}
	
}
void LoadContact(struct Contact*p)
{
//	struct PeoInfo tmp;
	FILE*pf=fopen("Contact.data","rb");
	if(pf==NULL)
	{
		printf("Load::%s\n",strerror(errno));
		return;
	}
	while(fread(&(p->Data[p->size]),sizeof(struct PeoInfo),1,pf))
	{
		CheckCapacity(p);
//		p->Data[p->size]=tmp;
		(p->size)++;
	}
	fclose(pf);
	pf=NULL;
}
static int FindByName(const struct Contact*p)//查找函数 找到了返回名字所在位置的下标 否则返回-1 static修饰 让函数只在这个源文件中生效 
{
	char name[MAX_NAME];
	printf("请输入姓名\n");
	scanf("%s",name);
	//1.查找
	int i;
	for(i=0;i<p->size;i++)
	{
		if(strcmp(p->Data[i].name,name)==0)
		{
			break;
		}
	}
	if(i==p->size)
	return -1;
	else 
	return i; 
}

void AddInfo(struct Contact *p)
{
//	if(p->size==MAX){
//		printf("通讯录已满,无法增加\n");
//	}
	CheckCapacity(p);//检测当前通讯录的容量 满了就增容 不满就什么是都不做 
		printf("请输入名字\n");
		scanf("%s",p->Data[p->size ].name);
		printf("请输入年龄\n");
		scanf("%hd",&(p->Data[p->size ].age));//数组不用取地址 而其他的需要取地址 
		printf("请输入性别\n");
		scanf("%s",p->Data[p->size ].sex );
		printf("请输入电话\n");
		scanf("%s",p->Data[p->size ].tele);
		printf("请输入地址\n");
		scanf("%s",p->Data[p->size ].addr);
		(p->size) ++;
		printf("添加成功\n");
}
void DelInfo(struct Contact*p)
{
	int ret=FindByName(p);
	if(ret==-1)
	printf("找不到被删除人\n");
	else 
	{
      int j;
			for(j=ret;j<p->size-1;j++)
			{
				p->Data[j]=p->Data[j+1];
			}
			p->size--;
    	printf("删除成功\n"); 
	}
}
void SearchContact(const struct Contact*p)
{
	int ret=FindByName(p);
	if(ret==-1) 
	printf("要查找的人不存在");
	else
	printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","姓名","年龄","性别","电话","地址");
	printf("%-20s\t%-4hd\t%-5s\t%-12s\t%-20s\n",p->Data[ret].name,p->Data[ret].age,p->Data[ret].sex,p->Data[ret].tele,p->Data[ret].addr);
}
void EditInfo(struct Contact * p)
{
	int ret=FindByName(p);
	if(ret==-1) printf("找不到被修改人");
	else
	{
		printf("请输入名字\n");
		scanf("%s",p->Data[ret].name);
		printf("请输入年龄\n");
		scanf("%hd",&(p->Data[ret].age)); 
		printf("请输入性别\n");
		scanf("%s",p->Data[ret].sex );
		printf("请输入电话\n");
		scanf("%s",p->Data[ret].tele);
		printf("请输入地址\n");
		scanf("%s",p->Data[ret].addr);
		printf("修改成功\n");
	} 
}
void Showcontact(const struct Contact*p)
{
	if(p->size ==0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","姓名","年龄","性别","电话","地址");
		for(i=0;i<p->size;i++)
		{
			printf("%-20s\t%-4hd\t%-5s\t%-12s\t%-20s\n",p->Data[i].name,p->Data[i].age,p->Data[i].sex,p->Data[i].tele,p->Data[i].addr);
		}
	}
}
void SortContact(struct Contact * p)
{
	printf("请选择排序方式\n");
	printf("1.按名字\n");
	printf("2.按年龄\n");
	int q;
	scanf("%d",&q);
	if(q==1)
	{
	int i,j;
	struct PeoInfo tmp;
	for(i=0;i<p->size-1;i++)
	{
		for(j=0;j<p->size-1-i;j++)
		{
			if(strcmp(p->Data[j].name,p->Data[j+1].name)>0)
			{
			tmp=p->Data[j];
			p->Data[j]=p->Data[j+1];
			p->Data[j+1]=tmp;
			}		
		}
	}	
	}
	else
	{
	int i,j;
	struct PeoInfo tmp;
	for(i=0;i<p->size-1;i++)
	{
		for(j=0;j<p->size-1-i;j++)
		{
			if(p->Data[j].age>p->Data[j+1].age)
			{
			tmp=p->Data[j];
			p->Data[j]=p->Data[j+1];
			p->Data[j+1]=tmp;	
			}
		}
	}		
	}
	printf("排序完成");
}
void SaveInfo(struct Contact *p)
{
	FILE*pf=fopen("Contact.data","wb");
	if(pf==NULL)
	{
		printf("SaveInfo::%s\n",strerror(errno));
		return ;
	}
	int i=0;//写通讯录的数据到文件中 
	for(i=0;i<p->size ;i++)
	{
		fwrite(&(p->Data[i]),sizeof(struct PeoInfo),1,pf);
	}
	fclose(pf);
	pf=NULL;
}
void DestroyContact(struct Contact*p)
{
	free(p->Data);
	p->Data=NULL;
}
