
#define _CRT_SECURE_NO_WARNINGS
#include "string.h"

void init(void* p, char ch)//ch=W ,ch=a 自定义宽窄规则
{
	if (ch == 'w')
	{
		stringw* pw = p;//指针类型转换，确定类型
		pw->p = NULL;
		pw->memlength = 0;
	}
	else if (ch == 'a')
	{
		stringa* pa = p;//指针类型转换，确定类型
		pa->p = NULL;
		pa->memlength = 0;
	}
	else
	{
		abort();
	}


}
void initwithstring(void* p, char ch,const void* pstr)//初始化
{
	if (ch == 'w')
	{
		stringw* pw = p;//指针类型转换，确定类型
		pw->p = NULL;
		pw->memlength = 0;

		wchar_t* pstrback = pstr;//转换指针类型
		pw->p = malloc(wcslen(pstrback));//分配宽字符指针长度
		pw->memlength = wcslen(pstrback) + 2;//内存长度
		wcscpy(pw->p, pstrback);
	}
	else if (ch == 'a')
	{
		stringa* pa = p;//指针类型转换，确定类型
		pa->p = NULL;
		pa->memlength = 0;
		char* pstrback = pstr;//转换指针类型
		pa->p = malloc(strlen (pstrback));//分配宽字符指针长度
		pa->memlength = strlen(pstrback) + 1;//内存长度
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