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
const int maxn = 4000;
int n, m, dist[maxn][maxn];
int s0, t0, l0, s1, t1, l1;
bool vis[maxn];
std::vector<int> edge[maxn];

void bfs(int str, int d[maxn]) {
	std::queue<int> q;
	memset(vis, 0, sizeof(vis));
	q.push(str);
	vis[str] = true;
	d[str] = 0;
	while(q.empty() == false) {
		int now = q.front(); q.pop();
		for(int i = 0; i < edge[now].size(); i++) {
			if(!vis[edge[now][i]]) {
				d[edge[now][i]] = d[now] + 1;
				vis[edge[now][i]] = true;
				q.push(edge[now][i]);
			}
		}
	}
}

int gao() {
	if(dist[s0][t0] > l0 || dist[s1][t1] > l1) return -1;
	int ret = 0;
	ret = std::max(ret, m - dist[s0][t0] - dist[s1][t1]);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) if(i != j) {
			if(dist[s0][i] + dist[i][j] + dist[j][t0] <= l0 &&
					dist[s1][i] + dist[i][j] + dist[j][t1] <= l1) {
				ret = std::max(ret, m - 
						dist[s0][i] - dist[i][j] - dist[j][t0] - 
						dist[s1][i] - dist[t1][j]);
			}
			if(dist[t0][i] + dist[i][j] + dist[j][s0] <= l0 &&
					dist[s1][i] + dist[i][j] + dist[j][t1] <= l1) {
				ret = std::max(ret, m - 
						dist[t0][i] - dist[i][j] - dist[j][s0] - 
						dist[s1][i] - dist[t1][j]);
			}
		}
	}
	return ret;
}

int main() {
	int u, v;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) bfs(i, dist[i]);
	scanf("%d%d%d", &s0, &t0, &l0);
	scanf("%d%d%d", &s1, &t1, &l1);
	printf("%d\n", gao());
	return 0;
}
