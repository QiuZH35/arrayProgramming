
#define _CRT_SECURE_NO_WARNINGS
#include "dataarray.h"
#include "datastruct.h"



void init(struct Dataarray* p)
{
	p->length = 0;
	p->pdataarray = NULL;

}


void initwithstring(struct Dataarray* p,char *str)
{
	init(p);
	int length = getnum(str);
	p->pdataarray = malloc(sizeof(struct Data) * length);//内存分配
	p->length = length;//标识长度

	int alllength = strlen(str);
	for (char* p = str; p < str + alllength; p++)
	{

		if (*p == ' ')
		{
			*p = '\0';
		}

	}
	int  i = 0;
	for (char* px = str; px < str + alllength; px += strlen(px) + 1)
	{
		char* pnew = malloc(sizeof(char) * (strlen(px) + 1));
		strcpy(pnew, px);
		//printf("%s\n", pnew);

		initdatastring(&p->pdataarray[i], pnew);//根据字符串初始化一个结构体
		//printf("%lld , %s\n", (&p->pdataarray[i])->QQ, (&p->pdataarray[i])->pstr);
		i++;
	}

}

void showall(const struct Dataarray* p)
{
	for (int i = 0; i < p->length; i++)
	{
		showdata(&p->pdataarray[i]);//传递地址显示
	}

}

void deleteall( struct Dataarray* p)
{
	for (int i = 0; i < p->length; i++)
	{
		free(p->pdataarray[i].pstr);
	}
	free(p->pdataarray);
	p->pdataarray = NULL;
	p->length = 0;
}

void findfistbyQQ(struct Dataarray* p, long long QQ)
{
	int flag = 0;
	for (int i = 0; i < p->length; i++)
	{
		if (QQ == p->pdataarray[i].QQ)
		{
			printf("找到了第一个 %lld , %s \n", p->pdataarray[i].QQ,( * (p->pdataarray + i)).pstr);
			flag = 1;
			break;
		}


	}
    if(!flag)
	{
		printf("没有找到\n");
	}



}
void findallbyQQ(struct Dataarray* p, long long QQ)
{
	int flag = 0;
	for (int i = 0; i < p->length; i++)
	{
		if (QQ == p->pdataarray[i].QQ)
		{
			printf("找到了 %lld , %s \n", p->pdataarray[i].QQ, (*(p->pdataarray + i)).pstr);
			flag = 1;
			
		}

	}
	if (!flag)
	{
		printf("没有找到\n");
	}

}

void findfistbypassword(struct Dataarray* p, char* password)
{
	
	for (int i = 0; i < p->length; i++)
	{
		if (strcmp(password, p->pdataarray[i].pstr) == 0)
		{
			
			printf("找到QQ:%lld , %s\n", (*(p->pdataarray + i)).QQ, p->pdataarray[i].pstr);
			break;
		}
		else	
		{
				printf("没有找到\n");
		}

	}
	



}
void findallbypassword(struct Dataarray* p, char* password)
{

	for (int i = 0; i < p->length; i++)
	{
		if (strcmp(password, p->pdataarray[i].pstr) == 0)
		{
			
			printf("找到QQ:%lld , %s\n", (*(p->pdataarray + i)).QQ, p->pdataarray[i].pstr);
			
		}
		else
			{
				printf("没有找到\n");
			}

	}
	


}

void changeQQwithSet(struct Dataarray* p, long long QQ)
{
	if (QQ != 0)
	{
		for (int i = 0; i < p->length; i++)
		{
			if (QQ == p->pdataarray[i].QQ)
			{
				printf("\n%lld你对可以进行该账号进行密码更改\n", p->pdataarray[i].QQ);
				printf("\n0取消\n1修改密码\n");
				while (1) {
					char ch = getch();
					if (ch == '1')
					{
						printf("输入新密码:\n");
						char newpassword[20]={0};
						scanf("%s", newpassword);
						printf("再次输入密码:\n");
						char newpassword1[20]={0};
						scanf("%s", newpassword1);
						if (strcmp(newpassword, newpassword1) == 0)
						{
							strcpy(p->pdataarray[i].pstr, newpassword1);
							printf("修改成功\n");
						}
					}
					if (ch == '0')
					{
						return;
					}
					
				}
			}
		}

	}
	else
	{
		return;
	}




}

int combyQQ(void* p1, void* p2) {

	struct Data* pd1 = p1;
	struct Data* pd2 = p2;

	if (pd1->QQ == pd2->QQ)
	{
		return 0;

	}
	else if (pd1->QQ > pd2->QQ)
	{
		return 1;
	}
	else
	{
		return -1;
	}

}

int combypass(void* p1, void* p2)//配合Qsort使用
{
	struct Data* pd1 = p1;
	struct Data* pd2 = p2;
	return strcmp(pd1->pstr, pd2->pstr);
}

void sortbyQQ(struct Dataarray* p)
{
	qsort(p->pdataarray, p->length, sizeof(struct Data), combyQQ);

}
void sortbypass(struct Dataarray* p)
{
	qsort(p->pdataarray, p->length, sizeof(struct Data), combypass);
}








void changeallbypassword(struct Dataarray* p, char* password, struct Data* pdata)
{
	
	for (int i = 0; i < p->length; i++)
	{
		if (strcmp(password, p->pdataarray[i].pstr) == 0)
		{
			
			printf("找到QQ:%lld , %s\n", (*(p->pdataarray + i)).QQ, p->pdataarray[i].pstr);
			changedata(p->pdataarray + i, pdata);
		}
		else
		 {
				printf("没有找到\n");
		}


	}
	

}


void deletefirstQQ(struct Dataarray * p, long long QQ)
{
	int curr = -1;
	for (int i = 0; i < p->length; i++)
	{
		if (QQ == p->pdataarray[i].QQ)
		{
			curr = i;
			break;
		}

	}
	if (curr == -1)
	{
		printf("\n没有找到无法删除\n");
	}
	else
	{
		free(p->pdataarray[curr].pstr);
		for (int i = curr; i < p->length-1; i++)
		{
			p->pdataarray[i] = p->pdataarray[i + 1];


		}
		p->length -= 1;
		p->pdataarray = realloc(p->pdataarray, sizeof(struct Data) * p->length);

	}



}
void deletefirstpassword(struct Dataarray* p, char* password)
{
	int curr = -1;
	for (int i = 0; i < p->length; i++)
	{
		if (strcmp(password,p->pdataarray[i].pstr)==0)
		{
			curr = i;
			break;
		}
	}
	if (curr == -1)
	{
		printf("\n没有找到无法删除\n");
	}
	else
	{
		free(p->pdataarray[curr].pstr);
		for (int i = curr; i < p->length - 1; i++)
		{
			p->pdataarray[i] = p->pdataarray[i + 1];


		}
		p->length -= 1;
		p->pdataarray = realloc(p->pdataarray, (sizeof(struct Data)*p->length));  //压缩空间

	}



}

void deleteAllQQ(struct Dataarray* p, long long QQ) 
{
	int i = 0;
	int j = 0;  //双指针
	int k = 0;  //要删除的总长度
	while (1)
	{
		p->pdataarray[i] = p->pdataarray[j];  //结构体赋值
		int mylength = p->length;//保存原来的长度

		if (j >= mylength || i >= mylength)  //超出原来的长度停止
		{
			break;
		}
		if (p->pdataarray[i].QQ == QQ)
		{
			free(p->pdataarray[i].pstr);

			j++;
			k++;
		}
		else
		{
			i++;
			j++;
		}
	}
	p->length -= k;
	p->pdataarray = realloc(p->pdataarray, (sizeof(struct Data) * p->length)); //压缩空间

}
void deleteAllpassword(struct Dataarray* p, char* password)
{
	int i = 0;
	int j = 0;  //双指针
	int k = 0;  //要删除的总长度
	while (1)
	{
		p->pdataarray[i] = p->pdataarray[j];  //结构体赋值
		int mylength = p->length;//保存原来的长度

		if (j >= mylength || i >= mylength)  //超出原来的长度停止
		{
			break;
		}

		char* pres = strstr(p->pdataarray[i].pstr, password); //根据密码寻找
		if (pres !=NULL)
		{
			free(p->pdataarray[i].pstr);

			j++;
			k++;
		}
		else
		{
			i++;
			j++;
		}
	}
	p->length -= k;
	p->pdataarray = realloc(p->pdataarray, (sizeof(struct Data) * p->length)); //压缩空间
}

void insertfirrtQQ(struct Dataarray* p, long long QQ,struct Data *pdata) 
{

	int curr=-1;
	for (int i = 0; i < p->length; i++)
	{
		if (QQ == p->pdataarray[i].QQ)
		{
			printf("找到了 %lld , %s \n", p->pdataarray[i].QQ, (*(p->pdataarray + i)).pstr);
			curr = i;
			break;

		}

	}
	if (curr==-1)
	{
		printf("没有找到\n");
	}
	else
	{
		p->pdataarray = realloc(p->pdataarray, sizeof(struct Data) * (p->length + 1));//开拓内存
		for (int i = p->length - 1; i >= curr; i--)
		{
			p->pdataarray[i + 1] = p->pdataarray[i];
		}
		p->pdataarray[curr] = *pdata;
		
		p->length += 1;
	}




}

void insertback(struct Dataarray* p, struct Data* password)//尾部插入
{
	p->length += 1;
	p->pdataarray= realloc(p->pdataarray, (sizeof(struct Data) * p->length));
	p->pdataarray[p->length - 1] = *password;
}

