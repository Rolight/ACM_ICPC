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

#define MAX(a, b)  ((a) > (b) ? (a) : (b))
#define MIN(a, b)  ((a) < (b) ? (a) : (b)) 


using namespace std;
const int maxn = 1e3 + 10;
char mp[maxn][maxn];
int n, m, q, pd, sqn;
int f[maxn][maxn][10], presum[maxn][maxn];

inline bool scanf_(int &ret) {
    char c; int sgn;
    if (c = getchar(), c == EOF) return 0; //EOF
    while (c != '-' && (c<'0' || c>'9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}

inline void printf_(int x) {
    if (x>9) printf_(x / 10);
    putchar(x % 10 + '0');
}

inline int ask(int row, int l, int r) {
	return presum[row][r] - presum[row][l - 1];
}

inline void init() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			presum[i][j] = presum[i][j - 1] + (int)(mp[i][j] == 'X');
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			for(int d = 1; d <= 10; d++) {
				f[i][j][d] = 0;
				if(i - d > 0) f[i][j][d] += f[i - d][j][d] + 
					ask(i - d, MAX(1, j - d), MIN(m, j + d)) - 
						ask(i - d, j, j);
				if(mp[i][j] == 'X') f[i][j][d]++;
			}
		}
	}
}


inline int gao(int x, int y, int d) {
	if(d <= 10) return f[x][y][d];
	int ret = 0;
	for(int i = x, j = 0; i >= 1; i -= d, j += d) {
		ret += ask(i, max(1, y - j), min(m, y + j));
	}
	return ret;
}

int main() {
	while(scanf("%d%d%d", &n, &m, &q) != EOF) {
		for(int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
		sqn = sqrt(n + 0.5); init();
		while(q--) {
			int x, y, d;
			scanf_(x); scanf_(y); scanf_(d);
			printf_(gao(x, y, d)); putchar('\n');
		}
	}
	return 0;
}
