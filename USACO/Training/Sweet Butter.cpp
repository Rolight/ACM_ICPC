/*
ID: flsnnx1
LANG: C++
TASK: butter
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>

const int maxp = 810;
const int maxe = 4096;
const int INF = INT_MAX >> 3;

int min_d[maxp][maxp], d[maxp], cow_pos[maxp];
bool inq[maxp];
int head[maxp], nxt[maxe], v[maxe], w[maxe], ecnt;
int n, m, k;

void add_edge(int uu, int vv, int ww) {
	v[ecnt] = vv; w[ecnt] = ww;
	nxt[ecnt] = head[uu];
	head[uu] = ecnt++;
}

void spfa(int str, int d[]) {
	std::queue<int> q;
	q.push(str);
	for(int i = 1; i <= n; i++) if(i != str) {
		inq[i] = true; q.push(i);
	}
	while(!q.empty()) {
		int now = q.front(); q.pop();
		inq[now] = false;
		for(int i = head[now]; i != -1; i = nxt[i]) {
			if(d[v[i]] > d[now] + w[i]) {
				d[v[i]] = d[now] + w[i];
				if(!inq[v[i]]) {
					q.push(v[i]);
					inq[v[i]] = true;
				}
			}
		}
	}
}

void ex_spfa() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			min_d[i][j] = INF;
		}
		min_d[i][i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		spfa(i, min_d[i]);
		for(int j = 1; j <= n; j++) {
			min_d[j][i] = std::min(min_d[i][j], min_d[j][i]);
		}
	}
}

int main() {
	freopen("butter.in", "r", stdin);
	freopen("butter.out", "w", stdout);
	memset(head, -1, sizeof(head));
	scanf("%d%d%d", &k, &n, &m);
	for(int i = 1; i <= k; i++) scanf("%d", &cow_pos[i]);
	int a, b, c;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		add_edge(a, b, c); add_edge(b, a, c);
	}
	ex_spfa();
	int ans = INF;
	for(int i = 1; i <= n; i++) {
		int nowcost = 0;
		for(int j = 1; j <= k; j++) {
			nowcost += min_d[i][cow_pos[j]];
		}
		ans = std::min(ans, nowcost);
	}
	printf("%d\n", ans);
	return 0;
}
