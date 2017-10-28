#include<iostream>
#include <string>
using namespace std;
struct Node
{
	string s = "";
	Node *next = NULL;
};
Node *esp = NULL;
void push(Node *p)
{
	p->next = esp;
	esp = p;
}
Node * pop()
{
	Node *ret = esp;
	esp = esp->next;
	return ret;
}
int main()
{
	string str;
	getline(cin, str);
	Node node[20];
	int loc = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '<')
		{
			if (i == str.length() - 1)
			{
				cout << "False";
				return 0;
			}
			else if (str.at(i + 1) == '/')
			{
				i++;
				if (i == str.length() - 1 || esp == NULL)
				{
					cout << "False";
					return 0;
				}
				else
				{
					i++;
					if (i == str.length() - 1)
					{
						cout << "False";
						return 0;
					}
					string end = "";
					for (; i < str.length() && str.at(i) >= 'A' && str.at(i) <= 'Z'; i++)
					{
						end += str.at(i);
					}
					string temp = pop()->s;
					if (temp != end || i == str.length() || str.at(i) != '>')
					{
						cout << "False";
						return 0;
					}
				}
			}
			else if (str.at(i + 1) == '!')
			{
				i++;
				if (str.length() - i <= 2 || str.at(i + 1) != '-' || str.at(i + 2) != '-')
				{
					cout << "False";
					return 0;
				}
				i += 3;
				int flag = 0;
				for (; i < str.length() - 5; i++)
				{
					if (str.at(i) == '-' && str.at(i + 1) == '-' && str.at(i + 2) == '>')
					{
						i += 3;
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					cout << "False";
					return 0;
				}
			}
			else
			{
				i++;
				if (i == str.length() - 1)
				{
					cout << "False";
					return 0;
				}
				else
				{
					string end = "";
					for (; i < str.length() && str.at(i) >= 'A' && str.at(i) <= 'Z'; i++)
					{
						end += str.at(i);
					}
					if (i == str.length() - 1 || str.at(i) != '>')
					{
						cout << "False";
						return 0;
					}
					else
					{
						node[loc].s = end;
						push(&node[loc]);
						loc++;
					}
				}
			}
		}
	}
	cout << "True";
}