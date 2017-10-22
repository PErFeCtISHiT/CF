#include<iostream>
#define int long long
using namespace std;
void main(){
	int n, k, x;
	cin >> n >> k >> x;
	int *num = new int[n];
	for (int i = 0; i < n; i++)
		cin >> num[i];
	int *maxn = new int[k];
	int ptr = 0;
	int temp = 0;
	int pt = 0;
	if (k == n){//一次能解决k个，不需要规划
		cout << k * x;
		return;
	}
	for (int i = 0; ptr < k; i++){//找到最大值并且将原位置置0
		if (num[i] > temp){
			temp = num[i];
			pt = i;
		}
		if (i == n - 1){
			maxn[ptr] = temp;
			temp = 0;
			ptr++;
			i = 0;
			num[pt] = 0;
		}
	}
	int res = k * x;
	for (int i = 0; i < n; i++){
		res += num[i];
	}
	cout << res;
}