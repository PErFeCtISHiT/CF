#include<iostream>
#include<string>
using namespace std;
int main(){
	int m;
	cin >> m;
	string s = "";
	for (int i = 0; i < m; i++){
		string cmd;
		cin >> cmd;
		if (cmd == "append"){
			string temp;
			cin >> temp;
			s += temp;
		}
		else if (cmd == "replace"){
			string a, b;
			cin >> a >> b;
			for (int i = 0; i <= s.length() - b.length(); i++){
				string temp = s.substr(i, a.length());
				if (temp == a){
					s = s.substr(0, i) + b + s.substr(i + a.length(), s.length() - i - b.length());
					i += b.length() - 1;
				}
			}
		}
		else if (cmd == "reverse"){
			for (int i = 0; i < s.length() / 2; i++){
				char temp = s.at(i);
				s.at(i) = s.at(s.length() - i - 1);
				s.at(s.length() - i - 1) = temp;
			}
		}
		else if (cmd == "changecase"){
			string temp;
			cin >> temp;
			if (temp == "up"){
				for (int i = 0; i < s.length(); i++){
					if (s.at(i) >= 'a' && s.at(i) <= 'z')
						s.at(i) = s.at(i) - 32;
				}
			}
			else{
				for (int i = 0; i < s.length(); i++){
					if (s.at(i) >= 'A' && s.at(i) <= 'Z')
						s.at(i) = s.at(i) + 32;
				}
			}
		}
		else if (cmd == "length"){
			cout << s.length() << endl;
		}
		else{
			for (int i = 0; i < s.length(); i++)
				cout << s.at(i);
			cout << endl;
		}
	}
}