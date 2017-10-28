#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	cin >> s;
	int res = 0;
	for (int i = 0; i < s.length(); i++){
		switch (s.at(i)){
		case 'I':
			if (i == s.length() - 1)
				res++;
			else if (s.at(i + 1) != 'I')
				res--;
			else
				res++;
			break;
		case 'X':
			if (i == s.length() - 1)
				res += 10;
			else if (s.at(i + 1) != 'X' && s.at(i + 1) != 'I' && s.at(i + 1) != 'V')
				res -= 10;
			else
				res += 10;
			break;
		case 'C':
			if (i == s.length() - 1)
				res += 100;
			else if (s.at(i + 1) != 'X' && s.at(i + 1) != 'I' && s.at(i + 1) != 'V' && s.at(i + 1) != 'C' && s.at(i + 1) != 'L')
				res -= 100;
			else
				res += 100;
			break;
		case 'M':
			res += 1000;
			break;
		case 'V':
			res += 5;
			break;
		case 'L':
			res += 50;
			break;
		case 'D':
			res += 500;
			break;
		}
	}
	cout << res;
}