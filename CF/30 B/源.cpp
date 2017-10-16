#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	string s;
	cin >> n >> s;
	int max = 0;
	int store = 0;
	int zero[100005];
	int p = 0;
	for (int i = 0; i < n; i++){
		if (s.at(i) == '0'){
			store++;
			zero[p] = i;
			p++;
		}
	}

	cout << max;
}