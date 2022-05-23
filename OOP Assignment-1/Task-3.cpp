#include<iostream>
#include<cstring>
using namespace std;
int stlen(const char* s)
{
	int len = 0;
	for (; s[len] != '\0';)
	{
		len++;
	}
	return len;
}
int strcomp(const char* s1, const char* s2)
{
	int flag = 0;
		int len1 = 0, len2 = 0,temp=0;
		for (; s1[len1] != '\0';)
		{
			len1++;
		}
		for (; s1[len2] != '\0';)
		{
			len2++;
		}
		if (len1 > len2)
			temp = len1;
		else
			temp = len2;

	for (int i = 0; i < len1+1; i++)
	{
		if (s1[i] < s2[i])
		{
			flag = -1;
			break;
		}
		else if (s1[i] > s2[i])
		{
			flag = 1;
			break;
		}
		else if (s1[i] == '\0' || s1[i] == '\0')
		{
			if (len1 < len2)
				flag = -1;
			else if (len2 < len1)
				flag = 1;
			else
			flag = 0;
			break;
		}
	}
	return flag;
}

int strcomp_n(const char* s1, const char* s2, int n)
{
	int flag = 0;
	for (int i = 0; i < n + 1; i++)
	{
		if (s1[i] < s2[i])
		{
			flag = -1;
			break;
		}
		else if (s1[i] > s2[i])
		{
			flag = 1;
			break;
		}
		else
		{
			flag = 0;
		}
	}
	return flag;
}
char* strcp(char* s1, const char* s2)
{
	int size = 0;
	while (s1[size]!='\0')
	{
		size++;
	}
	for (int i = 0; i < size; i++)
	{
		s1[i] = s2[i];
	}
	return s1;

}

char* strcpy_n(char* s1, const char* s2, int n)
{
	for (int i = 0; i < n; i++)
	{
		s1[i] = s2[i];
	}
	return s1;
}

char* strcatenate(char* s1, const char* s2)
{
	int size = 0;
	while (s1[size] != '\0')
	{
		size++;
	}
	int i = 0;
	for (int i = 0; s2[i] != '\0'; i++)
	{
		if (i == 0)
			s1[size++] = ' ';
		s1[size++] = s2[i];
	}
	s1[size + i] = '\0';
	return s1;
}
char* strcatenate_n(char* s1, const char* s2, int n)
{
	int size = 0;
	while (s1[size] != '\0')
	{
		size++;
	}
	int i = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			s1[size++] = ' ';
			s1[size++] = s2[i];
	}
	s1[size + i] = '\0';

	return s1;
}
int main()
{
	char s1[100] , s2[100];
	int n = 0;
	cout << "Enter s string to check its len: ";
	cin.get(s1, 100);
	cin.ignore();
	cout << "string Len = " << stlen(s1);
	cout << "\nEnter s string-1 ";
	cin.get(s1, 100);
	cin.ignore();
	cout << "Enter s string-2 ";
	cin.get(s2, 100);
	cin.ignore();
	cout << "strcmp = " << strcomp(s1, s2)<<endl;
	cout << "\nEnter s string-1 ";
	cin.get(s1, 100);
	cin.ignore();
	cout << "Enter s string-2 ";
	cin.get(s2, 100);
	cin.ignore();
	cout << "Enter n-char to compare: ";
	cin >> n;
	cin.ignore();
	cout << "strcmp of n-char= " << strcomp_n(s1, s2,n)<<endl;
	cout << "Enter a String to copy: ";
	cin.get(s2, 100);
	cin.ignore();
	char *cpy = strcp(s1, s2);
	cout << "Copied String: ";
	for (int i=0; cpy[i]!='\0'; i++)
	{
		cout << cpy[i];
	}
	
	cout << "\nENter no of of string to copy: ";
	cin >> n;
	cin.ignore();
	cout << "Copied String of n: ";
    cpy = strcpy_n(s1, s2,n);

	for (int i = 0; i < n; i++)
	{
		cout << cpy[i];
	}
	cout << "\nEnter a String to cancatenation\n";
	cout << "Enter a String-1: ";
	cin.get(s1, 100);
	cin.ignore();
	cout << "Enter a String-2: ";
	cin.get(s2, 100);
	cin.ignore();
	cpy = strcatenate(s1, s2);
	
	for (int i = 0; cpy[i] != '\0'; i++)
	{
		cout << cpy[i];
	}
	cout << "Enter a String-1: ";
	cin.get(s1, 100);
	cin.ignore();
	cout << "Enter a String-2: ";
	cin.get(s2, 100);
	cin.ignore();
	cout << "\nEnter a no of char to catenate: ";
	cin >> n;
	cpy = strcatenate_n(s1, s2,n);
	for (int i = 0; cpy[i] != '\0'; i++)
	{
		cout << cpy[i];
	}
}