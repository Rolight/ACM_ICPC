#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <iostream>
#include <map>
#include <cstdlib>
#include <list>
#include <set>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
const int maxn = 300;
const int INF = INT_MAX / 4;
int K,C,M,N,s,t;
int dist[maxn][maxn];
int cap[maxn][maxn],sig[maxn],vis[maxn][maxn];

void floyd() {
    for(int k = 1;k <= N;k++) {
        for(int i = 1;i <= N;i++) {
            for(int j = 1;j <= N;j++) {
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
}

void build_graph(int minval) {
    memset(cap,0,sizeof(cap));
    s = 0; t = N + 1;
    for(int i = K + 1;i <= N;i++) cap[s][i] = 1;
    for(int i = 1;i <= K;i++) cap[i][t] = M;
    for(int i = K + 1;i <= N;i++) {
        for(int j = 1;j <= K;j++) if(dist[i][j] <= minval) {
            cap[i][j] = 1;
        }
    }
}

int q[maxn * 2],qs,qe;

bool bfs() {
    qs = 0; qe = 1;
    q[qs] = s;
    memset(sig,0,sizeof(sig));
    sig[s] = 1;
    while(qs < qe) {
        int v = q[qs++];
        if(v == t) break;
        for(int i = s;i <= t;i++) if(cap[v][i] && !sig[i]) {
            sig[i] = sig[v] + 1;
            q[qe++] = i;
        }
    }
    if(sig[t] == 0) return false;
    else return true;
}

int dinic(int now,int alpha) {
    int rest = alpha;
    if(now == t) return alpha;
    for(int i = s;i <= t;i++) {
        if(sig[i] == sig[now] + 1 && rest && cap[now][i]) {
            int ret = dinic(i,min(rest,cap[now][i]));
            cap[now][i] -= ret;
            cap[i][now] += ret;
            rest -= ret;
        }
    }
    return alpha - rest;
}

bool ok(int val) {
    build_graph(val);
    int ans = 0;
    while(bfs()) {
        int ret = dinic(s,INF);
        ans += ret;
    }
    return ans >= C;
}

void solve() {
    floyd();
    int mine = INF,maxe = -1;
    for(int i = 1;i <= N;i++) {
        for(int j = 1;j <= N;j++) {
            if(dist[i][j] != INF) {
                mine = min(mine,dist[i][j]);
                maxe = max(maxe,dist[i][j]);
            }
        }
    }
    int l = mine,r = maxe,ans;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(ok(mid)) ans = mid,r = mid - 1;
        else l = mid + 1;
    }
    printf("%d\n",ans);
}

int main() {
    while(scanf("%d%d%d",&K,&C,&M) != EOF) {
        N = K + C;
        for(int i = 1;i <= N;i++) {
            for(int j = 1;j <= N;j++) {
                scanf("%d",&dist[i][j]);
                if(dist[i][j] == 0) dist[i][j] = INF;
            }
        }
        solve();
    }
    return 0;
}
