
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct  Men
{
	void* p;  //��¼�ڴ��ַ

	int memlength;//��¼�ڴ泤��
};  //�ṹ���ʼ��


struct  Mystruct
{
	struct  Men* p; //��¼�����ڴ�ṹ�������
	int length; //��¼����
};







struct Mystruct* Memmalloc=NULL;
 



int j = 0;  //��ǿ��ٶ���Ƭ�ڴ棬�Ƚϴ������
void* __cdecl mymalloc(
	size_t _Size
)
{
	void* p = malloc(_Size);
	
	j++;
	return p;
}

void __cdecl myfree(
	void* _Block
)
{
	
	free(_Block);
	j--;

	



	
}





void main()
{
	 
	
	void* p1 = mymalloc(14);

	void* p2 = mymalloc(14);

	void* p3 = mymalloc(14);
	void* p4 = mymalloc(14);

	myfree(p1);
	myfree(p2);
	myfree(p3);
	


	printf("û���ͷ�%dƬ�ڴ�", j);
	system("pause");
}