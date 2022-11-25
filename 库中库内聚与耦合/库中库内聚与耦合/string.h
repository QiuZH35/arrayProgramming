#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //本地化
#include <string.h>
#include <memory.h>
 


struct stringA
{
	char* p;
	int memlength;//内存长度

};

struct stringW
{
	wchar_t* p;
	int memlength;//内存长度
};

//内聚，类型功能相近的放在一起
typedef struct stringA stringa;
typedef struct stringW stringw;//缩写



void init(void* p, char ch);//ch=W ,ch=a 自定义宽窄规则
void initwithstring(void* p, char ch,const void* pstr);//初始化
void showstring(const void* p,char ch);//显示


