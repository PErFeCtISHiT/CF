#include<iostream>
#include<fstream>
#include <string>
using namespace std;
struct Node
{
	int data;
	Node *left = NULL;
	Node *right = NULL;
	Node *next = NULL;
};
Node *head = NULL;
Node *tail = NULL;
int findMin(Node *root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL)
		return root->data;
	else
	{
		int a = findMin(root->left);
		int b = findMin(root->right);
		if (a < b)
			return a + root->data;
		else
			return b + root->data;
	}
}
void inqueue(Node *t){
	if (tail != NULL)
	{
		tail->next = t;
	}
	else
		head = t;
	tail = t;
}
Node * outqueue()
{
	Node *ret = head;
	if (head == tail)
		tail = tail->next;
	head = head->next;
	return ret;
}
int main()
{
	//链表方法
	/*int n;
	cin >> n;
	if (n == 0)
		return 0;
	Node *node = new Node[n * (n + 1) / 2 + 5];
	int loc = 1;
	cin >> node[0].data;
	inqueue(&node[0]);
	for (int i = 1; i < n; i++)
	{
		Node* temp = outqueue();
		cin >> node[loc].data;
		temp->left = &node[loc];
		inqueue(&node[loc]);
		loc++;
		cin >> node[loc].data;
		temp->right = &node[loc];
		inqueue(&node[loc]);
		loc++;
		for (int j = 0; j < i - 1; j++)
		{
			Node* tem = outqueue();
			tem->left = temp->right;
			cin >> node[loc].data;
			tem->right = &node[loc];
			inqueue(&node[loc]);
			loc++;
			temp = tem;
		}
	}
	cout << findMin(&node[0]);*/
	//数组方法
	int n;
	cin >> n;
	int num[100][100];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
			cin >> num[i][j];
	}
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (num[i][j] > num[i][j + 1])
			{
				num[i - 1][j] += num[i][j + 1];
			}
			else
				num[i - 1][j] += num[i][j];
		}
	}
	cout << num[0][0];
}