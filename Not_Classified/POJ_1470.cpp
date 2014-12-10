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
const int maxn = 1000;
struct Edge {
	int u, v, id;
	Edge(int u, int v, int id = 0): u(u), v(v), id(id) {}
};
vector<Edge> e[maxn], q[maxn];
int n, fa[maxn], ans[260000], col[maxn], pfa[maxn];
map<int, int> mp;

int getfa(int u) {
	return fa[u] == u ? u : fa[u] = getfa(fa[u]);
}

void dfs(int now) {
	int qsize = q[now].size();
	col[now] = 1;
	for(int i = 0; i < qsize; i++) if(ans[q[now][i].id] == -1) {
		int v = q[now][i].v;
		if(col[v] != 0) ans[q[now][i].id] = getfa(v);
	}
	int esize = e[now].size();
	for(int i = 0; i < esize; i++) {
		int v = e[now][i].v;
		dfs(v);
		fa[v] = now;
	}
}

int main() {
	while(scanf("%d", &n) != EOF) {
		for(int i = 1; i <= n; i++) {
			e[i].clear(); q[i].clear();
			fa[i] = i; col[i] = 0;
		}
		memset(pfa, -1, sizeof(pfa));
		for(int i = 1; i <= n; i++) {
			int now, cnt; scanf("%d:(%d)", &now, &cnt);
			for(int j = 0; j < cnt; j++) {
				int tmp; scanf("%d", &tmp);
				e[now].push_back(Edge(now, tmp));
				pfa[tmp] = now;
			}
		}
		int qcnt; scanf("%d", &qcnt);
		char kk;
		memset(ans, -1, sizeof(ans));
		for(int i = 1; i <= qcnt; i++) {
			int a, b;
			scanf(" %c%d %d%c", &kk, &a, &b, &kk);
			q[a].push_back(Edge(a, b, i));
			q[b].push_back(Edge(b, a, i));
		}
		int root;
		for(int i = 1; i <= n; i++) if(pfa[i] == -1) root = i;
		dfs(root);
		mp.clear();
		for(int i = 1; i <= qcnt; i++) mp[ans[i]]++;
		for(map<int, int>::iterator i = mp.begin(); i != mp.end(); i++) {
			cout << i->first << ":" << i->second << endl;
		}
	}
	return 0;
}
