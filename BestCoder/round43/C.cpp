#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <ctime>
#include <cstdlib>

typedef long long LL;

struct Node {
	int dep, id;
	bool operator < (const Node &node) const {
		return dep < node.dep;
	}
};

const int maxn = 3e5 + 10;
int n, q;

//LCA部分

Node val[maxn << 1], minv[maxn << 1][20];
int head[maxn], nxt[maxn << 1], v[maxn << 1], cnt, ecnt, rpos[maxn];

void adde(int uu, int vv) {
	v[ecnt] = vv; nxt[ecnt] = head[uu]; head[uu] = ecnt++;
}

void dfs(int now, int fa, int dep) {
	val[++cnt].dep = dep; val[cnt].id = now;
	for(int i = head[now]; ~i; i = nxt[i]) if(v[i] != fa) {
		dfs(v[i], now, dep + 1);
		val[++cnt].dep = dep; val[cnt].id = now;
	}
	rpos[now] = cnt;
}

void initrmq() {
	for(int i = 1; i <= cnt; i++) {
		minv[i][0] = val[i];
	}
	for(int j = 1; (1 << j) <= cnt; j++) {
		for(int i = 1; i + (1 << j) - 1 <= cnt; i++) {
			minv[i][j] = std::min(minv[i][j - 1], minv[i + (1 << (j - 1))][j - 1]);
		}
	}
}

Node query(int l, int r) {
	int k = 0;
	while((1 << (k + 1)) <= r - l + 1) k++;
	return std::min(minv[l][k], minv[r - (1 << k) + 1][k]);
}

//线段树部分
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r

int lca[maxn << 2];

inline void pushup(int rt) {
	int lc = rt << 1, rc = rt << 1 | 1;
	int a = rpos[lca[lc]], b = rpos[lca[rc]];
	if(a > b) std::swap(a, b);
	lca[rt] = query(a, b).id;
}

void build(int rt, int l, int r) {
	if(l == r) lca[rt] = l;
	else {
		int mid = l + r >> 1;
		build(lson); build(rson);
		pushup(rt);
	}
}

int query_s(int rt, int l, int r, int ql, int qr) {
	if(ql <= l && qr >= r) return lca[rt];
	int mid = (l + r) >> 1, lval = -1, rval = -1;
	if(ql <= mid) lval = query_s(lson, ql, qr);
	if(qr > mid) rval = query_s(rson, ql, qr);
	if(lval == -1) return rval;
	else if(rval == -1) return lval;
	else {
		int a = rpos[lval], b = rpos[rval];
		if(a > b) std::swap(a, b);
		return query(a, b).id;
	}
}

int main() {
	while(scanf("%d", &n) != EOF) {
		memset(head, -1, sizeof(head));
		cnt = ecnt = 0;
		int a, b;
		for(int i = 1; i < n; i++) {
			scanf("%d%d", &a, &b);
			adde(a, b); adde(b, a);
		}
		dfs(1, -1, 0);
		initrmq();
		build(1, 1, n);
		scanf("%d", &q);
		int l, r;
		while(q--) {
			scanf("%d%d", &l, &r);
			printf("%d\n", query_s(1, 1, n, l, r));
		}
	}
	return 0;
}
