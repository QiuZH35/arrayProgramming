#pragma once
#include "string.h"

struct dataarray
{
	void* p;//�����κ����͵ĵ�ַ
	int length;
	char datatype[10];
	int elemsize;//4
};

void initwithnull(struct dataarray* pdataarray, char datatype[10], int elemsize);

void intwitharray(struct dataarray* pdataarray, char datatype[10], int elemsize, void* parray,int n);
void backarrayone(struct dataarray* pdataarray, void* parray);


void showarray(struct dataarray* pdataarray, char datatype[10]);