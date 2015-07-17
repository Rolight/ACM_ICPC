/*
ID: flsnnx1
LANG: C++
TASK: ratios
*/

#include <cstdio>
#include <algorithm>

typedef long long LL;

void setIO() {
	freopen("ratios.in", "r", stdin);
	freopen("ratios.out", "w", stdout);
}

int calc(int a[4], int b[4], int c[4]) {
	return a[1] * (b[2] * c[3] - c[2] * b[3]) - 
		b[1] * (a[2] * c[3] - a[3] * c[2]) +
		c[1] * (a[2] * b[3] - b[2] * a[3]);
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	setIO();
	int dp[4][4], d[4];
	for(int i = 1; i <= 3; i++) scanf("%d", &d[i]);
	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= 3; j++) {
			scanf("%d", &dp[i][j]);
		}
	}
	int d1 = calc(d, dp[2], dp[3]),
		d2 = calc(dp[1], d, dp[3]),
		d3 = calc(dp[1], dp[2], d),
		dd = calc(dp[1], dp[2], dp[3]);
	if(dd == 0 || (LL)d1 * dd < 0 || (LL)d2 * dd < 0 || (LL)d3 * dd < 0) puts("NONE");
	else {
		int lc = gcd(d1, gcd(d2, gcd(d3, dd)));
		d1 /= lc; d2 /= lc; d3 /= lc; dd /= lc;
		printf("%d %d %d %d\n", d1, d2, d3, dd);
	}
	return 0;
}
