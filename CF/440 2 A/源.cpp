#include<iostream>
using namespace std;
int main(){
	int m, n;
	int mina = 10;
	int minb = 10;
	int *ta = new int[12];
	int *tb = new int[12];
	cin >> m >> n;
	for (int i = 0; i < m; i++){
		int t;
		cin >> t;
		ta[t] = 1;
		if (t < mina)
			mina = t;
	}
	for (int j = 0; j < n; j++){
		int t;
		cin >> t;
		tb[t] = 1;
		if (t < minb)
			minb = t;
	}
	for (int i = 1; i <= 9; i++){
		if (ta[i] == tb[i] && ta[i] == 1){
			cout << i;
			return 0;
		}
	}
	if (mina > minb){
		cout << minb * 10 + mina;
		return 0;
	}
	else if(mina < minb){
		cout << mina * 10 + minb;
		return 0;
	}
}