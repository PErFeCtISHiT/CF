#include<iostream>
using namespace std;
const long long mod = 998244353;
const int ma = 5003;
int c[ma][ma]{};
int a, b, q;
long long f[ma];
void init(){
	f[0] = 1;
	c[0][0] = 1;
	for (int i = 1; i < ma; i++){
		f[i] = f[i - 1] * i % mod;
		c[i][0] = 1;
	}
	for (int i = 1; i < ma; i++){
		c[i][i] = 1;
		for (int j = 1; j < i; j++){
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
		}
	}
}
int deal(int a, int b){
	int min = a;
	if (a > b)
		min = b;
	int ret = 0;
	for (int i = 0; i <= min; i++){
		ret = (((1ll * c[a][i] * c[b][i]) % mod) * f[i] % mod) + ret % mod;
	}
	return ret;
}
int main(){
	init();
	cin >> a >> b >> q;
	int x = deal(a, b), y = deal(a, q), z = deal(b,q);
	int sum = (((1ll * x * y) % mod) * z) % mod;
	cout << sum;
}