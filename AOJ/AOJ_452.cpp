#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 10;

typedef unsigned long long LL;

int mp[maxn][maxn], n, m, ans, anscnt;

inline int u(int x, int y) {
	return (x - 1) * m + y - 1;
}

LL setState(int x, int y, LL state) {
	state &= ~(1LL << u(x, y));
	if (x - 1 >= 1) state &= ~(1LL << u(x - 1, y));
	if (x + 1 <= n) state &= ~(1LL << u(x + 1, y));
	if (y - 1 >= 1) state &= ~(1LL << u(x, y - 1));
	if (y + 1 <= m) state &= ~(1LL << u(x, y + 1));
	return state;
}

int bitcount(LL x) {
	return x == 0 ? 0 : (x & 1) + bitcount(x >> 1);
}


void printState(LL state) {
	printf("the  State is :\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", (bool)((1LL << u(i, j)) & state));
		}
		puts("");
	}
}

/*
void dfs(int x, int y, int cnt, LL state) {
	//printf("now is %d %d %d st: %I64d\n", x, y, cnt, state);
	//printState(state);
	//system("pause");
	if (cnt > 12) return;
	if (state == 0) {
		if (cnt < ans) {
			ans = cnt; anscnt = 0;
		}
		anscnt++;
		//printf("get an ans %d\n", cnt);
		return;
	}
	if (!(x >= 1 && x <= n && y >= 1 && y <= m)) {
		return;
	}
	if (cnt >= ans) return;
	LL nxtState;
	if ((nxtState = setState(x, y, state)) != state) {
		dfs(x + 2, y, cnt + 1, nxtState);
		dfs(x - 2, y, cnt + 1, nxtState);
		dfs(x, y + 2, cnt + 1, nxtState);
		dfs(x, y - 2, cnt + 1, nxtState);

		dfs(x + 1, y + 1, cnt + 1, nxtState);
		dfs(x + 1, y - 1, cnt + 1, nxtState);
		dfs(x - 1, y + 1, cnt + 1, nxtState);
		dfs(x - 1, y - 1, cnt + 1, nxtState);

	}
}
*/



void dfs(int x, int y, int cnt, LL state) {
	/*
	printf("now is %d %d %d %I64d\n", x, y, cnt, state);
	printState(state);
	system("pause");
	*/
	if (state == 0) {
		if (cnt < ans) {
			ans = cnt; anscnt = 0;
		}
		if (cnt == ans) anscnt++;
		return;
	}
	if (cnt >= ans) return;
	int cc[maxn * maxn];
	memset(cc, 0, sizeof(cc));
	LL st[maxn * maxn];
	int bnow = bitcount(state);
	int mx = 1, my = 1, mx1 = 1, my1 = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x = u(i, j);
			st[x] = setState(i, j, state);
			cc[x] = bnow - bitcount(st[x]);
			if (cc[x] > cc[u(mx, my)]) {
				mx1 = mx; my1 = my;
				mx = i; my = j;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) if (cc[u(i, j)] == cc[u(mx, my)] || cc[u(i, j)] == cc[u(mx1, my1)]) {
			if (cc[u(i, j)] == 0) continue;
			dfs(i, j, cnt + 1, st[u(i, j)]);
		}
	}
}


int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		LL str = 0;
		anscnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &mp[i][j]);
				str |= (LL)mp[i][j] << u(i, j);
			}
		}
		ans = 12;
		dfs(1, 1, 0, str);
		printf("%d\n", ans);
	}
	return 0;
}