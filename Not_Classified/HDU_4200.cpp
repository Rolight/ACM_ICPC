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
const int maxn = 105;
int a[maxn][maxn], n, d, row, col;
int fid[maxn], fcnt, isf[maxn];

int Gauss() {
	for(row = 0, col = 0; row < n && col < n; col++) {
		int k = row;
		while(k < n && a[k][col] == 0) k++;
		if(k >= n) continue;
		for(int i = 0; i <= n; i++) swap(a[row][i], a[k][i]);
		for(int i = 0; i < n; i++) if(i != row && a[i][col] != 0) {
			for(int j = 0; j <= n; j++) a[i][j] ^= a[row][j];
		}
		row++;
	}
	for(int i = row; i < n; i++) if(a[i][n] != 0) return -1;
	if(row < n) return 1;
	return 0;
}

void pa() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= n; j++) printf("%d ", a[i][j]);
		puts("");
	}
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &d);
		memset(a, 0, sizeof(a));
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i][n]);
		}
		for(int i = 0; i < n; i++) {
			for(int j = i - d; j <= i + d; j++) if(j >= 0 && j < n) {
				a[i][j] = 1;
			}
		}
		int ret = Gauss();
		if(ret == -1) {
			puts("impossible"); continue;
		}
		else if(ret == 0) {
			int ans = 0;
			for(int i = 0; i < n; i++) ans += a[i][n];
			printf("%d\n", ans);
			continue;
		}
		fcnt = 0;
		memset(fid, -1, sizeof(fid));
		memset(isf, 0, sizeof(isf));
		for(int i = 0; i < n; i++) {
			int nowcnt = 0;
			for(int j = 0; j < n; j++) {
				nowcnt += a[i][j];
				if(nowcnt > 1) isf[j] = 1;
			}
		}
		for(int i = 0; i < n; i++) if(isf[i]) {
			fid[i] = fcnt++;
		}
		int ans = 1e9;
		for(int s = 0; s < (1 << fcnt); s++) {
			int nowans = 0;
			for(int i = 0; i < n; i++) {
				int nowl = 0;
				for(int j = 0; j < n; j++) if(fid[j] != -1 && a[i][j]) {
					if(s & (1 << fid[j])) nowl ^= 1;
				}
				if(nowl != a[i][n]) nowans++;
			}
			int bval = 0;
			for(int i = 0; i < fcnt; i++) if(s & (1 << i)) bval++;
			ans = min(ans, nowans + bval);
		}
		printf("%d\n", ans);
	}
	return 0;
}
