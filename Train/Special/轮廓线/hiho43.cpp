#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
const int mod = 12357;
const int maxn = 129;

struct Matrix {
	int n, m, g[maxn][maxn];
	Matrix(int n, int m): n(n), m(m) {
		memset(g, 0, sizeof(g));
	}
	Matrix(int a[maxn][maxn], int n, int m): n(n), m(m) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				g[i][j] = a[i][j];
			}
		}
	}
	void print() {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				printf("%d ", g[i][j]);
			}
			puts("");
		}
	}
};

Matrix operator * (Matrix a, Matrix b) {
	Matrix ret(a.n, b.m);
	for(int i = 0; i < a.n; i++) {
		for(int j = 0; j < b.m; j++) {
			for(int k = 0; k < a.m; k++) {
				ret.g[i][j] += a.g[i][k] * b.g[k][j] % mod;
				ret.g[i][j] %= mod;
			}
		}
	}
	return ret;
}

Matrix pow(Matrix m, int n) {
	Matrix ret(m.n, m.m);
	for(int i = 0; i < m.n; i++) ret.g[i][i] = 1;
	while(n) {
		if(n & 1) ret = ret * m;
		m = m * m;
		n >>= 1;
	}
	return ret;
}

int k, n;
int A[maxn][maxn];

void dfs(int gstate, int nstate, int pos) {
	if(pos == k) {
		A[gstate][nstate] = 1;
		return;
	}
	bool g0 = gstate & (1 << pos);
	if(g0) {
		//不放
		dfs(gstate, nstate, pos + 1);
		//横放
		if(pos < k && (gstate & (1 << (pos + 1)))) 
			dfs(gstate, nstate | (1 << pos) | (1 << (pos + 1)), pos + 2);
	}
	else {
		//竖放
		dfs(gstate, nstate | (1 << pos), pos + 1);
	}
}

int main() {
	while(scanf("%d%d", &k, &n) != EOF) {
		memset(A, 0, sizeof(A));
		for(int i = 0; i < (1 << k); i++) dfs(i, 0, 0);
		Matrix a0(1, (1 << k)), a1(A, (1 << k), (1 << k));
		a0.g[0][(1 << k) - 1] = 1;
		a1 = pow(a1, n);
		a0 = a0 * a1;
		printf("%d\n", a0.g[0][(1 << k) - 1]);
	}
	return 0;
}
