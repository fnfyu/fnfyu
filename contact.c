#include"contact.h" 
void Init(struct Contact *p)
{
	p->Data=(struct PeoInfo*)malloc(DEFAULTSZ*sizeof(struct PeoInfo));
	if(p->Data ==NULL)	return;
	p->size=0;
	p->capacity=DEFAULTSZ;
	LoadContact(p);//�����ļ� 
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
			printf("����ʧ��");
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
static int FindByName(const struct Contact*p)//���Һ��� �ҵ��˷�����������λ�õ��±� ���򷵻�-1 static���� �ú���ֻ�����Դ�ļ�����Ч 
{
	char name[MAX_NAME];
	printf("����������\n");
	scanf("%s",name);
	//1.����
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
//		printf("ͨѶ¼����,�޷�����\n");
//	}
	CheckCapacity(p);//��⵱ǰͨѶ¼������ ���˾����� ������ʲô�Ƕ����� 
		printf("����������\n");
		scanf("%s",p->Data[p->size ].name);
		printf("����������\n");
		scanf("%hd",&(p->Data[p->size ].age));//���鲻��ȡ��ַ ����������Ҫȡ��ַ 
		printf("�������Ա�\n");
		scanf("%s",p->Data[p->size ].sex );
		printf("������绰\n");
		scanf("%s",p->Data[p->size ].tele);
		printf("�������ַ\n");
		scanf("%s",p->Data[p->size ].addr);
		(p->size) ++;
		printf("��ӳɹ�\n");
}
void DelInfo(struct Contact*p)
{
	int ret=FindByName(p);
	if(ret==-1)
	printf("�Ҳ�����ɾ����\n");
	else 
	{
      int j;
			for(j=ret;j<p->size-1;j++)
			{
				p->Data[j]=p->Data[j+1];
			}
			p->size--;
    	printf("ɾ���ɹ�\n"); 
	}
}
void SearchContact(const struct Contact*p)
{
	int ret=FindByName(p);
	if(ret==-1) 
	printf("Ҫ���ҵ��˲�����");
	else
	printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","����","����","�Ա�","�绰","��ַ");
	printf("%-20s\t%-4hd\t%-5s\t%-12s\t%-20s\n",p->Data[ret].name,p->Data[ret].age,p->Data[ret].sex,p->Data[ret].tele,p->Data[ret].addr);
}
void EditInfo(struct Contact * p)
{
	int ret=FindByName(p);
	if(ret==-1) printf("�Ҳ������޸���");
	else
	{
		printf("����������\n");
		scanf("%s",p->Data[ret].name);
		printf("����������\n");
		scanf("%hd",&(p->Data[ret].age)); 
		printf("�������Ա�\n");
		scanf("%s",p->Data[ret].sex );
		printf("������绰\n");
		scanf("%s",p->Data[ret].tele);
		printf("�������ַ\n");
		scanf("%s",p->Data[ret].addr);
		printf("�޸ĳɹ�\n");
	} 
}
void Showcontact(const struct Contact*p)
{
	if(p->size ==0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","����","����","�Ա�","�绰","��ַ");
		for(i=0;i<p->size;i++)
		{
			printf("%-20s\t%-4hd\t%-5s\t%-12s\t%-20s\n",p->Data[i].name,p->Data[i].age,p->Data[i].sex,p->Data[i].tele,p->Data[i].addr);
		}
	}
}
void SortContact(struct Contact * p)
{
	printf("��ѡ������ʽ\n");
	printf("1.������\n");
	printf("2.������\n");
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
	printf("�������");
}
void SaveInfo(struct Contact *p)
{
	FILE*pf=fopen("Contact.data","wb");
	if(pf==NULL)
	{
		printf("SaveInfo::%s\n",strerror(errno));
		return ;
	}
	int i=0;//дͨѶ¼�����ݵ��ļ��� 
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
