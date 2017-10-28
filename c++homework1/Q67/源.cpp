#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	getline(cin, s);
	int res = 0;
	for (int i = 0; i < s.length(); i++){
		if (s.at(i) != ' ')
			res++;
		else
			res = 0;
	}
	cout << res;
}