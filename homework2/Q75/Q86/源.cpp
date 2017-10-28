#include<iostream>
using namespace std;
struct Node
{
	int way;
	int x;
	int y;
};
struct str
{
	int data;
	int flag = 0;
};
int main()
{
	Node p;
	p.way = 0;
	p.x = 0;
	p.y = 0;
	int m, n;
	cin >> m >> n;
	str num[100][100];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> num[i][j].data;
		}
	}
	int *loc = new int[m * n];
	for (int i = 0; i < m * n; i++)
	{
		loc[i] = num[p.y][p.x].data;
		num[p.y][p.x].flag = 1;
		if (p.way == 0){
			if (p.x == n - 1 || num[p.y][p.x + 1].flag == 1)
			{
				p.way = 1;
				p.y++;
			}
			else
			{
				p.x++;
			}
		}
		else if (p.way == 1)
		{
			if (p.y == m - 1 || num[p.y + 1][p.x].flag == 1)
			{
				p.way = 2;
				p.x--;
			}
			else
			{
				p.y++;
			}
		}
		else if (p.way == 2)
		{
			if (p.x == 0 || num[p.y][p.x - 1].flag == 1)
			{
				p.way = 3;
				p.y--;
			}
			else
			{
				p.x--;
			}
		}
		else if (p.way == 3)
		{
			if (p.y == 0 || num[p.y - 1][p.x].flag == 1)
			{
				p.way = 0;
				p.x++;
			}
			else
			{
				p.y--;
			}
		}
	}
	int ret;
	cin >> ret;
	cout << loc[ret];
}