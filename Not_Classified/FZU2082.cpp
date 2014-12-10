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

#define lson rt << 1, l, mid
#define rson rt << 1 | 1 , mid + 1, r

using namespace std;
typedef long long LL;
const int maxn = 5e4 + 10; 
int head[maxn], nxt[maxn << 1], u[maxn << 1], v[maxn << 1], w[maxn << 1];
int son[maxn], top[maxn], dep[maxn], fa[maxn], siz[maxn], tid[maxn];
int sval[maxn], eid[maxn], rnum[maxn];
LL sumv[maxn << 2];
int n, m, ecnt, idcnt;

void init() {
	memset(head, -1, sizeof(head));
	memset(son, -1, sizeof(son));
	idcnt = ecnt = 0;
}

void adde(int uu, int vv, int ww, int id) {
	u[ecnt] = uu; v[ecnt] = vv; w[ecnt] = ww;
	eid[ecnt] = id; nxt[ecnt] = head[uu];
	head[uu] = ecnt++;
}

void dfs1(int now, int nowfa, int nowdep) {
	dep[now] = nowdep; fa[now] = nowfa; siz[now] = 1;
	for(int i = head[now]; ~i; i = nxt[i]) if(v[i] != nowfa) {
		dfs1(v[i], now, nowdep + 1);
		siz[now] += siz[v[i]];
		if(son[now] == -1 || siz[son[now]] < siz[v[i]]) son[now] = v[i];
	}
}

void dfs2(int now, int tp) {
	tid[now] = ++idcnt;
	top[now] = tp;
	if(son[now] == -1) return;
	dfs2(son[now], tp);
	for(int i = head[now]; ~i; i = nxt[i]) {
		if(v[i] != fa[now] && v[i] != son[now]) {
			dfs2(v[i], v[i]);
		}
	}
}

int pushup(int rt) {
	sumv[rt] = sumv[rt << 1] + sumv[rt << 1 | 1];
}

void build(int rt, int l, int r) {
	int mid = l + r >> 1;
	if(l == r) sumv[rt] = sval[l];
	else {
		build(lson); build(rson);
		pushup(rt);
	}
} 

void update(int rt, int l, int r, int pos, int val) {
	if(l == r) sumv[rt] = val;
	else {
		int mid = l + r >> 1;
		if(pos <= mid) update(lson, pos, val);
		else update(rson, pos, val);
		pushup(rt);
	}
}

LL query(int rt, int l, int r, int ql, int qr) {
	if(ql <= l && qr >= r) return sumv[rt];
	else {
		int mid = l + r >> 1;
		LL ret = 0;
		if(ql <= mid) ret += query(lson, ql, qr);
		if(qr > mid) ret += query(rson, ql, qr);
		return ret;
	}
}

LL ask(int x, int y) {
	LL ret = 0;
	while(top[x] != top[y]) {
		//printf("now x is %d, now y is %d\n", x, y);
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		ret += query(1, 1, n, tid[top[x]], tid[x]);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	if(x != y) ret += query(1, 1, n, tid[x] + 1, tid[y]);
	return ret;
}

void debug() {
	for(int i = 1; i <= n; i++) {
		printf("%d top is %d tid is %d\n", i, top[i], tid[i]);
	}
}

int main() {
	while(scanf("%d%d", &n, &m) != EOF) {
		init();
		for(int i = 1; i < n; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			adde(a, b, c, i); adde(b, a, c, i);
		}
		dfs1(1, 1, 1); dfs2(1, 1);
		for(int i = 0; i < ecnt; i++) {
			if(dep[u[i]] > dep[v[i]]) {
				sval[tid[u[i]]] = w[i];
				rnum[eid[i]] = u[i];
			}
			else {
				sval[tid[v[i]]] = w[i];
				rnum[eid[i]] = v[i];
			}
		}
		build(1, 1, n);
		int cmd, a, b;
		while(m--) {
			scanf("%d%d%d", &cmd, &a, &b);
			if(cmd == 0) update(1, 1, n, tid[rnum[a]], b);
			else printf("%I64d\n", ask(a, b));
		}
	}
	return 0;
}
