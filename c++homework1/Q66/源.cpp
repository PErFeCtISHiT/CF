#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int isHam(string s);
string turn(int x,int n);
int main(){
string s;
	cin >> s;
	int r;
	int len = s.length();
	for (r = 0; pow(2, r) - 1 - r - s.length() <= 0; r++);
	for (int i = 0; i < r; i++){
		const char *a = "0";
		s.insert(pow(2,i) - 1, a);
	}
	for (int i = 1; i <= s.length(); i++){
		string temp = turn(i,r);
		if (!isHam(temp)){
			for (int j = temp.length() - 1; j >= 0; j--){
				if (temp.at(j) == '1'){
					s.at(pow(2, temp.length() - j - 1) - 1) = (s.at(pow(2, temp.length() - j - 1) - 1) ^ s.at(i - 1)) + 48;//
				}
			}
		}
	}
	cout << s;
}
string turn(int x,int n){
	string s = "";
	while (x > 0){
		if (x % 2 == 0)
			s = '0' + s;
		else
			s = '1' + s;
		x /= 2;
	}
	while (s.length() < n)
		s = '0' + s;
	return s;
}
int isHam(string s){
	int count = 0;
	for (int i = 0; i < s.length(); i++){
		if (s.at(i) == '1')
			count++;
	}
	if (count == 1)
		return 1;
	else
		return 0;
}