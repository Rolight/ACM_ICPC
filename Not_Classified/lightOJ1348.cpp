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
const int maxn = 3e4 + 20;
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
int head[maxn], nxt[maxn << 1], v[maxn << 1];
int val[maxn], sval[maxn], n, m, ecnt, idcnt;
int son[maxn], siz[maxn], top[maxn], dep[maxn], fa[maxn], tid[maxn];
int sumv[maxn << 2];
 
void init() {
	memset(head, -1, sizeof(head));
	memset(son, -1, sizeof(son));
	idcnt = ecnt = 0;
}

void dfs1(int now, int nowfa, int nowdep) {
	fa[now] = nowfa; dep[now] = nowdep; siz[now] = 1;
	for(int i = head[now]; ~i; i = nxt[i]) if(v[i] != nowfa) {
		dfs1(v[i], now, nowdep + 1);
		siz[now] += siz[v[i]];
		if(son[now] == -1 || siz[son[now]] < siz[v[i]]) son[now] = v[i];
	}
}

void dfs2(int now, int tp) {
	tid[now] = ++idcnt; top[now] = tp;
	if(son[now] == -1) return;
	dfs2(son[now], tp);
	for(int i = head[now]; ~i; i = nxt[i]) {
		if(v[i] != fa[now] && v[i] != son[now]) {
			dfs2(v[i], v[i]);
		}
	}
}

void adde(int uu, int vv) {
	v[ecnt] = vv; nxt[ecnt] = head[uu]; head[uu] = ecnt++;
}

void pushup(int rt) {
	sumv[rt] = sumv[rt << 1] + sumv[rt << 1 | 1];
}

void build(int rt, int l, int r) { 
	if(l == r) sumv[rt] = sval[l];
	else {
		int mid = (l + r) >> 1;
		build(lson); build(rson);
		pushup(rt);
	}
}

void update(int rt, int l, int r, int pos, int Val) {
	if(l == r) sumv[rt] = Val;
	else {
		int mid = l + r >> 1;
		if(pos <= mid) update(lson, pos, Val);
		else update(rson, pos, Val);
		pushup(rt);
	}
}

int query(int rt, int l, int r, int ql, int qr) {
	if(ql <= l && qr >= r) return sumv[rt];
	int mid = (l + r) >> 1, ret = 0;
	if(ql <= mid) ret += query(lson, ql, qr);
	if(qr > mid) ret += query(rson, ql, qr);
	return ret;
}

int ask(int x, int y) {
	int ret = 0;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		ret += query(1, 1, n, tid[top[x]], tid[x]);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	ret += query(1, 1, n, tid[x], tid[y]);
	return ret;
}

int main() {
	int T, kase = 1; scanf("%d", &T);
	while(T--) {
		printf("Case %d:\n", kase++);
		init();
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &val[i]);
		for(int i = 1; i < n; i++) {
			int a, b; scanf("%d%d", &a, &b);
			a++; b++;
			adde(a, b); adde(b, a);
		}
		dfs1(1, 1, 1); dfs2(1, 1);
		for(int i = 1; i <= n; i++) sval[tid[i]] = val[i];
		build(1, 1, n);
		scanf("%d", &m);
		while(m--) {
			int cmd, a, b; 
			scanf("%d%d%d", &cmd, &a, &b);
			if(cmd == 0) printf("%d\n", ask(a + 1, b + 1));
			else {
				update(1, 1, n, tid[a + 1], b);
			}
		}
	}
	return 0;
}
