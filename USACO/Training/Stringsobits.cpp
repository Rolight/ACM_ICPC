/*
ID: flsnnx1
LANG: C++
TASK: kimbits
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <iostream>

typedef long long LL;

LL N, L, I;
LL C[40][40], C1[40][40];
char out[40];

LL calc(int n, int c) {
	LL ret = 0;
	for(int i = 0; i <= c; i++) ret += C[n][i];
	return ret;
}

int main() {
	freopen("kimbits.in", "r", stdin);
	freopen("kimbits.out", "w", stdout);
	while(std::cin >> N >> L >> I) {
		C[1][0] = 1;
		C[1][1] = 1;
		for(int i = 2; i <= N; i++) {
			C[i][0] = 1;
			for(int j = 1; j <= i; j++) {
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			}
		}
		for(int i = 0; i <= N; i++) {
			for(int j = 0; j <= N; j++) {
				C1[i][j] = calc(i, j);
			}
		}
		for(int i = 1; i <= N; i++) out[i] = '0';
		while(L > 0 && I > 1) {
			int i = 1;
			while(C1[i][L] < I) i++;
			I -= C1[i - 1][L];
			out[i] = '1';
			L--; 
		}
		for(int i = N; i >= 1; i--) printf("%c", out[i]); puts("");
	}
	return 0;
}
