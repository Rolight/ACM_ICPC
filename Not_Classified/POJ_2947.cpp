#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;
const int maxn = 400;

int a[maxn][maxn], n, m, ans[maxn], fans[maxn], anscnt;
char t1[1024], t2[1024];

int mp(char *s) {
	if(strcmp(s,"MON")==0)
		return 1;
	else if(strcmp(s,"TUE")==0)
		return 2;
	else if(strcmp(s,"WED")==0)
		return 3;
	else if(strcmp(s,"THU")==0)
		return 4;
	else if(strcmp(s,"FRI")==0)
		return 5;
	else if(strcmp(s,"SAT")==0)
		return 6;
	else return 7;
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int getmod(int x) {
	return (x % 7 + 7) % 7;
}

//-1表示无解，0表示有唯一解，1表示有多解
int Gauss() {
	int row, col;
	for(row = 0, col = 0; row < m && col < n; col++) {
		int k = row;
		while(a[k][col] == 0 && k < m) k++;
		if(k >= m) continue;
		for(int i = 0; i <= n; i++) swap(a[row][i], a[k][i]);
		for(int i = 0; i < m; i++) if(i != row && a[i][col] != 0) {
			int lc = lcm(abs(a[row][col]), abs(a[i][col]));
			int c1 = lc / a[row][col], c2 = lc / a[i][col];
			for(int j = 0; j <= n; j++) {
				a[i][j] = getmod(a[i][j] * c2 - a[row][j] * c1);
			}
		}
		row++;
	}
	//无解
	for(int i = row; i < m; i++) if(a[i][n]) return -1;
	//无穷多解
	if(row < n) return 1;
	//唯一解
	for(int i = row - 1; i >= 0; i--) {
		int right = a[i][n], left = a[i][i];
		for(int j = i + 1; j < n; j++) {
			right = getmod(right - a[i][j] * ans[j]);
		}
		while(right % left != 0) right += 7;
		ans[i] = right / left % 7;
		if(ans[i] < 3) ans[i] += 7;
	}
	return 0;
}


void pa() {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j <= n; j++) {
			printf("%d ", a[i][j]);
		}
		puts("");
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	while(scanf("%d%d", &n, &m) != EOF) {
		if(n == 0 && m == 0) break;
		int k, tmp;
		anscnt = 0;
		memset(a, 0, sizeof(a));
		for(int i = 0; i < m; i++) {
			scanf("%d%s%s", &k, t1, t2);
			a[i][n] = getmod(mp(t2) - mp(t1) + 1);
			for(int j = 0; j < k; j++) {
				scanf("%d", &tmp);
				a[i][tmp - 1] = getmod(a[i][tmp - 1] + 1);
			}
		}
		int ret = Gauss();
		if(ret == -1) puts("Inconsistent data.");
		else if(ret == 1) puts("Multiple solutions.");
		else {
			for(int i = 0; i < n; i++) printf("%d ", ans[i]);
			puts("");
		}
	}
	return 0;
}
