/*void show(int a[6][5][6]){
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 5; j++){
			for (int k = 0; k < 6; k++){
				cout << *(*(*(a + i) + j) + k) << endl;
			}
		}
	}
		;
}
int main(){
	typedef int q[6];
	typedef q w[5];
	typedef w e[3];
	typedef e a[2];
	a ptr;
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 3; j++){
			for (int k = 0; k < 5; k++){
				for (int u = 0; u < 6; u++){
					*(*(*(*(ptr + i) + j) + k) + u) = i * 90 + j * 30 + k * 6 + u;
				}
			}
		}
	}
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 3; j++){
			for (int k = 0; k < 5; k++){
				for (int u = 0; u < 6; u++){
					cout << a[i][j][k][u] << endl;
				}
			}
		}
	}
	show((int(*)[5][6])ptr);
}
#include<stdio.h>
#include<string.h>
int main(){
	int x, p, n;
	scanf_s("%d%d%d", &x, &p, &n);
	char s[32];
	int ptr = 31;
	int xstore = x;
	if (x == -1){
		for (int i = 0; i < 32; i++)
			s[i] = '1';
	}
	while (x != 0 && x != -1){
		if (x % 2 == 0){
			s[ptr] = '0';
			ptr--;
		}
		else{
			s[ptr] = '1';
			ptr--;
		}
		x = x >> 1;
	}
	while (ptr >= 0){
		if (xstore >= 0)
			s[ptr] = '0';
		else
			s[ptr] = '1';
		ptr--;
	}
	for (int i = 0; i < 32; i++){
		if (i % 8 == 0 && i != 0)
			printf(" ");
		printf("%c", s[i]);
	}
	x = xstore;
	printf("\n");
	int xor = 0;
	int move = 1;
	for (int i = 0; i < p; i++)
		move = move << 1;
	while (n > 0){
		xor += move;
		move = move << 1;
		n--;
	}
	x = x ^ xor;
	xstore = x;
	ptr = 31;
	if (x == -1){
		for (int i = 0; i < 32; i++)
			s[i] = '1';
	}
	while (x != 0 && x != -1){
		if (x % 2 == 0){
			s[ptr] = '0';
			ptr--;
		}
		else{
			s[ptr] = '1';
			ptr--;
		}
		x = x >> 1;
	}
	while (ptr >= 0){
		if (xstore >= 0)
			s[ptr] = '0';
		else
			s[ptr] = '1';
		ptr--;
	}
	for (int i = 0; i < 32; i++){
		if (i % 8 == 0 && i != 0)
			printf(" ");
		printf("%c", s[i]);
	}
}
//kmp
#include<iostream>
#include<string>
#pragma warning (disable : 4996)
using namespace std;
int KMP(char* T, char *P, int start, int *next);
void Next(char *P, int *next);

void Next(char *P, int *next) {
	int j = 0, k = -1;
	int lengthP;
	if (P == NULL)
		lengthP = 0;
	else
		lengthP = strlen(P);
	next[0] = -1;
	j = 1;
	while (j < lengthP) {
		k = next[j - 1];
		while (1) {
			if (k == -1 || P[j - 1] == P[k]) {
				k++;
				next[j] = k;
				j++;
				break;
			}
			else
				k = next[k];
		}
	}
}

int KMP(char *T, char *P, int start, int *next) {
	int posT = start, posP = 0;
	int lengthT = strlen(T), lengthP = strlen(P);
	while (posP < lengthP&&posT < lengthT) {
		if (posP == -1 || T[posT] == P[posP]) {
			posP++;
			posT++;
		}
		else
			posP = next[posP];
	}
	if (posP < lengthP)
		return -1;
	else {
		return posT - lengthP;
	}
}

int main() {
	char str[200] = { '\n' };
	int next[100] = { -1 };
	int start = 0;
	while (cin.getline(str, 1000, '\n')) {
		char *T = strtok(str, ",");
		char *P = strtok(NULL, ",");
		Next(P, next);
		cout << KMP(T, P, 0, next);
	}
	delete str;
	return 0;
}*/

