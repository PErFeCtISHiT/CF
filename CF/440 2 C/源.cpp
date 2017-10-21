#include<iostream>
using namespace std;
int main(){
	int q;
	cin >> q;
	long long *a = new long long[q];
	for (int i = 0; i < q; i++){
		cin >> a[i];
		if (a[i] <= 3){
			cout << -1 << endl;
		}
		else if (a[i] == 4 || a[i] == 6)
			cout << 1 << endl;
		else if (a[i] == 5 || a[i] == 7 || a[i] == 11)
			cout << -1 << endl;
		else{
			if (a[i] % 2 == 1)
				cout << a[i] / 4 - 1 << endl;
			else
				cout << a[i] / 4 << endl;
		}
	}
}
