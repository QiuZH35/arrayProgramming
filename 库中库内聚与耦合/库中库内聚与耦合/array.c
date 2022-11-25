
#define _CRT_SECURE_NO_WARNINGS
#include "array.h"

void initwithnull(struct dataarray* pdataarray, char datatype[10], int elemsize)
{
	pdataarray->p = NULL;
	pdataarray->length = 0;
	pdataarray->elemsize = elemsize;//大小
	strcpy(pdataarray->datatype, datatype);//确定类型


}

void intwitharray(struct dataarray* pdataarray, char datatype[10], int elemsize, void* parray,int n)
{
	pdataarray->p = NULL;
	pdataarray->length = 0;
	pdataarray->elemsize = elemsize;//大小
	strcpy(pdataarray->datatype, datatype);//确定类型
	
	if (strcmp(pdataarray->datatype, "stringa")==0)
	{
		stringa* pa = parray;//指针类型转换
		pdataarray->elemsize = sizeof(stringa);//元素大小
		pdataarray->p = malloc(sizeof(stringa) * n);;//分配内存
		memcpy(pdataarray->p, parray, sizeof(stringa) * n);//
		pdataarray->length = n; //记录长度

		
	}




}
void backarrayone(struct dataarray* pdataarray, void* parray)
{
	if (strcmp(pdataarray->datatype, "stringa") == 0)
	{
		
		pdataarray->p = realloc(pdataarray->p, sizeof(stringa) * (pdataarray->length + 1));//拓展数据长度
		stringa* pa = pdataarray->p; //接收首地址
		stringa* pd = parray;

		pa[pdataarray->length].p=pd->p;//浅拷贝
		pa[pdataarray->length].memlength = pd->memlength;


		pdataarray->length += 1;
	}
	

}


void showarray(struct dataarray* pdataarray, char datatype[10])
{
	if (strcmp(pdataarray->datatype, "stringa") == 0)
	{
		stringa* pa = pdataarray->p;
		for (int i = 0; i < pdataarray->length; i++)
		{
			
			printf("%s  ", pa[i].p);//打印字符串


		}
		printf("\n");

	}




}