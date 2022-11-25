
#include "datastruct.h"


struct Dataarray
{
	struct Data* pdataarray;
	int length;//数组长度
};


void init(struct Dataarray* p);  //初始化
void initwithstring(struct Dataarray* p,char *str);
void showall(const struct Dataarray* p);
void deleteall(struct Dataarray* p);
void findfistbyQQ(struct Dataarray* p,long long QQ);
void findallbyQQ (struct Dataarray* p,long long QQ);

void findfistbypassword(struct Dataarray* p, char * password);
void findallbypassword(struct Dataarray* p, char *pwssword);

void changeQQwithSet(struct Dataarray* p, long long QQ);

int combyQQ(void* p1, void* p2);
int combypass(void* p1, void* p2); //配合Qsort使用

void sortbyQQ(struct Dataarray*p);
void sortbypass(struct Dataarray* p);


void changeallbypassword(struct Dataarray* p, char* password, struct Data* pdata);



void deletefirstQQ(struct Dataarray* p, long long QQ);
void deletefirstpassword(struct Dataarray* p, char *password);

void deleteAllQQ(struct Dataarray* p, long long QQ);
void deleteAllpassword(struct Dataarray* p, char* password);

void insertfirrtQQ(struct Dataarray* p, long long QQ, struct Data* pdata);

void insertback(struct Dataarray* p,struct Data * password);