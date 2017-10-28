#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct student{
	string name;
	string num;
	string obj;
	double score;
};
int main(){
	int n;
	cin >> n;
	student *p = new student[n];
	for (int i = 0; i < n; i++){
		cin >> p[i].name >> p[i].num >> p[i].obj >> p[i].score;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++){
		string temp;
		cin >> temp;
		if (temp == "course"){
			string t;
			cin >> t;
			double count = 0;
			double res = 0;
			for (int j = 0; j < n; j++){
				if (p[j].obj == t){
					count++;
					res += p[j].score;
				}
			}
			res /= count;
			cout << t + " ";
			printf("%.2f\n", res);
		}
		if (temp == "student"){
			string t;
			cin >> t;
			int count = 0;
			double res = 0;
			for (int j = 0; j < n; j++){
				if (p[j].name == t){
					count++;
					res += p[j].score;
				}
			}
			res /= count;
			cout << t + " ";
			printf("%.2f\n", res);
		}
	}
}