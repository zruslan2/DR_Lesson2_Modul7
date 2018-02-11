#include <vector>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int i, j;

void head(char mas[])
{
	int len, third, s1_len, s2_len, s3_len, maks;
	len = strlen(mas);
	third = len / 3;
	s1_len = third;
	for (int i = s1_len; i < len; i++)
	{
		if (mas[s1_len] != ' ') s1_len++;
		else break;
	}
	s2_len = third;
	for (int i = s1_len + s2_len; i < len; i++)
	{
		if (mas[s1_len + s2_len] != ' ') s2_len++;
		else break;
	}
	s3_len = len - (s1_len + s2_len);
	vector<char>str1(s1_len);
	vector<char>str2(s2_len);
	vector<char>str3(s3_len);
	for (int i = 0; i < s1_len; i++)
	{
		str1[i] = mas[i];
	}
	for (int i = s1_len + 1; i < s1_len + s2_len; i++)
	{
		str2[i - (s1_len + 1)] = mas[i];
	}
	for (int i = s1_len + s2_len + 1; i < len; i++)
	{
		str3[i - (s1_len + s2_len + 1)] = mas[i];
	}
	maks = s1_len;
	if (s2_len > maks)maks = s2_len;
	if (s3_len > maks)maks = s3_len;
	system("cls");
	SetConsoleTextAttribute(hConsole, 11);
	setlocale(LC_ALL, ".866");
	cout << " Ú";
	for (int i = 0; i <= maks + 1; i++)cout << "Ä";
	cout << "¿\n";
	cout << " ³ "; setlocale(LC_ALL, ".1251");
	for (int i = 0; i<s1_len; i++) cout << str1[i];
	if (s1_len < maks)
	{
		for (int i = 0; i < maks - s1_len; i++)cout << " ";
	}
	setlocale(LC_ALL, ".866"); cout << " ³\n";
	cout << " ³ "; setlocale(LC_ALL, ".1251");
	for (int i = 0; i<s2_len; i++) cout << str2[i];
	if (s2_len < maks)
	{
		for (int i = 0; i < maks - s2_len; i++)cout << " ";
	}
	setlocale(LC_ALL, ".866"); cout << " ³\n";
	cout << " ³ "; setlocale(LC_ALL, ".1251");
	for (int i = 0; i<s3_len; i++) cout << str3[i];
	if (s3_len < maks)
	{
		for (int i = 0; i < maks - s3_len; i++)cout << " ";
	}
	setlocale(LC_ALL, ".866"); cout << " ³\n";
	cout << " À";
	for (int i = 0; i <= maks + 1; i++)cout << "Ä";
	cout << "Ù\n";
	SetConsoleTextAttribute(hConsole, 15);
	setlocale(LC_ALL, ".1251");
}

void yellow()
{
	SetConsoleTextAttribute(hConsole, 14);
}

void white()
{
	SetConsoleTextAttribute(hConsole, 15);
}

void red()
{
	SetConsoleTextAttribute(hConsole, 12);
}

void green()
{
	SetConsoleTextAttribute(hConsole, 11);
}

int Len(int ch)
{
	int raz = 0;
	while (ch > 0)
	{
		ch = ch / 10;
		++raz;
	}
	return raz;
}

bool lucky_number(int ch)
{
	int c1, c2, c3, c4, c5, c6, ost;
	c1 = ch / 100000;
	ost = ch - (c1 * 100000);
	c2 = ost / 10000;
	ost = ost - (c2 * 10000);
	c3 = ost / 1000;
	ost = ost - (c3 * 1000);
	c4 = ost / 100;
	ost = ost - (c4 * 100);
	c5 = ost / 10;
	c6 = ost - (c5 * 10);
	if ((c1 + c2 + c3) == (c4 + c5 + c6)) return true;
	else return false;
}

int new_number(int ch)
{
	int c1, c2, c3, c4, ost;
	c1 = ch / 1000;
	ost = ch - (c1 * 1000);
	c2 = ost / 100;
	ost = ost - (c2 * 100);
	c3 = ost / 10;
	c4 = ost - (c3 * 10);
	return (c2 * 1000) + (c1 * 100) + (c4 * 10) + c3;
}

int best_m(double* p)
{
	if ((p[0] > p[1]) && (p[0] > p[2])) return 1;
	if ((p[1] > p[0]) && (p[1] > p[2])) return 2;
	if ((p[2] > p[0]) && (p[2] > p[1])) return 3;
}

void salary(double* p, double *z, int l)
{
	for (i = 0; i < 3; i++)
	{
		if (i != l)
		{
			if(p[i]<=500)
			z[i] = 500 + (p[i] * 3 / 100);
			else if(p[i]>500&&p[i]<=1000)
			z[i] = 500 + (p[i] * 5 / 100);
			else if(p[i]>1000)
			z[i] = 500 + (p[i] * 8 / 100);
		}
		else
		{
			if (p[i] <= 500)
				z[i] = 500 + (p[i] * 3 / 100)+200;
			else if (p[i]>500 && p[i] <= 1000)
				z[i] = 500 + (p[i] * 5 / 100)+200;
			else if (p[i]>1000)
				z[i] = 500 + (p[i] * 8 / 100)+200;
		}
	}
}

void count_s(int &doh, int &opozd, int &string)
{
	int op;
	op = opozd / 3;
	string = (doh + (op * 20)) / 0.5;
	if (string % 100 != 0)
		string = (string / 100 + 1) * 100;
}

void count_o(int &doh, int &opozd, int &string)
{
	int str;
	str = (string / 100)*100;
	opozd = (((str*0.5)-doh) / 20)*3;
	if (opozd % 3 != 0)
		opozd = (opozd / 3) * 3;
}

void count_d(int &doh, int &opozd, int &string)
{
	int str;
	str = (string / 100) * 100;
	int op;
	op = opozd / 3;
	doh = (str*0.5)-(op*20);
}

int d_ch(int n, int k)
{
	int c1, c2, c3, ost;
	int c_ch=0;
	for (i = 0; i <= k; i++)
	{
		c1 = i / 100;
		ost = i - (c1 * 100);
		c2 = ost / 10;
		c3 = ost - (c2 * 10);
		if ((c1 == c2) || (c1 == c3) || (c2 == c3))c_ch++;
	}
	return c_ch;
}

int r_ch(int n, int k)
{
	int c1, c2, c3, ost;
	int c_ch = 0;
	for (i = 0; i <= k; i++)
	{
		c1 = i / 100;
		ost = i - (c1 * 100);
		c2 = ost / 10;
		c3 = ost - (c2 * 10);
		if ((c1 != c2) && (c1 != c3) && (c2 != c3))c_ch++;
	}
	return c_ch;
}

void rand_arr(int*arr, int r)
{
	srand(time(0));
	for (i = 0; i < r; i++)
	{
		arr[i] = 1 + rand() % 9;
	}
}

void print_arr(int*arr, int r)
{
	for (i = 0; i < r; i++)
	{
		if(arr[i]<10)
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void clear_ch(int*arr, int r)
{
	int a = 1;
	for (int k = 0; k < r; k++)
	{
		for (i = 0; i < r; i++)
		{
			if (arr[i] == 3 || arr[i] == 6)
			{
				for (j = i; j < r - a; j++)
				{
					arr[j] = arr[j + 1];
				}
				arr[r - a] = 11;
				a++;
			}
		}
	}
}

void without(int ch)
{
	for (i = 1; i <= ch; i++)
	{
		if (ch%i == 0)cout << i << endl;
	}
}

void tr(int a)
{
	if (a == 1)
	{
		int n = 0;
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (j < n)
				{
					cout << " ";
				}
				else
				{
					cout << "*";
				}				
			}
			cout << endl;
			n++;
		}
	}
	else if (a == 2)
	{
		int n = 0;
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (j < n)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
			n++;
		}
	}
	else if (a == 3)
	{
		int n = 0, k=10;
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (j > n&&j<k)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
			n++;
			k--;
		}
	}
	else if (a == 4)
	{
		int n = 9, k = 1;
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (j > n&&j<k)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
			n--;
			k++;
		}
	}
	else if (a == 5)
	{
		int n = 0, k = 10;
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (j > n&&j<k)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
			n++;
			k--;
		}
		n = 4, k = 6;
		for (i = 5; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (j > n&&j<k)
				{
					cout << "*";
				}
				else
				{
					cout << " ";
				}
			}
			cout << endl;
			n--;
			k++;
		}
	}
}