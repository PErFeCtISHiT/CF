#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct Node
{
	string data = "";
	Node *next = NULL;
};
struct final
{
	double data = 0;
	string id = "";
};
int stoint(string s)
{
	int ret = 0;
	for (int i = 0; i < s.length(); i++)
	{
		ret = ret * 10 + s.at(i) - 48;
	}
	return ret;
}
bool comp(final a, final b)
{
	if (a.data > b.data)
		return true;
	else if (a.data < b.data)
		return false;
	else
	{
		if (stoint(a.id) > stoint(b.id))
			return true;
		else
			return false;
	}
}
int main()
{
	int n;
	cin >> n;
	string subj[100];
	int locsub = 0;
	Node student[100];
	int loc = 0;
	Node sub[100];
	int locc = 0;
	Node score[100];
	int locs = 0;
	for (int i = 0; i < n; i++)
	{
		string s1, s2, s3, s4;
		cin >> s1 >> s2 >> s3 >> s4;
		int f = 0;
		int fl = 0;
		for (int i = 0; i < locsub; i++)
		{
			if (subj[i] == s3)
			{
				fl = 1;
				break;
			}
		}
		if (fl == 0)
		{
			subj[locsub] = s3;
			locsub++;
		}
		for (int i = 0; i < loc; i++)
		{
			if (student[i].data == s2)
			{
				f = 1;
				Node *temp = &student[i];
				int flag = 0;
				while (temp->next != NULL)
				{
					if (temp->data == s3)
					{
						temp->next->data = s4;
						flag = 1;
						break;
					}
					temp = temp->next;
				}
				if (flag == 0)
				{
					sub[locc].data = s3;
					score[locs].data = s4;
					temp->next= &sub[locc];
					temp->next->next = &score[locs];
					locc++;
					locs++;
				}
				break;
			}
		}
		if (f == 0)
		{
			student[loc].data = s2;
			sub[locc].data = s3;
			score[locs].data = s4;
			student[loc].next = &sub[locc];
			sub[locc].next = &score[locs];
			loc++;
			locc++;
			locs++;
		}
	}
	final agv[100];
	double sumall = 0;
	for (int i = 0; i < loc; i++)
	{
		Node *temp = student[i].next;
		double sum = 0;
		while (temp != NULL)
		{
			temp = temp->next;
			sum += stoint(temp->data);
			temp = temp->next;
		}
		sum = sum / locsub;
		agv[i].data = sum;
		agv[i].id = student[i].data;
		sumall += sum;
	}
	sumall = sumall / loc;
	final stu[100];
	int locstu = 0;
	for (int i = 0; i < loc; i++)
	{
		if (agv[i].data <= sumall)
		{
			stu[locstu] = agv[i];
			locstu++;
		}
	}
	sort(stu, stu + locstu, comp);
	for (int i = 0; i < locstu; i++)
		cout << stu[i].id << endl;
}