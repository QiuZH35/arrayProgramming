
#define _CRT_SECURE_NO_WARNINGS
#include "datastruct.h"




void newinitdatastring(struct Data* p, char* initstr)
{
	p->pstr = malloc(sizeof(char) * strlen(initstr) + 1);
	p->QQ = 65431321;
	strcpy(p->pstr, initstr);
}

void changeinitdatastring(struct Data* p,long long QQ, char* initstr)
{
	p->pstr = malloc(sizeof(char) * strlen(initstr) + 1);
	p->QQ = QQ;
	strcpy(p->pstr, initstr);
}

void initdatastring( struct Data* p,char*initstr)
{
	char* px = strstr(initstr, "----");
	*px = '\0';
	//521276402\0----hanlei@19940403 
	sscanf(initstr, "%lld", &p->QQ);
	p->length = strlen(px + 4);
	p->pstr = malloc(sizeof(char) * (p->length + 1));
	strcpy(p->pstr, px + 4);
	//printf("%lld---%s\n",p->QQ, p->pstr);

}


void showdata(const struct Data *p)
{
	if (p != NULL )
	{
		printf("%lld----%s \n", (*p).QQ, p->pstr);
	}
	else
	{
		
		abort();
	}


}

void changedata(struct Data* pold, struct Data* pnew)//Ç³¿½±´
{
	if (pold->pstr != NULL)
	{
		free(pold->pstr);
	}
	(*pold) = (*pnew);
}
void changedatadeep(struct Data* pold, struct Data* pnew)//Éî¿½±´
{
	if (pold->pstr != NULL)
	{
		free(pold->pstr);
	}
	(*pold) = (*pnew);
	pold->pstr = malloc(strlen(pnew->pstr) + 1);
	strcpy(pold->pstr, pnew->pstr);//¿½±´

}