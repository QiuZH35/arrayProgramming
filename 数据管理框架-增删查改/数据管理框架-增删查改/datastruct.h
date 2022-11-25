
#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>





struct Data
{
	long long QQ;
	char* pstr;
	unsigned char length;
};




void showdata(const struct Data* p);//显示单个数据
void initdatastring(struct Data* p, char* initstr);
void changeinitdatastring(struct Data* p, long long QQ, char* initstr);

void newinitdatastring(struct Data* p, char* initstr);

void changedata( struct Data* pold, struct Data* pnew);//浅拷贝
void changedatadeep( struct Data* pold, struct Data* pnew);//深拷贝