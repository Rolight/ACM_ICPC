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
const int maxn = 1e5 + 100;

int tid[maxn], nid[maxn], rank[maxn], rank1[maxn];
int son[maxn], siz[maxn], fa[maxn], top[maxn], dep[maxn];
int head[maxn], nxt[maxn << 1], v[maxn << 1], u[maxn << 1], ecnt, idcnt;
int n, m, addv1[maxn], addv2[maxn], Vval[maxn], Eval[maxn];
int eid[maxn], erank[maxn];

inline bool scanf_(int &ret) {
   char c; int sgn;
   if(c=getchar(),c==EOF) return 0; //EOF
   while(c!='-'&&(c<'0'||c>'9')) c=getchar();
   sgn=(c=='-')?-1:1;
   ret=(c=='-')?0:(c-'0');
   while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
   ret*=sgn;
   return 1;
}
 
inline void printf_(int x) {
   if(x>9) printf_(x/10);
   putchar(x%10+'0');
}

inline void adde(int uu, int vv, int id) {
	u[ecnt] = uu; v[ecnt] = vv; nxt[ecnt] = head[uu]; 
	eid[ecnt] = id; head[uu] = ecnt++;
}

inline void init() {
	memset(son, -1, sizeof(son));
	memset(head, -1, sizeof(head));
	memset(addv1, 0, sizeof(addv1));
	memset(addv2, 0, sizeof(addv2));
	ecnt = idcnt = 0;
}

void dfs1(int now, int nowfa, int nowdep) {
	fa[now] = nowfa, dep[now] = nowdep; siz[now] = 1;
	for(int i = head[now]; ~i; i = nxt[i]) if(v[i] != nowfa) {
		dfs1(v[i], now, nowdep + 1);
		siz[now] += siz[v[i]];
		if(son[now] == -1 || siz[v[i]] > siz[son[now]]) {
			son[now] = v[i];
		}
	}
}

void dfs2(int now, int tp) {
	tid[now] = ++idcnt; rank[idcnt] = now;
	top[now] = tp;
	if(son[now] == -1) return;
	dfs2(son[now], tp);
	for(int i = head[now]; ~i; i = nxt[i]) 
		if(v[i] != fa[now] && v[i] != son[now]) {
			dfs2(v[i], v[i]);
		}
}

inline void gao2(int x, int y, int w) {
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		addv2[tid[top[x]]] += w;
		if(top[rank[tid[x] + 1]] == top[x])
			addv2[tid[x] + 1] -= w;
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	addv2[tid[x] + 1] += w; 
	if(top[rank[tid[y] + 1]] == top[y])
		addv2[tid[y] + 1] -= w;
}

inline void gao1(int x, int y, int w) {
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		addv1[tid[top[x]]] += w;
		if(top[rank[tid[x] + 1]] == top[x])
			addv1[tid[x] + 1] -= w;
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	addv1[tid[x]] += w;
	if(top[rank[tid[y] + 1]] == top[y])
		addv1[tid[y] + 1] -= w;
}

void calc() {
	int val1 = 0, val2 = 0;
	for(int i = 1; i <= n; i++) {
		val1 += addv1[i]; val2 += addv2[i];
		Vval[rank[i]] = val1;
		Eval[rank[i]] = val2;
		if(top[rank[i + 1]] != top[rank[i]]) {
			val1 = val2 = 0;
		}
	}
}

int main() {
	int __size__ = 256 << 20;
	char * __p__ = (char *) malloc(__size__) + __size__;
	__asm__("movl %0,%%esp\n"::"r"(__p__));
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		init();
		scanf("%d%d", &n, &m);
		for(int i = 1; i < n; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adde(a, b, i); adde(b, a, i);
		}
		dfs1(1, 1, 1); dfs2(1, 1);
		for(int i = 0; i < ecnt; i++) {
			if(dep[u[i]] < dep[v[i]]) {
				erank[eid[i]] = v[i];
			}
			else erank[eid[i]] = u[i];
		}
		char cmd[16]; 
		int a, b, y;
		getchar();
		while(m--) {
			getchar(); getchar(); getchar();
			cmd[3] = getchar();
			scanf_(a); scanf_(b); scanf_(y);
			if(cmd[3] == '1') gao1(a, b, y);
			else gao2(a, b, y);
		}
		calc();
		printf("Case #%d:\n", kase);
		for(int i = 1; i <= n; i++) {
			if(i > 1) putchar(' ');
			printf_(Vval[i]);
		}
		puts("");
		for(int i = 1; i < n; i++) {
			if(i > 1) putchar(' ');
			printf_(Eval[erank[i]]);
		}
		puts("");
	}
	return 0;
}
