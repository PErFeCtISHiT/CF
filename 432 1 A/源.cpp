#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	typedef int t[5];
	auto x = new t[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
			cin >> *(*(x + j)+i * 5);
	}
	auto b = true;
	for (int i = 0; i < n; i++)
	{
		int flag = 
	}
}