#include<iostream>
#include<string>
using namespace std;
void print(char s[100][5],string t,int len,int num,int point);
int main(){
	string s;
	cin >> s;
	int len = s.length();
	char a[10][5]{};
	for (int i = 0; i < len; i++){
		switch (s.at(i)){
		case '2':
			a[i][0] = 'a';
			a[i][1] = 'b';
			a[i][2] = 'c';
			break;
		case '3':
			a[i][0] = 'd';
			a[i][1] = 'e';
			a[i][2] = 'f';
			break;
		case '4':
			a[i][0] = 'g';
			a[i][1] = 'h';
			a[i][2] = 'i';
			break;
		case '5':
			a[i][0] = 'j';
			a[i][1] = 'k';
			a[i][2] = 'l';
			break;
		case '6':
			a[i][0] = 'm';
			a[i][1] = 'n';
			a[i][2] = 'o';
			break;
		case '7':
			a[i][0] = 'p';
			a[i][1] = 'q';
			a[i][2] = 'r';
			a[i][3] = 's';
			break;
		case '8':
			a[i][0] = 't';
			a[i][1] = 'u';
			a[i][2] = 'v';
			break;
		case '9':
			a[i][0] = 'w';
			a[i][1] = 'x';
			a[i][2] = 'y';
			a[i][3] = 'z';
			break;
		}
	}
	for (int i = 0; a[0][i] != 0;i++)
	print(a, "", len, 0, i);
}
void print(char s[10][5],string t,int len,int num,int point){
		t += s[num][point];
		if (t.length() == len){
			cout << t << endl;
		}
		for (int i = 0; s[t.length()][i] != 0; i++){
			print(s, t, len, t.length(), i);
		}
}