
#define _CRT_SECURE_NO_WARNINGS
#include "string.h"

void init(void* p, char ch)//ch=W ,ch=a �Զ����խ����
{
	if (ch == 'w')
	{
		stringw* pw = p;//ָ������ת����ȷ������
		pw->p = NULL;
		pw->memlength = 0;
	}
	else if (ch == 'a')
	{
		stringa* pa = p;//ָ������ת����ȷ������
		pa->p = NULL;
		pa->memlength = 0;
	}
	else
	{
		abort();
	}


}
void initwithstring(void* p, char ch,const void* pstr)//��ʼ��
{
	if (ch == 'w')
	{
		stringw* pw = p;//ָ������ת����ȷ������
		pw->p = NULL;
		pw->memlength = 0;

		wchar_t* pstrback = pstr;//ת��ָ������
		pw->p = malloc(wcslen(pstrback));//������ַ�ָ�볤��
		pw->memlength = wcslen(pstrback) + 2;//�ڴ泤��
		wcscpy(pw->p, pstrback);
	}
	else if (ch == 'a')
	{
		stringa* pa = p;//ָ������ת����ȷ������
		pa->p = NULL;
		pa->memlength = 0;
		char* pstrback = pstr;//ת��ָ������
		pa->p = malloc(strlen (pstrback));//������ַ�ָ�볤��
		pa->memlength = strlen(pstrback) + 1;//�ڴ泤��
		strcpy(pa->p, pstrback);

	}
	else
	{
		abort();
	}


}
void showstring(const void* p,char ch)
{
	if (ch == 'w')
	{
		stringw* pw = p;
		if (pw->p != NULL)
		{
			wprintf(L"%ls\n", pw->p);
		}


	}
	else if (ch == 'a')
	{
		stringa* pa = p;
		if (pa->p != NULL)
		{
			printf("%s\n", pa->p);
		}

	}
	else
	{
		abort();
	}


}