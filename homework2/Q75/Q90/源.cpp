#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct Node
{
	int data = 0;
	Node *next = NULL;
};
Node *head = NULL;
Node *now = NULL;
int size = 0;
int main()
{
	int n;
	cin >> n;
	Node temp[100];
	int loc = 0;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (str == "ADD")
		{
			int d;
			cin >> d;
			temp[loc].data = d;
			temp[loc].next = NULL;
			if (head == NULL){
				head = &temp[loc];
				now = head;
			}
			else
			{
				now->next = &temp[loc];
				now = now->next;
			}
			loc++;
			size++;
		}
		else if (str == "REVERSE")
		{
			if (head == NULL || head->next == NULL)
				continue;
			now = head;
			Node *store = head;
			head = head->next;
			while (head->next != NULL)
			{
				Node *temp = head;
				head = head->next;
				temp->next = store;
				store = temp;
			}
			head->next = store;
			now->next = NULL;
		}
		else if (str == "REMOVEREPEAT")
		{
			int deln;
			cin >> deln;
			Node *temp = head;
			Node *pervtemp = NULL;
			Node *pervnodestore = NULL;
			Node *nodestore = NULL;
			Node *del = NULL;
			while (temp != NULL)
			{
				if (temp->data == deln)
				{
					if (nodestore == NULL)
					{
						pervnodestore = pervtemp;
						nodestore = temp;
						pervtemp = temp;
						temp = temp->next;
					}
					else
					{
						size--;
						if (pervnodestore == NULL)
						{
							if (pervtemp == head)
							{
								nodestore = temp;
								pervtemp = temp;
								temp = temp->next;
							}
							else
							{
								pervnodestore = pervtemp;
								nodestore = temp;
								pervtemp = temp;
								temp = temp->next;
							}
							head = head->next;
						}
						else
						{
							pervnodestore->next = nodestore->next;
							pervnodestore = pervtemp;
							nodestore = temp;
							pervtemp = temp;
							temp = temp->next;
						}
					}
				}
				else{
					pervtemp = temp;
					temp = temp->next;
				}
			}
		}
		else if (str == "DEL")
		{
			int deln;
			cin >> deln;
			Node *temp = head;
			Node *prevtemp = NULL;
			while (temp != NULL)
			{
				if (temp->data == deln)
				{
					if (prevtemp == NULL){
						head = head->next;
						temp = head;
					}
					else
					{
						prevtemp->next = temp->next;
						temp = temp->next;
					}
					size--;
				}
				else{
					prevtemp = temp;
					temp = temp->next;
				}
			}
		}
		else if (str == "SIZE")
			cout << size << endl;
		else if (str == "PRINT")
		{
			if (head == NULL)
				cout << "NULL";
			else
			{
				Node *temp = head;
				while (temp != NULL)
				{
					cout << temp->data << ' ';
					temp = temp->next;
				}
			}
			cout << endl;
		}
	}
}