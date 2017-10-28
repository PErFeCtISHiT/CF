#include<iostream>
#include<string>
using namespace std;
int turn(string a);
string antiturn(long a);
int main(){
	while (true){
		string s;
		cin >> s;
		string a;
		string b;
		long y, x;
		cin >> a >> b;
		if (a.at(0) == '-'){
			x = -turn(a.substr(1));
		}
		else
			x = turn(a);
		if (b.at(0) == '-'){
			y = -turn(b.substr(1));
		}
		else
			y = turn(b);
		if (s.at(0) == 'a'){
			x += y;
			if (x >= 0)
				cout << antiturn(x);
			else{
				cout << '-' << antiturn(abs(x));
			}
		}
		else if (s.at(0) == 's'){
			x -= y;
			if (x >= 0)
				cout << antiturn(x);
			else{
				cout << '-' << antiturn(abs(x));
			}
		}
		else{
			x *= y;
			if (x >= 0)
				cout << antiturn(x);
			else{
				cout << '-' << antiturn(abs(x));
			}
		}
	}
}
int turn(string a){
	int res = 0;
	int count = 0;
	for (int i = a.length(); i > 0; i--){
		if (a.at(i - 1) == 'A'){
			int temp = 10;
			for (int j = 0; j < count; j++){
				temp *= 13;
			}
			res += temp;
		}
		else if (a.at(i - 1) == 'B'){
			int temp = 11;
			for (int j = 0; j < count; j++){
				temp *= 13;
			}
			res += temp;
		}
		else if (a.at(i - 1) == 'C'){
			int temp = 12;
			for (int j = 0; j < count; j++){
				temp *= 13;
			}
			res += temp;
		}
		else{
			int temp = a.at(i - 1) - 48;
			for (int j = 0; j < count; j++){
				temp *= 13;
			}
			res += temp;
		}
		count++;
	}
	return res;
}
string antiturn(long x){
	if (x == 0)
		return "0";
	string res = "";
	int store = -1;
	while (x > 0){
		int count = -1;
		long temp = x;
		while (temp > 0){
			temp /= 13;
			count++;
		}
		int e = 1;
		for (int i = 0; i < count; i++)
			e *= 13;
		int q = x / e;
		for (int i = 0; i < store - count - 1; i++)
			res += '0';
		if (q < 10){
			res += (char)(q + 48);
		}
		else if (q == 10)
			res += 'A';
		else if (q == 11)
			res += 'B';
		else
			res += 'C';
		x -= q * e;
		store = count;
		if (x == 0){
			for (int i = 0; i < store; i++)
				res += '0';
		}
	}
	return res;
}