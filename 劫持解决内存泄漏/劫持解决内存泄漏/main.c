
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct  Men
{
	void* p;  //记录内存地址

	int memlength;//记录内存长度
};  //结构体初始化


struct  Mystruct
{
	struct  Men* p; //记录开辟内存结构体的数组
	int length; //记录个数
};







struct Mystruct* Memmalloc=NULL;
 



int j = 0;  //标记开辟多少片内存，比较挫的做法
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
	


	printf("没有释放%d片内存", j);
	system("pause");
}