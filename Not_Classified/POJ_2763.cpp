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
int head[maxn], nxt[maxn << 1], u[maxn << 1], v[maxn << 1], w[maxn << 1];
int siz[maxn], top[maxn], maxson[maxn], dep[maxn], eid[maxn << 1];
int tid[maxn], fa[maxn], sumv[maxn << 2], idcnt, sval[maxn];
int n, q, s, ecnt, rnum[maxn];

void init() {
	memset(head, -1, sizeof(head));
	memset(maxson, -1, sizeof(maxson));
	ecnt = idcnt = 0;
}

void adde(int uu, int vv, int ww, int id) {
	u[ecnt] = uu; v[ecnt] = vv; w[ecnt] = ww; 
	eid[ecnt] = id;	nxt[ecnt] = head[uu]; head[uu] = ecnt++;
}

//第一遍dfs，用于统计节点信息
void dfs1(int now, int nowfa, int nowdep) {
	dep[now] = nowdep; fa[now] = nowfa; siz[now] = 1;
	for(int i = head[now]; ~i; i = nxt[i]) if(v[i] != nowfa) {
		dfs1(v[i], now, nowdep + 1);
		siz[now] += siz[v[i]];
		if(maxson[now] == -1 || siz[v[i]] > siz[maxson[now]]) {
			maxson[now] = v[i];
		}
	} 
}

//第二遍dfs， 划分链
void dfs2(int now, int tp) {
	top[now] = tp; tid[now] = ++idcnt;
	//遇到叶子节点就返回
	if(maxson[now] == -1) return;
	//重链直接dfs下去
	dfs2(maxson[now], tp);
	for(int i = head[now]; ~i; i = nxt[i]) if(v[i] != fa[now]) {
		//剩下的每一个节点都自己成为一条链
		if(v[i] != maxson[now]) dfs2(v[i], v[i]);
	}
}

//线段树操作

void pushup(int rt) {
	sumv[rt] = sumv[rt << 1] + sumv[rt << 1 | 1];
}

void build(int rt, int l, int r) {
	int mid = (l + r) >> 1;
	if(l == r) sumv[rt] = sval[l];
	else {
		build(lson); build(rson);
		pushup(rt);
	}
}

void update(int rt, int l, int r, int pos, int val) {
	if(l == r) sumv[rt] = val;
	else {
		int mid = (l + r) >> 1;
		if(pos <= mid) update(lson, pos, val);
		else update(rson, pos, val);
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
//		printf("%d %d %d %d\n", x, y, top[x], top[y]);
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		ret += query(1, 1, idcnt, tid[top[x]], tid[x]);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	if(x != y) ret += query(1, 1, n, tid[x] + 1, tid[y]);
	return ret;
}

int main() {
	while(scanf("%d%d%d", &n, &q, &s) != EOF) {
		init();
		for(int i = 1; i < n; i++) {
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			adde(a, b, c, i); adde(b, a, c, i);
		}
		dfs1(1, 1, 1); dfs2(1, 1);
		/*
		for(int i = 1; i <= n; i++) {
			printf("for %d top is %d tid is %d\n", i
					, top[i], tid[i]);
		}
		*/
		//把边上的权值处理到点
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
		build(1, 1, idcnt);
		int cmd, v1, v2;
		for(int i = 0; i < q; i++) {
			scanf("%d", &cmd);
			if(cmd == 0) {
				scanf("%d", &v1);
				int ret = ask(s, v1);
				s = v1;
				printf("%d\n", ret);
			}
			else {
				scanf("%d%d", &v1, &v2);
				update(1, 1, idcnt, tid[rnum[v1]], v2);
			}
		}
	}
	return 0;
}
