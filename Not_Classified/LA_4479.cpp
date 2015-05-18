#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
const int maxn = 50;
const int maxp = maxn * maxn + maxn + 10;
const int wPoint = 2;
const int INF = INT_MAX / 4;

int matchCount[maxn][maxn], score[maxn], N, M, G;
int head[maxp], nxt[maxp << 1], v[maxp << 1], cap[maxp << 1], ecnt;
int id[maxn][maxn], pid[maxn], pcnt;
int s, t, gs;

void addEdge(int _u, int _v, int _c) {
	v[ecnt] = _v; nxt[ecnt] = head[_u]; cap[ecnt] = _c; head[_u] = ecnt++;
	v[ecnt] = _u; nxt[ecnt] = head[_v]; cap[ecnt] = 0; head[_v] = ecnt++;
}

//Dinic
int level[maxp];
bool bfs() {
	memset(level, 0, sizeof(level));
	queue<int> q; q.push(s);
	level[s] = 1;
	while(!q.empty()) {
		int now = q.front(); q.pop();
		if(now == t) break;
		for(int i = head[now]; ~i; i = nxt[i]) {
			if(cap[i] && level[v[i]] == 0) {
				q.push(v[i]); level[v[i]] = level[now] + 1;
			}
		}
	}
	return level[t];
}

int dfs(int now, int alpha) {
	if(now == t) return alpha;
	int sum = 0;
	for(int i = head[now]; ~i; i = nxt[i]) {
		if(cap[i] && level[v[i]] == level[now] + 1) {
			int ret = dfs(v[i], min(alpha, cap[i]));
			sum += ret; alpha -= ret;
			cap[i] -= ret; cap[i ^ 1] += ret;
		}
	}
	if(sum == 0) level[now] = -1;
	return sum;
}

void solve() {
	//count score
	for(int i = 1; i < N; i++) if(matchCount[0][i] < M) {
		score[0] += (M - matchCount[0][i]) * wPoint;
	}
	for(int i = 1; i < N; i++) if(score[0] <= score[i]) {
		puts("N"); return;
	}
	//build_graph
	s = pcnt++; t = pcnt++; gs = pcnt++;
	for(int i = 1; i < N; i++) {
		pid[i] = pcnt++;
		for(int j = 1; j < i; j++) if(matchCount[i][j] < M) {
			id[i][j] = id[j][i] = pcnt++;
		}
	}
	int tsum = 0;
	addEdge(s, gs, INF);
	for(int i = 1; i < N; i++) {
		for(int j = 1; j < i; j++) if(matchCount[i][j] < M) {
			addEdge(gs, id[i][j], (M - matchCount[i][j]) * wPoint);
			tsum += (M - matchCount[i][j]) * wPoint;
			addEdge(id[i][j], pid[i], INF);
			addEdge(id[i][j], pid[j], INF);
		}
		addEdge(pid[i], t, score[0] - score[i] - 1);
	}
	/*
	for(int i = 1; i < N; i++) {
		for(int j = 1; j < i; j++) if(matchCount[i][j] < M) {
			int tcap = (M - matchCount[i][j]) * wPoint;
			addEdge(s, pid[i], tcap);
			addEdge(pid[i], pid[j], tcap);
			tsum += tcap;
		}
		addEdge(pid[i], t, score[0] - score[i] - 1);
	}
	*/
	//dinic
	while(bfs()) dfs(s, INF);
	if(cap[1] == tsum) puts("Y");
	else puts("N");
	/*
	for(int i = head[s]; ~i; i = nxt[i]) {
		tsum -= cap[i ^ 1];
	}
	if(tsum == 0) puts("Y");
	else puts("N");
	*/
}

int main() {
	freopen("in.txt", "r", stdin);
	while(scanf("%d%d%d", &N, &M, &G), N || M || G) {
		pcnt = ecnt = 0;
		memset(head, -1, sizeof(head));
		memset(matchCount, 0, sizeof(matchCount));
		memset(score, 0, sizeof(score));
		int a, b; char state[4];
		for(int i = 0; i < G; i++) {
			scanf("%d %s %d", &a, state, &b);
			if(state[0] == '=') {
				score[a]++; score[b]++;
			}
			else if(state[0] == '<') score[b] += 2;
			else score[a] += 2;
			matchCount[a][b]++;
			matchCount[b][a]++;
		}
		for(int i = 0; i < N; i++) {
			printf("%d: %d\n", i, score[i]);
		}
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < i; j++) if(M - matchCount[i][j]) {
				printf("%d %d %d\n", i, j, wPoint * (M - matchCount[i][j]));
			}
		}
		solve();
	}
	return 0;
}
