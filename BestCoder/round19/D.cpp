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

#define lson rt, l, mid
#define rson rt << 1, mid + 1, r

using namespace std;
const int maxn = 1e5 + 10;

struct Tree {
	int top[maxn], siz[maxn], son[maxn], fa[maxn];
	int head[maxn], nxt[maxn], v[maxn], tcnt, ecnt;
	int val[maxn], n, sum[maxn << 2], tid[maxn], dep[maxn];

	inline void read() {
		ecnt = tcnt = 0;
		memset(head, -1, sizeof(head));
		memset(son, -1, sizeof(son));
		for(int i = 2; i <= n; i++) {
			scanf("%d",  &fa[i]);
			v[ecnt] = i; nxt[ecnt] = head[fa[i]];
			head[fa[i]] = ecnt++;
		}
		for(int i = 1; i <= n; i++) scanf("%d", &val[i]);
	}

	void dfs1(int now, int nowdep) {
		dep[now] = nowdep; siz[now] = 1;
		for(int i = head[now]; ~i; i = nxt[i]) {
			dfs1(v[i]);
			if(son[now] == -1 || siz[son[now]] < siz[v[i]]) {
				son[now] = v[i];
			}
		}
	}

	void dfs2(int now, int tp) {
		top[now] = tp;
		tid[now] = ++tcnt;
		if(son[now] == -1) return;
		dfs2(son[now], tp);
		for(int i = head[now]; ~i; i = nxt[i]) if(v[i] != son[now]) {
			dfs2(v[i], v[i]);
		}
	}

	inline void init() {
		dfs1(1, 1); dfs2(1, 1);
	}


	inline void pushup(int rt) {
		sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	}

	void build(int rt, int l, int r) {
		int mid = (l + r) >> 1;
		if(l == r) sum[rt] = val[l];
		else {
			build(lson); build(rson);
			pushup(rt);
		}
	}

	int query(int rt, int l, int r, int ql, int qr) {
		if(ql <= l && qr >= r) return sum[rt];
		int mid = (l + r) >> 1, ret = 0;
		if(ql <= mid) ret += query(lson, ql, qr);
		if(qr > mid) ret += query(rson, ql, qr);
		return ret;
	}

	int ask(int u, int v) {
		int ret = 0;
		while(top[u] != top[v]) {
			if(dep[top[u]] < dep[top[v]]) swap(u, v);
			ret += query(1, 1, n, top[u], u);
			u = fa[top[u]];
		}
		while(dep[u] > dep[v]) swap(u, v);
		ret += query(1, 1, n, u, v);
		return ret;
	}
};

Tree t1, t2;
int n;

int main() {
	int __size__ = 256 << 20;
    char * __p__ = (char *)malloc(__size__) + __size__;
    __asm__("movl %0,%%esp\n"::"r"(__p__));
	while(scanf("%d", &n) != EOF) {
		t1.read();
		scanf("%d", &t2.n);
		t2.read();
		t1.init(); t2.init();
		Tree *tree1, *tree2;
		if(t1. n > t2.n) {
			tree1 = &t1; tree2 = &t2;
		}
		else {
			tree1 = &t2; tree2 = &t1;
		}
		for(int i = 1; i <= tree2->n; i++) {
			if(tree1->val[i] == tree2->val[i]) {
				tree1->val[i] = 1; tree2->val[i] = 0;
			}
			else {
				tree1->val[i] = tree2->val[i] = 0;
			}
		}
		for(int i = tree2->n + 1; i <= tree1->n; i++) {
			tree1->val[i] = 1;
		}
		tree1->build(1, 1, tree1->n);
		tree2->build(1, 1, tree2->n);
		int Q; scanf("%d", &Q);
		while(Q--) {
			int u1, v1, u2, v2;
		}
	}
	return 0;
}
