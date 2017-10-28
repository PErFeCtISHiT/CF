#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int turn(char a)
{
	if (a >= 'a' && a <= 'z')
		return a * 2;
	else
		return (a + 32) * 2 + 1;
}
bool compare(string a, string b)
{
	if (a.length() > b.length())
		return false;
	else if (a.length() < b.length())
		return true;
	else
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (turn(a.at(i)) > turn(b.at(i)))
				return false;
			else if (turn(a.at(i)) < turn(b.at(i)))
				return true;
		}
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	string *str = new string[n];
	for (int i = 0; i < n; i++)
		cin >> str[i];
	sort(str, str + n,compare);
	for (int i = 0; i < n; i++)
		cout << str[i] << endl;
}