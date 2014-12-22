#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef long long LL;

const int maxn = 4e4 + 20;
const LL INF = 1e15;
LL d1[maxn], d2[maxn], d3[maxn];
LL B, E, P, N, M;
int head[maxn << 1], nxt[maxn << 1], v[maxn << 1], ecnt;
bool vis[maxn];
int icnt[maxn];

inline void adde(int _u, int _v) {
	v[ecnt] = _v; nxt[ecnt] = head[_u]; head[_u] = ecnt++;
}

void SPFA(LL d[], int str, int power) {
	for(int i = 1; i <= N; i++) {
		vis[i] = false; d[i] = INF; icnt[i] = 0;
	}
	queue<int> q; q.push(str); d[str] = 0; vis[str] = true;
	while(!q.empty()) {
		int now = q.front(); q.pop();
		vis[now] = false;
		for(int i = head[now]; ~i; i = nxt[i]) {
			if(d[v[i]] > d[now] + power) {
				d[v[i]] = d[now] + power;
				if(!vis[v[i]]) {
					vis[v[i]] = true;
					q.push(v[i]);
				}
			}
		}
	}
}

int main() {
	freopen("piggyback.in", "r", stdin);
	freopen("piggyback.out", "w", stdout);
	cin >> B >> E >> P >> N >> M;
	ecnt = 0; memset(head, -1, sizeof(head));
	for(int i = 0; i < M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adde(a, b); adde(b, a);
	}
	SPFA(d1, 1, B); SPFA(d2, 2, E); SPFA(d3, N, P);
	LL ans = INF;
	for(int i = 1; i <= N; i++) {
		LL nowVal = d1[i] + d2[i] + d3[i];
		ans = min(ans, nowVal);
	}
	cout << ans << endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
