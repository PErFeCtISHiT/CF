#include<iostream>
#include<string>
using namespace std;
int main(){
	int a;
	string s;
	cin >> a >> s;
	int max = 0;
	for (int k = 0; k < s.length(); k++){
		for (int j = 1; j <= s.length(); j++){
			string temp = s.substr(k, j);
			int t = temp.length();
			for (int i = 0; i < temp.length() / 2; i++){
				if (temp.at(i) != temp.at(temp.length() - i - 1))
					t = temp.length() - (i + 1) * 2;
			}
			if (t > max)
				max = t;
		}
	}
	cout << max;
}