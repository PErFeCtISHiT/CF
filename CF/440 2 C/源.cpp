/*#include<iostream>
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
}*/
#include<stdio.h>
#include<stdlib.h>
#define maxn 10000
int main(){
	char a[maxn], b[maxn];
	scanf("%s", &a);
	scanf("%s", &b);
	int m = 0;
	for (int i = 0; a[i] != '\0'; i++){
		char x[maxn], y[maxn];
		int xptr = 0;
		int yptr = 0;
		int num = 0;
	loop:		int flag = 0;
		x[xptr] = a[xptr];
		for (int j = yptr; b[j] != '\0'; j++){
			if (b[j] == x[xptr]){
				y[yptr] = b[j];
				yptr++;
				flag = 1;
				break;
			}
		}
		if (flag == 1){
			xptr++;
			num++;
			if (a[xptr] != '\0')
				goto loop;
			else
				goto finish;
		}
		if (a[xptr] != '\0'){
			xptr++;
			if (num > m)
				m = xptr;
			goto loop;
		}
	finish:;
	}
	printf("%d", m);
}
