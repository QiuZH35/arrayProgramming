
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


int Mystrlen(const char* src)
{
	int num = 0;
	while (*(src++) != '\0')
	{

		num++;

	}
	return num;
}
char* Mystrstr(char* p, char ch)
{
	if (p != nullptr)
	{
		char* port = NULL;
		int length = Mystrlen(p);
		for (int i = 0; i < length; i++)
		{
			if (*(p + i) == ch)
			{
				port = p + i;
				return port;

			}
		}

	}
	else
	{
		return nullptr;
	}
}

char* Mystrcpy(char* dest, const char* src)
{
	if (dest != nullptr && src != nullptr)
	{
		char* p = dest;
		while ((*(p++) = *(src++)) != '\0');
		return p;
	}
	else
	{
		return nullptr;
	}
	
}
char* Mynstrcpy(char* dest, char *source,char ch)
{
	if (dest != nullptr && source !=nullptr)
	{
		char* p = dest;
		while ( *source != '\0')
		{
			if ((*(p++) = *(source++)) != ch && *(source) !=ch)
			{
			}
			else
			{
				return p;
			}
		}

	}
	else
	{
		return nullptr;
	}

}
int Myatoi(char* source)
{
	if (source != nullptr)
	{
		//55 0*10+5  5    5*10+5 55
		
		if (*source <= '0' && *source >= '9')
		{
			source+1;
		}
		int num = 0;
		while (*source != '\0')
		{
			if (*source >= '0' && *source <= '9')
			{
				int staticnum = *(source)-'0';
				num = num * 10 + staticnum;

			}
			
			source++;
		}

		return num;

	}
	else
	{
		return 0;
	}


}


void getnum(string str, int &num1, int &num2)
{
	
	//S10T999
	char newstr[20];
	Mystrcpy(newstr, str.c_str());
	char* newp = newstr;

	if (*newp == 'S') {
		char lefts[10] = { 0 };
		char rights[10] = { 0 };

		char* left = lefts;
		char* right = rights;


		if (newp != nullptr)
		{
			right = Mystrstr(newp, 'T');
			Mynstrcpy(left, newp, 'T');
			num1 = Myatoi(left + 1);
			num2 = Myatoi(right + 1);

		}
		else
		{
			return;
		}
	}
	else
	{
		return;
	}
	
}



int main()
{
	string str = "S010T999";
	int a=1, b=2;
	getnum(str,a,b);

	cout <<"main=" << a <<" " << b << endl;



	cin.get();
}