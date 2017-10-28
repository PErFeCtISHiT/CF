#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
using namespace std;
struct Node
{
	int data = 0;
	Node *before = NULL;
};
int loc1 = 0;
int loc2 = 0;
int main()
{
	string str;
	getline(cin, str);
	Node num1[100];
	Node *ptr1 = NULL;
	for (int i = 0; str.at(i) != 'n'; i++)
	{
		if (str.at(i) >= '0' && str.at(i) <= '9')
		{
			num1[loc1].data = str.at(i) - 48;
			num1[loc1].before = ptr1;
			ptr1 = &num1[loc1];
			loc1++;
		}
	}
	getline(cin, str);
	Node num2[100];
	Node *ptr2 = NULL;
	for (int i = 0; str.at(i) != 'n'; i++)
	{
		if (str.at(i) >= '0' && str.at(i) <= '9')
		{
			num2[loc2].data = str.at(i) - 48;
			num2[loc2].before = ptr2;
			ptr2 = &num2[loc2];
			loc2++;
		}
	}
	int in = 0;
	Node res[100];
	Node *resu = NULL;
	int loc = 0;
	while (ptr1 != NULL && ptr2 != NULL)
	{
		int sum = ptr1->data + ptr2->data + in;
	if (sum >= 10)
	{
	in = 1;
	sum -= 10;
	}
	else
		in = 0;
	res[loc].data = sum;
	res[loc].before = resu;
	resu = &res[loc];
	loc++;
	ptr1 = ptr1->before;
	ptr2 = ptr2->before;
	}
	if (ptr1 == NULL)
	{
	while (ptr2 != NULL)
	{
	int sum = ptr2->data + in;
	if (sum >= 10)
	{
	in = 1;
	sum -= 10;
	}
	else
	in = 0;
	res[loc].data = sum;
	res[loc].before = resu;
	resu = &res[loc];
	loc++;
	ptr2 = ptr2->before;
	}
	}
	else
	{
	while (ptr1 != NULL)
	{
	int sum = ptr1->data + in;
	if (sum >= 10)
	{
	in = 1;
	sum -= 10;
	}
	else
	in = 0;
	res[loc].data = sum;
	res[loc].before = resu;
	resu = &res[loc];
	loc++;
	ptr1 = ptr1->before;
	}
	}
	if (in == 1)
	{
	res[loc].data = 1;
	res[loc].before = resu;
	resu = &res[loc];
	loc++;
	}
	for (; loc > 0; loc--)
	{
		if (res[loc - 1].data != 0)
			break;
	}
	for (; loc > 0; loc--)
	{
	cout << res[loc - 1].data << ">";
	}
	cout << "null";
}

