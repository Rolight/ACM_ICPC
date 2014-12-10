#include <cstdio>
#include <cstring>
#include <algorithm>

#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r

using namespace std;

const int maxn = 1e4 + 10;

int head[maxn], nxt[maxn << 1], w[maxn << 1], v[maxn << 1], ecnt;
int N, tcnt, from[maxn], to[maxn], tid[maxn], w1[maxn];
int son[maxn], siz[maxn], fa[maxn], top[maxn], dep[maxn];
int maxv[maxn << 2], val[maxn];

void init() {
	memset(head, -1, sizeof(head));
	ecnt = tcnt = 0;
}

void add_edge(int uu, int vv, int ww) {
	v[ecnt] = vv; w[ecnt] = ww; nxt[ecnt] = head[uu]; head[uu] = ecnt++;
}

void dfs1(int now, int f, int now_dep) {
	dep[now] = now_dep; fa[now] = f; siz[now] = 1; son[now] = -1;
	for (int i = head[now]; ~i; i = nxt[i]) if(now != f) {
		dfs1(v[i], now, now_dep + 1);
		siz[now] += siz[v[i]];
		if (son[now] == -1 || siz[v[i]] > siz[son[now]]) {
			son[now] = v[i];
		}
	}
}

void dfs2(int now, int tp) {
	top[now] = tp; tid[now] = ++tcnt;
	if (son[now] == -1) return;
	dfs2(son[now], tp);
	for (int i = head[now]; ~i; i = nxt[i]) {
		if (i == fa[now] || i == son[now]) continue;
		dfs2(v[i], v[i]);
	}
}

//线段树

void pushup(int rt) {
	maxv[rt] = max(maxv[rt << 1], maxv[rt << 1 | 1]);
}

void build(int rt, int l, int r) {
	int mid = l + r >> 1;
	if (l == r) val[l];
	else {
		build(lson); build(rson);
		pushup(rt);
	}
}

void update(int rt, int l, int r, int pos, int Val) {
	if (l == r) maxv[pos] = Val;
	else {
		int mid = l + r >> 1;
		if (pos <= mid) update(lson, pos, Val);
		else update(rson, pos, Val);
		pushup(rt);
	}
}

int query(int rt, int l, int r, int ql, int qr) {
	if (ql <= l && qr >= r) return maxv[rt];
	int mid = l + r >> 1, ret = -1e9;
	if (ql <= mid) ret = max(ret, query(lson, ql, qr));
	if (qr > mid) ret = max(ret, query(rson, ql, qr));
	return ret;
}

int ask(int x, int y) {
	int ret = -1e9;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		ret = max(ret, query(1, 1, N, tid[top[x]], tid[x]));
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	ret = max(ret, query(1, 1, N, tid[x], tid[y]));
	return ret;
}

int main() {
	while (scanf("%d", &N) != EOF) {
		init();
		for (int i = 1; i < N; i++) {
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			add_edge(a, b, c); add_edge(b, a, c);
			from[i] = a; to[i] = b; w1[i] = c;
		}
		dfs1(1, 1, 1); dfs2(1, 1);
		for (int i = 1; i < N; i++) {
			if (fa[from[i]] == to[i]) val[tid[from[i]]] = w1[i];
			else val[tid[to[i]]] = w1[i];
		}
		build(1, 1, N);
		char cmd[32]; int x, y;
		while (scanf("%s", cmd), strcmp(cmd, "DONE") != 0) {
			scanf("%d%d", &x, &y);
			if (cmd[0] == 'Q') printf("%d\n", ask(x, y));
			else update(1, 2, N, tid[x], y);
		}
	}
	return 0;
}
