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

#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r

const int maxn = 1e5 + 10;
int head[maxn], nxt[maxn << 1], u[maxn << 1], v[maxn << 1];
int tid[maxn], maxson[maxn], siz[maxn], top[maxn], idcnt, ecnt;
int lcnt[maxn << 2], lbdc[maxn << 2], rbdc[maxn << 2], lazy[maxn << 2];
int n, m, scol[maxn], sval[maxn], dep[maxn], fa[maxn];

void init() {
	memset(head, -1, sizeof(head));
	memset(maxson, -1, sizeof(maxson));
	idcnt = ecnt = 0;
}

void adde(int uu, int vv) {
	u[ecnt] = uu; v[ecnt] = vv;
	nxt[ecnt] = head[uu]; head[uu] = ecnt++;
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
	top[now] = tp;
	tid[now] = ++idcnt;
	if(maxson[now] == -1) return;
	dfs2(maxson[now], tp);
	for(int i = head[now]; ~i; i = nxt[i]) {
		if(v[i] != fa[now] && v[i] != maxson[now]) {
			dfs2(v[i], v[i]);
		}
	}
}

void pushup(int rt) {
	int lc = rt << 1, rc = rt << 1 | 1;
	lcnt[rt] = lcnt[lc] + lcnt[rc];
	lbdc[rt] = lbdc[lc]; rbdc[rt] = rbdc[rc];
	if(rbdc[lc] == lbdc[rc]) lcnt[rt]--;
}

void fill(int rt, int Col) {
	lazy[rt] = Col;
	lcnt[rt] = 1;
	lbdc[rt] = rbdc[rt] = Col;
}

void pushdown(int rt) {
	if(lazy[rt] == -1) return;
	int lc = rt << 1, rc = rt << 1 | 1;
	fill(lc, lazy[rt]); fill(rc, lazy[rt]);
	lazy[rt] = -1;
}

void build(int rt, int l, int r) {
	lazy[rt] = -1;
	if(l == r) {
		lcnt[rt] = 1;
		lbdc[rt] = rbdc[rt] = sval[l];
	}
	else {
		int mid = (l + r) >> 1;
		build(lson); build(rson);
		pushup(rt);
	}
}

void update(int rt, int l, int r, int ql, int qr, int Col) {
	if(ql <= l && qr >= r) fill(rt, Col);
	else {
		int mid = (l + r) >> 1;
		pushdown(rt);
		if(ql <= mid) update(lson, ql, qr, Col);
		if(qr > mid) update(rson, ql, qr, Col);
		pushup(rt);
	}
}

int query(int rt, int l, int r, int ql, int qr) {
	if(ql <= l && qr >= r) return lcnt[rt];
	else {
		pushdown(rt);
		int mid = (l + r) >> 1, ret = 0, lc = rt << 1, rc = rt << 1 | 1;
		if(ql <= mid) ret += query(lson, ql, qr);
		if(qr > mid) ret += query(rson, ql, qr);
		if(ql <= mid && qr > mid && lbdc[rc] == rbdc[lc]) {
			ret--;
		}
		pushup(rt);
		return ret;
	}
}

int query_Col(int rt, int l, int r ,int pos) {
	if(l == r) return lbdc[rt];
	pushdown(rt);
	int mid = (l + r) >> 1, ret;
	if(pos <= mid) ret = query_Col(lson, pos);
	else ret = query_Col(rson, pos);
	pushup(rt);
	return ret;
}

int ask(int x, int y) {
	int ret = 0;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		ret += query(1, 1, idcnt, tid[top[x]], tid[x]);
		int ca = query_Col(1, 1, idcnt, tid[top[x]]), 
			cb = query_Col(1, 1, idcnt, tid[fa[top[x]]]);
		if(ca == cb) ret--;
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	ret += query(1, 1, idcnt, tid[x], tid[y]);
	return ret;
}

void change(int x, int y, int Col) {
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		update(1, 1, idcnt, tid[top[x]], tid[x], Col);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	update(1, 1, idcnt, tid[x], tid[y], Col);
}


int main() {
	while(scanf("%d%d", &n, &m) != EOF) {
		init();
		for(int i = 1; i <= n; i++) scanf("%d", &scol[i]);
		for(int i = 1; i < n; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adde(a, b); adde(b, a);
		}
		dfs1(1, 1, 1); dfs2(1, 1);
		for(int i = 1; i <= n; i++) sval[tid[i]] = scol[i];
		build(1, 1, idcnt);
		char cmd[10]; int a, b, c;
		for(int i = 1; i <= m; i++) {
			scanf("%s", cmd);
			if(cmd[0] == 'C') {
				scanf("%d%d%d", &a, &b, &c);
				change(a, b, c);
			}
			else {
				scanf("%d%d", &a, &b);
				printf("%d\n", ask(a, b));
			}
		}
	}
	return 0;

}
