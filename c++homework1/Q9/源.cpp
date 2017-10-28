#include<iostream>
#include<cmath>
using namespace std;
int judge(int x);
int main(){
	int m, n;
	cin >> m >> n;
	int res = 0;
	for (int i = m; i <= n; i++){
		if (judge(i))
			res += i;
	}
	cout << res;
}
int judge(int x){
	if (x == 1)
		return 0;
	if (x == 2)
		return 1;
	for (int i = 2; i <= sqrt((double)x) + 1; i++){
		int temp = x / i;
		if (temp * i == x)
			return 0;
	}
	return 1;
}