#include<iostream>
#include<string>
using namespace std;
long long turn(long long x);
int main(){
	long long res = 0;
	int n;
	cin >> n;
	long long *a = new long long[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
		res += turn(a[i]);
	}
	cout << res;
}
long long turn(long long x){
	string s = "";
	while (x > 0){
		if (x % 2 == 0)
			s = '0' + s;
		else
			s = '1' + s;
		x /= 2;
	}
	while (s.length() < 3)
		s = '0' + s;
	long long res = 0;
	if (s.at(0) == '1')
		res += 4;
	if (s.at(1) == '1')
		res += 2;
	if (s.at(2) == '1')
		res += 1;
	return res;
}