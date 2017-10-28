#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	long long res = 0;
	long long a = 0;
	long long b = 1;
	for (int i = 2; i <= n; i++){
		res = a + b;
		a = b;
		b = res;
	}
	cout << res;
}
