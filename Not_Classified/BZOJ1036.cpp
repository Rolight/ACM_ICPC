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
const int maxn = 3e4 + 10;
int head[maxn], u[maxn << 1], v[maxn << 1], nxt[maxn << 1], ecnt;
int siz[maxn], maxson[maxn], top[maxn], fa[maxn], tid[maxn], idcnt;
int n, q, maxv[maxn << 2], sumv[maxn << 2], dep[maxn], sval[maxn], val[maxn];

void adde(int uu, int vv) {
	u[ecnt] = uu; v[ecnt] = vv;
	nxt[ecnt] = head[uu]; head[uu] = ecnt++;
}

void init() {
	memset(head, -1, sizeof(head));
	memset(maxson, -1, sizeof(maxson));
	idcnt = ecnt = 0;
}

void dfs1(int now, int nowfa, int nowdep) {
	dep[now] = nowdep; fa[now] = nowfa; siz[now] = 1;
	for(int i = head[now]; ~i; i = nxt[i]) if(v[i] != nowfa) {
		dfs1(v[i], now, nowdep + 1);
		siz[now] += siz[v[i]];
		if(maxson[now] == -1 || siz[maxson[now]] < siz[v[i]]) {
			maxson[now] = v[i];
		}
	}
}

void dfs2(int now, int tp) {
	tid[now] = ++idcnt;
	top[now] = tp;
	if(maxson[now] == -1) return;
	dfs2(maxson[now], tp);
	for(int i = head[now]; ~i; i = nxt[i]) {
		if(v[i] != fa[now] && v[i] != maxson[now]) {
			dfs2(v[i], v[i]);
		}
	}
}

#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r

void pushup(int rt) {
	int lc = rt << 1, rc = rt << 1 | 1;
	sumv[rt] = sumv[lc] + sumv[rc];
	maxv[rt] = max(maxv[lc], maxv[rc]);
}

void build(int rt, int l, int r) {
	int mid = (l + r) >> 1;
	if(l == r) sumv[rt] = maxv[rt] = sval[l];
	else {
		build(lson); build(rson);
		pushup(rt);
	}
}

void update(int rt, int l, int r, int pos, int Val) {
	if(l == r) maxv[rt] = sumv[rt] = Val;
	else {
		int mid = (l + r) >> 1;
		if(pos <= mid) update(lson, pos, Val);
		else update(rson, pos, Val);
		pushup(rt);
	}
}

int query_max(int rt, int l, int r, int ql, int qr) {
	if(ql <= l && qr >= r) return maxv[rt];
	int mid = l + r >> 1, ret = -1e9;
	if(ql <= mid) ret = max(ret, query_max(lson, ql, qr));
	if(qr > mid) ret = max(ret, query_max(rson, ql, qr));
	return ret;
}

int query_sum(int rt, int l, int r, int ql, int qr) {
	if(ql <= l && qr >= r) return sumv[rt];
	int mid = l + r >> 1, ret = 0;
	if(ql <= mid) ret += query_sum(lson, ql, qr);
	if(qr > mid) ret += query_sum(rson, ql, qr);
	return ret;
}

int ask_max(int x, int y) {
	int ret = -1e9;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) {
			swap(x, y);
		}
		ret = max(ret, query_max(1, 1, idcnt, tid[top[x]], tid[x]));
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	ret = max(ret, query_max(1, 1, idcnt, tid[x], tid[y]));
	return ret;
}

int ask_sum(int x, int y) {
	int ret = 0;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		ret += query_sum(1, 1, idcnt, tid[top[x]], tid[x]);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	ret += query_sum(1, 1, idcnt, tid[x], tid[y]);
	return ret;
}

int main() {
	while(scanf("%d", &n) != EOF) {
		init();
		for(int i = 1; i < n; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adde(a, b); adde(b, a);
		}
		for(int i = 1; i <= n; i++) scanf("%d", &val[i]);
		scanf("%d", &q);
		dfs1(1, 1, 1); 
		dfs2(1, 1);
		for(int i = 1; i <= n; i++) {
			sval[tid[i]] = val[i];
		}
		build(1, 1, idcnt);
		char cmd[16];
		int a, b, c;
		while(q--) {
			scanf("%s%d%d", cmd, &a, &b);
			if(strcmp("QMAX", cmd) == 0) {
				printf("%d\n", ask_max(a, b));
			}
			else if(strcmp("QSUM", cmd) == 0) {
				printf("%d\n", ask_sum(a, b));
			}
			else {
				update(1, 1, idcnt, tid[a], b);
			}
		}
	}
	return 0;
}
