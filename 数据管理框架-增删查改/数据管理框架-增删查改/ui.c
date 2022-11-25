
#define _CRT_SECURE_NO_WARNINGS
#include "ui.h"




struct Dataarray* pdata = NULL;

char uistr[2048] = "\n0帮助\n\
1显示所有数据\
\n2删除所有数据\
\n3根据QQ查询密码\
\n4修改QQ数据\
\n5排序\
\n6清屏\
\n7删除\
\n8退出\
\n9尾部增加\
\n10插入\n";


void help(char *uistr)
{
	printf("%s\n",uistr);

}


void uimain() 
{
	pdata = malloc(sizeof(struct Dataarray));

	initwithstring(pdata, str);
aaa:
	help(uistr);
	while (1)
	{
		printf("\n请输入:\n");
		char ch=getch();
		switch (ch)
		{
		case '0':
			help(uistr);
			break;
		case '1':
			showall(pdata);
			printf("\n已显示所有\n");
			break;
		case '2':
			deleteall(pdata);//释放内存
				break;
		case '3':
		{
			printf("\n请输入你的选择方式\n0退出\n1根据QQ查询第一个\n2根据密码查询第一个\n3根据QQ查询所有\n4根据密码查询所有\n");
			while (1){
			char newchx = getch();
			switch (newchx)
			{
			case '0':
				goto aaa;
				break;
			case '1':
				printf("输入QQ:\n");
				long long l1;
				scanf("%lld", &l1);

				findfistbyQQ(pdata, l1);

				break;
			case '2':
				printf("输入密码:\n");
				char password[20];
				scanf("%s", password);
				findfistbypassword(pdata, password);

				break;
			case '3':
				printf("输入QQ:\n");
				long long l2;
				scanf("%lld", &l2);
				findallbyQQ(pdata, l2);


				break;
			case '4':
				printf("输入密码:\n");
				char password1[20];
				scanf("%s", password1);
				findallbypassword(pdata, password1);
				break;
			}

			}

		}
			break;
		case '4':
		{
		printf("输入QQ:\n");
		long long QQ;
		scanf("%lld", &QQ);
		changeQQwithSet(pdata, QQ);
		
		}
			break;
		case '5':
		{
			printf("请选择排序方式：\n1根据QQ排\n2根据密码排\n");
			char chx = getch();
			switch (chx)
			{
			case '1':
				sortbyQQ(pdata);
				
				printf("\n已排序\n");
				break;
			case '2':
				 sortbypass( pdata);
				printf("\n已排序\n");
				break;
			}
		}
			break;
		case '6':
			system("cls");
			break;
		case '7':
		{
			printf("\n删除\n");
			printf("\n请输入你的选择方式\n0退出\n1根据QQ删除第一个\n2根据密码删除第一个\n3根据QQ删除所有\n4根据密码删除所有\n");
			while (1) {
				char newch = getch();
				switch (newch)
				{
				case '0':
					goto aaa;
					break;
				case '1':
					printf("输入QQ:\n");
					long long l1;
					scanf("%lld", &l1);
					deletefirstQQ(pdata, l1);


					break;
				case '2':
					printf("输入密码:\n");
					char password[20]={0};
					scanf("%s", password);
					deletefirstpassword(pdata, password);


					break;
					case '3':
						printf("输入QQ:\n");
						long long l2;
						scanf("%lld", &l2);
						deleteAllQQ( pdata,l2);


						break;
					case '4':
						printf("输入密码:\n");
						char password1[20]={0};
						scanf("%s", password1);
						deleteAllpassword(pdata,  password);

						break;
				}
			}



			break;
		}
		case '8':
			exit(0);
			break;
		case '9':	
		{printf("输入QQ:\n");
		long long QQ;
		scanf("%d", &QQ);
		printf("输入密码:\n");
		char password1[20] = { 0 };
		scanf("%s", password1);
		struct Data data1;
		changeinitdatastring(&data1, QQ, password1);
		insertback(pdata, &data1);
		break;
		}
		case '10':
			printf("输入插入QQ的位置\n");
			long long QQ;
			scanf("%d", &QQ);
			printf("输入QQ:\n");
			long long newQQ;
			scanf("%d", &newQQ);
			printf("输入密码:\n");
			char password1[20] = { 0 };
			scanf("%s", password1);
			struct Data data1;
			changeinitdatastring(&data1, newQQ, password1);
		
			insertfirrtQQ(pdata, QQ, &data1);



			break;


		}




	}



}