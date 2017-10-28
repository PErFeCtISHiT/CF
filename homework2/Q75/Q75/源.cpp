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
};
struct stack
{
	Node *data = NULL;
	stack *next = NULL;
};
stack *s = NULL;
stack * Pop()
{
	stack *ret = s;
	s = s->next;
	return ret;
}
void Push(stack *t)
{
	t->next = s;
	s = t;
}
struct queue
{
	Node *data = NULL;
	queue *next = NULL;
};
Node *root = NULL;
queue *esp = NULL;
queue *ebp = NULL;
//此处为队列，ebp指对头，esp指队尾
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
int main()
{
	string s_;
	int loc = 0;
	string str[50];
	getline(cin, s_);
	string temp;
	for (int i = 0; i<s_.length(); i++)
	{
		if (s_.at(i) != ' ')
		{
			temp += s_.at(i);
		}
		else
		{
			if (s_.at(i + 1) == ' ')
				i++;
			str[loc] = temp;
			loc++;
			temp = "";
		}
	}
	str[loc] = temp;
	loc++;
	int loct = 0;
	Node n;
	n.data = str[0];
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
	while (loct < loc - 1)
	{
		Node *op = topandpop()->data;
		loct++;
		left[leftcon].data = str[loct];
		op->left = &left[leftcon];
		l[lcon].data = &left[leftcon];
		push(&l[lcon]);
		leftcon++;
		lcon++;
		loct++;
		right[rightcon].data = str[loct];
		op->right = &right[rightcon];
		r[rcon].data = &right[rightcon];
		push(&r[rcon]);
		rcon++;
		rightcon++;
	}
	Node *pri = root;
	stack st[1000];
	int stloc = 0;
	while (true)
	{
		while (pri != NULL)
		{
			st[stloc].data = pri;
			Push(&st[stloc]);
			stloc++;
			pri = pri->left;
		}
		if (s != NULL)
		{
			pri = Pop()->data;
			if (pri->data != "null")
				cout << pri->data << " ";
			pri = pri->right;
		}
		else
			break;
	}
}