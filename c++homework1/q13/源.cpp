#include<iostream>
using namespace std;
int main(){
	int line = 1;
	int count = 1;
	int point = 1;
	int way = 0;
	int n;
	cin >> n;
	while (count < n){
		if (point < line){
			point++;
			count++;
		}
		else{
			point = 1;
			line++;
			count++;
			if (way == 0)
				way = 1;
			else
				way = 0;
		}
	}
	if (way == 1){
		cout << point << '/' << line - point + 1;
	}
	else{
		cout << line - point + 1 << '/' << point;
	}
}