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
const int maxn = 1e5 + 10;
int head[maxn], nxt[maxn << 1], v[maxn << 1];
int headQ[maxn], nxtQ[maxn << 1], vQ[maxn << 1], idQ[maxn << 1];
int dep[maxn], Qcnt, ecnt, col[maxn];
map<string, int> mp;
int mpz, n, m, fa[maxn], ans[maxn], pfa[maxn];

int getid(char *str) {
	if(mp.count(str) == 0) {
		mp[str] = ++mpz;
		return mpz;
	}
	return mp[str];
}

void init() {
	memset(head, -1, sizeof(head));
	memset(headQ, -1, sizeof(headQ));
	memset(ans, -1, sizeof(ans));
	memset(pfa, -1, sizeof(pfa));
	memset(col, 0, sizeof(col));
	mp.clear();
	mpz = Qcnt = ecnt = 0;
}

void adde(int uu, int vv) {
	v[ecnt] = vv; nxt[ecnt] = head[uu]; head[uu] = ecnt++;
}

void addQ(int uu, int vv, int id) {
	vQ[Qcnt] = vv; nxtQ[Qcnt] = headQ[uu]; idQ[Qcnt] = id; headQ[uu] = Qcnt++;
}

int getfa(int now) {
	return now == fa[now] ? now : fa[now] = getfa(fa[now]);
}

char stra[100], strb[100];

void dfs(int now, int nowdep) {
	dep[now] = nowdep; col[now] = 1;
	for(int i = headQ[now]; ~i; i = nxtQ[i]) {
		if(ans[idQ[i]] == -1 && col[vQ[i]]) {
			ans[idQ[i]] = getfa(vQ[i]);
		}
	}
	for(int i = head[now]; ~i; i = nxt[i]) {
		dfs(v[i], nowdep + 1);
		fa[v[i]] = now;
	}
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) fa[i] = i;
		for(int i = 1; i < n; i++) {
			scanf("%s%s", stra, strb);
			int a = getid(stra), b = getid(strb);
			adde(b, a);
			pfa[a] = b;
		}
		for(int i = 1; i <= m; i++) {
			scanf("%s%s", stra, strb);
			int a = getid(stra), b = getid(strb);
			addQ(a, b, i); addQ(b, a, i);
		}
		int root;
		for(int i = 1; i <= n; i++) if(pfa[i] == -1) root = i;
		dfs(root, 1);
		for(int i = 0; i < Qcnt; i += 2) {
			int uu = vQ[i ^ 1], lcadep = dep[ans[idQ[i]]];
			int ret = dep[uu] - lcadep;
			if(ans[idQ[i]] != vQ[i]) ret++;
			printf("%d\n", ret);
		}
	}
	return 0;
}
