#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	int n, m;
	cin >> n;
	double *x = new double[n];
	for (int i = 0; i < n; i++){
		cin >> x[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++){
		string s;
		cin >> s;
		if (s.at(0) == 'a'){
			double t;
			cin >> t;
			for (int i = 0; i < n; i++)
				x[i] += t;
		}
		else if (s.at(2) == 'b'){
			double t;
			cin >> t;
			for (int i = 0; i < n; i++){
				x[i] -= t;
			}
		}
		else if (s.at(0) == 'm'){
			double t;
			cin >> t;
			for (int i = 0; i < n; i++){
				x[i] *= t;
			}
		}
		else if (s.at(2) == 'w'){
			int t;
			cin >> t;
			for (int i = 0; i < n; i++){
				x[i] = pow(x[i], t);
			}
		}
		else if (s.at(2) == 'a'){
			double t = 0;
			for (int i = 0; i < n; i++){
				t += x[i] * x[i];
			}
			cout << t;
		}
		else{
			cout << ' ';
			for (int i = 0; i < n; i++){
				cout << x[i] << ' ';
			}
		}
	}
}