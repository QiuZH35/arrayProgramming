#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //���ػ�
#include <string.h>
#include <memory.h>
 


struct stringA
{
	char* p;
	int memlength;//�ڴ泤��

};

struct stringW
{
	wchar_t* p;
	int memlength;//�ڴ泤��
};

//�ھۣ����͹�������ķ���һ��
typedef struct stringA stringa;
typedef struct stringW stringw;//��д



void init(void* p, char ch);//ch=W ,ch=a �Զ����խ����
void initwithstring(void* p, char ch,const void* pstr);//��ʼ��
void showstring(const void* p,char ch);//��ʾ


