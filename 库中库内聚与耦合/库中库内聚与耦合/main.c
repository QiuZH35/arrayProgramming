
#define _CRT_SECURE_NO_WARNINGS
#include "string.h"
#include "array.h"

//���ھۣ��ڲ���������ܵĶ���������һ��
// 
// 
//����ϣ�ÿ������֮���������Ӱ��ȫ�֡�  



//void main()
//{
//	setlocale(LC_ALL, "zh-CN");
//	stringa stringa1;
//	stringw stringw1;
//
//	initwithstring(&stringa1, 'a', "calc");
//	initwithstring(&stringw1, 'w', L"�ƻ�");
//	showstring (&stringa1, 'a');
//	showstring(&stringw1, 'w');
//
//
//
//
//
//	system("pause");
//}



void main()
{
	stringa stringa1[6];
	char *str[6] = { "calc","notepad","mspaint","pause","123456","main.cpl"};
	for (int i = 0; i < 6; i++)
	{

		initwithstring(&stringa1[i], 'a', str[i]);

	}
	{
		struct dataarray data;
		intwitharray(&data, "stringa", sizeof(stringa), stringa1, 4);
		showarray(&data, "stringa");
		backarrayone(&data, &stringa1[5]);
		backarrayone(&data, &stringa1[4]);
		showarray(&data, "stringa");

	}

	system("pause");
}