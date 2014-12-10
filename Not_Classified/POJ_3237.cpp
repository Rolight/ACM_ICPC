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
const int maxn = 10000 + 5;
int n, head[maxn], nxt[maxn << 1], u[maxn << 1], v[maxn << 1], w[maxn << 1];
int tid[maxn], maxson[maxn], fa[maxn], dep[maxn], siz[maxn], idcnt, ecnt;
int top[maxn], maxv[maxn << 2], minv[maxn << 2], sval[maxn], lazy[maxn << 2];
int eid[maxn << 1], rnum[maxn];

#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r

void init() {
	memset(head, -1, sizeof(head));
	memset(maxson, -1, sizeof(maxson));
	ecnt = idcnt = 0;
}

void adde(int uu, int vv, int ww, int id) {
	u[ecnt] = uu; v[ecnt] = vv; w[ecnt] = ww; eid[ecnt] = id;
	nxt[ecnt] = head[uu]; head[uu] = ecnt++;
}

void dfs1(int now, int nowfa, int nowdep) {
	fa[now] = nowfa; dep[now] = nowdep;
	siz[now] = 1;
	for(int i = head[now]; ~i; i = nxt[i]) if(v[i] != nowfa) {
		dfs1(v[i], now, nowdep + 1);
		siz[now] += siz[v[i]];
		if(maxson[now] == -1 || siz[v[i]] > siz[maxson[now]]) {
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
	minv[rt] = min(minv[rt << 1], minv[rt << 1 | 1]);
	maxv[rt] = max(maxv[rt << 1], maxv[rt << 1 | 1]);
}

void pushdown(int rt) {
	if(lazy[rt] == 0) return;
	int lc = rt << 1, rc = rt << 1 | 1;
	lazy[lc] ^= lazy[rt]; lazy[rc] ^= lazy[rt];
	swap(minv[lc], maxv[lc]); swap(minv[rc], maxv[rc]);
	minv[lc] = -minv[lc]; minv[rc] = -minv[rc];
	maxv[lc] = -maxv[lc]; maxv[rc] = -maxv[rc];
	lazy[rt] = 0;
}

void build(int rt, int l, int r) {
	int mid = (l + r) >> 1;
	lazy[rt] = 0;
	if(l == r) {
		minv[rt] = maxv[rt] = sval[l];
	}
	else {
		build(lson); build(rson);
		pushup(rt);
	}
}

void change(int rt, int l, int r, int pos, int val) {
	if(l == r) {
		minv[rt] = maxv[rt] = val;
	}
	else {
		int mid = (l + r) >> 1;
		pushdown(rt);
		if(pos <= mid) change(lson, pos, val);
		else change(rson, pos, val);
		pushup(rt);
	}
}

void update(int rt, int l, int r, int ql, int qr) {
	if(ql <= l && qr >= r) {
		swap(minv[rt], maxv[rt]);
		minv[rt] = -minv[rt]; maxv[rt] = -maxv[rt];
		lazy[rt] ^= 1;
	}
	else {
		int mid = (l + r) >> 1;
		pushdown(rt);
		if(ql <= mid) update(lson, ql, qr);
		if(qr > mid) update(rson, ql, qr);
		pushup(rt);
	}
}

int query(int rt, int l, int r, int ql, int qr) {
	if(ql <= l && qr >= r) return maxv[rt];
	int mid = (l + r) >> 1, ret = -1e9;
	pushdown(rt);
	if(ql <= mid) ret = max(ret, query(lson, ql, qr));
	if(qr > mid) ret = max(ret, query(rson, ql, qr));
	pushup(rt);
	return ret;
}

int ask(int x, int y) {
	int ret = -1e9;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]])
			swap(x, y);
		ret = max(ret, query(1, 1, idcnt, tid[top[x]], tid[x]));
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	if(x != y) ret = max(ret, query(1, 1, idcnt, tid[x] + 1, tid[y]));
	return ret;
}

void Negate(int x, int y) {
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		update(1, 1, idcnt, tid[top[x]], tid[x]);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	if(x != y) update(1, 1, idcnt, tid[x] + 1, tid[y]);
}

void debug() {
	for(int i = 1; i <= n; i++) {
		printf("for %d top is %d tid is %d val is %d\n", 
				i, top[i], tid[i], sval[tid[i]]);
	}
	printf("the maxv: ");
	for(int i = 1; i <= n << 2; i++) printf("%d ", maxv[i]);
	puts("");
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d", &n);
		for(int i = 1; i < n; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			adde(a, b, c, i); adde(b, a, c, i);
		}
		dfs1(1, 1, 1); dfs2(1, 1);
		for(int i = 0; i < ecnt; i++) {
			if(dep[u[i]] > dep[v[i]]) {
				sval[tid[u[i]]] = w[i];
				rnum[eid[i]] = tid[u[i]];
			}
			else {
				sval[tid[v[i]]] = w[i];
				rnum[eid[i]] = tid[v[i]];
			}
		}
		build(1, 1, idcnt);
		//debug();
		char cmd[16];
		int x, y;
		while(scanf("%s", cmd)) {
			if(strcmp(cmd, "DONE") == 0) break;
			scanf("%d%d", &x, &y);
			if(cmd[0] == 'Q') {
				printf("%d\n", ask(x, y));
			}
			else if(cmd[0] == 'C') {
				change(1, 1, idcnt, rnum[x], y);
			}
			else {
				Negate(x, y);
			}
		}
	}
	return 0;
}
