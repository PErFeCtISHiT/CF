#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;
struct Node
{
	string data = "";
	Node *left = NULL;
	Node *right = NULL;
	int deep = 0;
};
struct queue
{
	Node *data = NULL;
	queue *next = NULL;
};
Node *root = NULL;
queue *esp = NULL;
queue *ebp = NULL;
queue * topandpop()
{
	queue *ret = ebp;
	if (ebp == esp)
		esp = esp->next;
	ebp = ebp->next;
	return ret;
}
void push(queue * t)
{
	if (esp != NULL)
		esp->next = t;
	else
		ebp = t;
	esp = t;
}
int findson(Node *node1, Node *node2)
{
	if (node1 == NULL || node1->data == "NULL")
		return -1;
	if (node1 == node2)
		return 0;
	int temp1 = findson(node1->left, node2);
	int temp2 = findson(node1->right, node2);
	if (temp1 == -1 && temp2 == -1)
		return -1;
	else if (temp1 != -1)
		return temp1 + 1;
	else
		return temp2 + 1;
}
int main()
{
	int nui;
	cin >> nui;
	string s_;
	int loc = 0;
	string str[50];
	getline(cin, s_);
	getline(cin, s_);
	string s1, s2;
	cin >> s1 >> s2;
	Node *node1;
	Node *node2;
	string temp;
	for (int i = 0; i < s_.length(); i++)
	{
		if (s_.at(i) != ' ')
		{
			temp += s_.at(i);
		}
		else
		{
			str[loc] = temp;
			loc++;
			temp = "";
		}
	}
	str[loc] = temp;
	loc++;
	int loct = 0;
	Node n;
	if (str[0] == s1)
		node1 = &n;
	if (str[0] == s2)
		node2 = &n;
	n.data = str[0];
	n.deep = 0;
	root = &n;
	queue q;
	q.data = &n;
	ebp = &q;
	push(&q);
	Node left[1000];
	int leftcon = 0;
	Node right[1000];
	int rightcon = 0;
	queue l[1000];
	int lcon = 0;
	queue r[1000];
	int rcon = 0;
	int level = 1;
	while (loct < loc - 1)
	{
		Node *op = topandpop()->data;
		loct++;
		if (str[loct] == s1)
			node1 = &left[leftcon];
		if (str[loct] == s2)
			node2 = &left[leftcon];
		left[leftcon].data = str[loct];
		left[leftcon].deep = level;
		op->left = &left[leftcon];
		l[lcon].data = &left[leftcon];
		push(&l[lcon]);
		leftcon++;
		lcon++;
		loct++;
		if (str[loct] == s1)
			node1 = &right[rightcon];
		if (str[loct] == s2)
			node2 = &right[rightcon];
		right[rightcon].data = str[loct];
		right[rightcon].deep = level;
		op->right = &right[rightcon];
		r[rcon].data = &right[rightcon];
		push(&r[rcon]);
		rcon++;
		rightcon++;
		level++;
	}
	if (node1->deep == node2->deep){
		if (node1->data == node2->data)
		{
			cout << 0;
			return 0;
		}
		else
		{
			cout << -1;
			return 0;
		}
	}
	if (node1->deep > node2->deep)
	{
		cout << findson(node2, node1);
	}
	else
		cout << findson(node1, node2);
}