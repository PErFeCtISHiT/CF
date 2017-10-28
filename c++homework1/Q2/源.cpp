#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long x, y;
	cin >> x >> y;
	if (y >= 0){
		x = pow(x, y);
		cout << x;
	}
	else{
		y = abs(y);
		x = pow(x, y);
		long long res = 1 / (double)x;
		cout << res;
	}
}