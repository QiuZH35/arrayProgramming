
#define _CRT_SECURE_NO_WARNINGS
#include "array.h"

void initwithnull(struct dataarray* pdataarray, char datatype[10], int elemsize)
{
	pdataarray->p = NULL;
	pdataarray->length = 0;
	pdataarray->elemsize = elemsize;//��С
	strcpy(pdataarray->datatype, datatype);//ȷ������


}

void intwitharray(struct dataarray* pdataarray, char datatype[10], int elemsize, void* parray,int n)
{
	pdataarray->p = NULL;
	pdataarray->length = 0;
	pdataarray->elemsize = elemsize;//��С
	strcpy(pdataarray->datatype, datatype);//ȷ������
	
	if (strcmp(pdataarray->datatype, "stringa")==0)
	{
		stringa* pa = parray;//ָ������ת��
		pdataarray->elemsize = sizeof(stringa);//Ԫ�ش�С
		pdataarray->p = malloc(sizeof(stringa) * n);;//�����ڴ�
		memcpy(pdataarray->p, parray, sizeof(stringa) * n);//
		pdataarray->length = n; //��¼����

		
	}




}
void backarrayone(struct dataarray* pdataarray, void* parray)
{
	if (strcmp(pdataarray->datatype, "stringa") == 0)
	{
		
		pdataarray->p = realloc(pdataarray->p, sizeof(stringa) * (pdataarray->length + 1));//��չ���ݳ���
		stringa* pa = pdataarray->p; //�����׵�ַ
		stringa* pd = parray;

		pa[pdataarray->length].p=pd->p;//ǳ����
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
			
			printf("%s  ", pa[i].p);//��ӡ�ַ���


		}
		printf("\n");

	}




}