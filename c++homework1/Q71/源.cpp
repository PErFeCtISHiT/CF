#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	cin >> s;
	for (int i = 0; i < s.length() / 2; i++){
		char temp = s.at(i);
		s.at(i) = s.at(s.length() - i - 1);
		s.at(s.length() - i - 1) = temp;
	}
	cout << s;
	/*int a;
	cin >> a;
	int res = 0;
	int count = 0;
	while (a != 0){
		int i = 1;
		while (i <= a){
			i *= 10;
		}
		i /= 10;
		if (i == 0)
			i = 1;
		int m = a / i;
		a -= i * m;
		for (int j = 0; j < count; j++)
			m *= 10;
		res += m;
		count++;
	}
	cout << res;*/
}