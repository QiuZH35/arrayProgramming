
#define _CRT_SECURE_NO_WARNINGS
#include "ui.h"




struct Dataarray* pdata = NULL;

char uistr[2048] = "\n0����\n\
1��ʾ��������\
\n2ɾ����������\
\n3����QQ��ѯ����\
\n4�޸�QQ����\
\n5����\
\n6����\
\n7ɾ��\
\n8�˳�\
\n9β������\
\n10����\n";


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
		printf("\n������:\n");
		char ch=getch();
		switch (ch)
		{
		case '0':
			help(uistr);
			break;
		case '1':
			showall(pdata);
			printf("\n����ʾ����\n");
			break;
		case '2':
			deleteall(pdata);//�ͷ��ڴ�
				break;
		case '3':
		{
			printf("\n���������ѡ��ʽ\n0�˳�\n1����QQ��ѯ��һ��\n2���������ѯ��һ��\n3����QQ��ѯ����\n4���������ѯ����\n");
			while (1){
			char newchx = getch();
			switch (newchx)
			{
			case '0':
				goto aaa;
				break;
			case '1':
				printf("����QQ:\n");
				long long l1;
				scanf("%lld", &l1);

				findfistbyQQ(pdata, l1);

				break;
			case '2':
				printf("��������:\n");
				char password[20];
				scanf("%s", password);
				findfistbypassword(pdata, password);

				break;
			case '3':
				printf("����QQ:\n");
				long long l2;
				scanf("%lld", &l2);
				findallbyQQ(pdata, l2);


				break;
			case '4':
				printf("��������:\n");
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
		printf("����QQ:\n");
		long long QQ;
		scanf("%lld", &QQ);
		changeQQwithSet(pdata, QQ);
		
		}
			break;
		case '5':
		{
			printf("��ѡ������ʽ��\n1����QQ��\n2����������\n");
			char chx = getch();
			switch (chx)
			{
			case '1':
				sortbyQQ(pdata);
				
				printf("\n������\n");
				break;
			case '2':
				 sortbypass( pdata);
				printf("\n������\n");
				break;
			}
		}
			break;
		case '6':
			system("cls");
			break;
		case '7':
		{
			printf("\nɾ��\n");
			printf("\n���������ѡ��ʽ\n0�˳�\n1����QQɾ����һ��\n2��������ɾ����һ��\n3����QQɾ������\n4��������ɾ������\n");
			while (1) {
				char newch = getch();
				switch (newch)
				{
				case '0':
					goto aaa;
					break;
				case '1':
					printf("����QQ:\n");
					long long l1;
					scanf("%lld", &l1);
					deletefirstQQ(pdata, l1);


					break;
				case '2':
					printf("��������:\n");
					char password[20]={0};
					scanf("%s", password);
					deletefirstpassword(pdata, password);


					break;
					case '3':
						printf("����QQ:\n");
						long long l2;
						scanf("%lld", &l2);
						deleteAllQQ( pdata,l2);


						break;
					case '4':
						printf("��������:\n");
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
		{printf("����QQ:\n");
		long long QQ;
		scanf("%d", &QQ);
		printf("��������:\n");
		char password1[20] = { 0 };
		scanf("%s", password1);
		struct Data data1;
		changeinitdatastring(&data1, QQ, password1);
		insertback(pdata, &data1);
		break;
		}
		case '10':
			printf("�������QQ��λ��\n");
			long long QQ;
			scanf("%d", &QQ);
			printf("����QQ:\n");
			long long newQQ;
			scanf("%d", &newQQ);
			printf("��������:\n");
			char password1[20] = { 0 };
			scanf("%s", password1);
			struct Data data1;
			changeinitdatastring(&data1, newQQ, password1);
		
			insertfirrtQQ(pdata, QQ, &data1);



			break;


		}




	}



}