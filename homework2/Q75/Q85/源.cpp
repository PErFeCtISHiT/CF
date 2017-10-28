/*#include<iostream>
#include <string>
#include<fstream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int *num = new int[n];
	for (int i = 0; i < n; i++)
		cin >> num[i];
	int m;
	cin >> m;
	string cmd;
	for (int i = 0; i < m; i++)
	{
		cin >> cmd;
		if (cmd.at(0) == 'r')
		{
			int num1;
			int num2;
			cin >> num1 >> num2;
			for (int j = 0; j < n; j++)
			{
				if (num[j] == num1)
				num[j] = num2;
			}
		}
		else if (cmd.at(0) == 'm')
		{
			string type;
			cin >> type;
			if (type.at(0) == 't')
			{
				int num1;
				cin >> num1;
				int count = 0;
				int *store = new int[n];
				int loc = 0;
				for (int j = 0; j < n; j++)
				{
					if (num[j] == num1)
						count++;
					else
					{
						store[loc] = num[j];
						loc++;
					}
				}
				for (int j = 0; j < n - count; j++)
				{
					num[j] = store[j];
				}
				for (int j = n - count; j < n; j++)
					num[j] = num1;
			}
			else
			{
				int num1;
				cin >> num1;
				int count = 0;
				int *store = new int[n];
				int loc = 0;
				for (int j = 0; j < n; j++)
				{
					if (num[j] == num1)
						count++;
					else
					{
						store[loc] = num[j];
						loc++;
					}
				}
				for (int j = 0; j < count; j++)
				{
					num[j] = num1;
				}
				for (int j = count; j < n; j++)
					num[j] = store[j - count];
			}
		}
		else if (cmd.at(0) == 't')
		{
			string type;
			cin >> type;
			if (type.at(0) == 'h')
			{
				int num1;
				cin >> num1;
				num1 = num1 % n;
				int *store = new int[num1];
				for (int j = 0; j < num1; j++){
					store[j] = num[j];
				}
				for (int j = 0; j < n - num1; j++)
				{
					num[j] = num[j + num1];
				}
				for (int j = n - num1; j < n; j++)
				{
					num[j] = store[j + num1 - n];
				}
			}
			else
			{
				int num1;
				cin >> num1;
				num1 = num1 % n;
				int *store = new int[num1];
				for (int j =  n - num1; j < n; j++){
					store[j + num1 - n] = num[j];
				}
				for (int j = n - 1; j >= num1; j--)
				{
					num[j] = num[j - num1];
				}
				for (int j = 0; j < num1; j++)
				{
					num[j] = store[j];
				}
			}
		}
		else if (cmd.at(0) == 'p')
		{
			for (int j = 0; j < n; j++)
				cout << num[j] << ' ';
			cout << endl;
		}
	}
}*/
#include<iostream>
using namespace std;
int fun(int s[], int n, int *x)
{
	int i = 0, j = 0;
	for (; i < 10; i++)
	{
		if (s[i] >= 90)
			j++;
		if (s[i] < 60)
			(*x)++;
	}
	return j;
}
int main()
{
	int s[10], i, p = 0, *x;
	*x = p;
	for (i = 0; i < 10; i++)
		cin >> s[i];
	cout << fun(s, 20, x) << " " << *x << endl;
	return 0;
}