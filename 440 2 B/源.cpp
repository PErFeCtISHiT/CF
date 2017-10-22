#include<iostream>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	long long minn = 9223372036854775807;
	long long maxn = 9223372036854775808;
	int minptr = 0;
	long long *a = new long long[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] > maxn)
			maxn = a[i];
		if (a[i] < minn){
			minn = a[i];
			minptr = i;
		}
	}
	if (k == 1){
		cout << minn;
		return 0;
	}
	else if (k >= 3){
		cout << maxn;
		return 0;
	}
	else{
		long long *max = new long long[n + 1];
		long long res = minn;
		for (int i = 1; i < n; i++){
			long long min1 = 9223372036854775807;
			long long min2 = 9223372036854775807;
			for (int j = 0; j < i; j++){
				if (min1 > a[j])
					min1 = a[j];
			}
			for (int j = i; j < n; j++){
				if (min2 > a[j])
					min2 = a[j];
			}
			if (min1 > min2){
				max[i] = min1;
			}
			else
				max[i] = min2;
		}
		max[0] = max[n] = minn;
		for (int i = 0; i < n; i++){
			if (max[i] > res)
				res = max[i];
		}
		cout << res;
		return 0;
	}
}