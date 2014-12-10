/*
ID: j.sure.1
PROG:
LANG: C++
*/
/****************************************/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <climits>
#include <iostream>
#define LL long long
using namespace std;
const int INF = 0x3f3f3f3f;
/****************************************/
const int N = 222, M = 44444;
int tot, head[N], q[N], s[N], lev[N], cur[N], S, T, n, m;
int f[N], b[M];
struct Edge {
	int u, v, w, next;
	Edge(){}
	Edge(int _u, int _v, int _w, int _next):
		u(_u), v(_v), w(_w), next(_next){}
}edge[M];


void init()
{
	tot = 0;
	memset(head, -1, sizeof(head));
}

void add(int u, int v, int w)
{
	edge[tot] = Edge(u, v, w, head[u]); head[u] = tot++;
	edge[tot] = Edge(v, u, 0, head[v]); head[v] = tot++;
}

bool bfs()
{
	memset(lev, -1, sizeof(lev));
	int fron = 0, rear = 0;
	q[rear++] = S; 
	lev[S] = 0;
	while(fron < rear) {
		int u = q[fron%N]; fron++;
		for(int i = head[u]; ~i; i = edge[i].next) {
			int v = edge[i].v;
			if(edge[i].w && lev[v] == -1) {
				lev[v] = lev[u] + 1;
				q[rear%N] = v; rear++;
				if(v == T) return true;
			}
		}
	}
	return false;
}

int Dinic()
{
	int ret = 0;
	while(bfs()) {
		memcpy(cur, head, sizeof(head));
		int u = S, top = 0;
		while(1) {
			if(u == T) {
				int mini = INF, loc;
				for(int i = 0; i < top; i++) {
					if(mini > edge[s[i]].w) {
						mini = edge[s[i]].w;
						loc = i;
					}
				}
				for(int i = 0; i < top; i++) {
					edge[s[i]].w -= mini;
					edge[s[i]^1].w += mini;
				}
				ret += mini;
				top = loc;
				u = edge[s[top]].u;
			}
			int &i = cur[u];
			for(; ~i; i = edge[i].next) {
				int v = edge[i].v;
				if(edge[i].w && lev[v] == lev[u] + 1) break;
			}
			if(~i) {
				s[top++] = i;
				u = edge[i].v;
			}
			else {
				if(!top) break;
				lev[u] = -1;
				u = edge[s[--top]].u;
			}
		}
	}
	return ret;
}

void judge()
{
	for(int i = head[S]; ~i; i = edge[i].next) if(edge[i].w) {
		puts("NO");
		return ;
	}
	puts("YES");
	for(int j = 0; j < m; j++) {
		printf("%d\n", edge[j<<1|1].w + b[j]);
	}
}

int main()
{
#ifdef J_Sure
	freopen("000.in", "r", stdin);
	freopen("999.out", "w", stdout);
#endif
	int Cas, kase = 0;
	scanf("%d", &Cas);
	while(Cas--) {
		if(kase++) puts("");
		scanf("%d%d", &n, &m);
		memset(f, 0, sizeof(f));
		init();
		S = 0; T = n+1;
		int u, v, l, c;
		for(int i = 0; i < m; i++) {
			scanf("%d%d%d%d", &u, &v, &l, &c);
			add(u, v, c-l);
			f[v] += l;
			f[u] -= l;
			b[i] = l;
		}
		for(int i = 1; i <= n; i++) {
			if(f[i] > 0) {
				add(S, i, f[i]);
			}
			else if(f[i] < 0) {
				add(i, T, -f[i]);
			}
		}
		int ans = Dinic();
		judge();
	}
	return 0;
}
