#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <string>
#include <iostream>
#include <map>
#include <cstdlib>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long LL;
const int maxn = 505;
const int maxm = maxn * maxn;
const LL INF = 1e14;
struct Edge {
    int u,v; LL w;
    bool operator < (const Edge &x) const {
        return w < x.w;
    }
};
LL dist[maxn][maxn],cow_cnt[maxn],sj_cnt[maxn],cow_sum;
LL cap[maxm],v[maxm],maxedge;
Edge e[maxm];
int first[maxn],nxt[maxm];
int n,m,s,t,ecnt,oecnt;

void adde(int uu,int vv,LL ww) {
    v[ecnt] = vv; cap[ecnt] = ww; nxt[ecnt] = first[uu]; first[uu] = ecnt++;
    v[ecnt] = uu; cap[ecnt] = 0; nxt[ecnt] = first[vv]; first[vv] = ecnt++;
}

void floyd() {
    maxedge = -1;
    for(int k = 1;k <= n;k++) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                dist[i][j] = min(dist[i][k] + dist[k][j],dist[i][j]);
            }
        }
    }
    oecnt = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(dist[i][j] != INF) {
                maxedge = max(maxedge,dist[i][j]);
                e[oecnt].u = i; e[oecnt].v = j; e[oecnt].w = dist[i][j]; oecnt++;
            }
        }
        e[oecnt].u = i; e[oecnt].v = i; e[oecnt].w = 0; oecnt++;
    }
    sort(e,e + oecnt);
}

void input() {
    memset(first,-1,sizeof(first));
    memset(nxt,-1,sizeof(nxt));
    s = 0; t = (n << 1) | 1;
    cow_sum = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            dist[i][j] = INF;
        }
    }
    for(int i = 1;i <= n;i++) {
        scanf("%lld%lld",&cow_cnt[i],&sj_cnt[i]);
        cow_sum += cow_cnt[i];
    }
    for(int i = 1;i <= m;i++) {
        int u,v; LL w;
        scanf("%d%d%lld",&u,&v,&w);
        dist[u][v] = dist[v][u] = min(dist[u][v],w);
    }
    floyd();
}

void build_graph(LL minval) {
    memset(first,-1,sizeof(first));
    ecnt = 0;
    for(int i = 1;i <= n;i++) {
        adde(i + n,t,sj_cnt[i]);
        adde(s,i,cow_cnt[i]);
    }
    for(int i = 0;i < oecnt;i++) {
        if(e[i].w > minval) break;
        adde(e[i].u,e[i].v + n,INF);
    }
}

int q[maxn * 2],qs,qe,level[maxn];
bool bfs() {
    memset(level,0,sizeof(level));
    qs = 0; qe = 1;
    q[qs] = s; level[s] = 1;
    while(qs < qe) {
        int now = q[qs++];
        for(int i = first[now];i != -1;i = nxt[i]) {
            if(level[v[i]] == 0 && cap[i] != 0) {
                q[qe++] = v[i]; level[v[i]] = level[now] + 1;
            }
        }
    }
    return level[t];
}

LL dinic(int now,LL alpha) {
    if(now == t) return alpha;
    LL sum = 0;
    for(int i = first[now];i != -1 && alpha;i = nxt[i]) {
        if(cap[i] && level[v[i]] == level[now] + 1) {
            LL ret = dinic(v[i],min(alpha,cap[i]));
            alpha -= ret; sum += ret;
            cap[i] -= ret; cap[i ^ 1] += ret;
        }
    }
    return sum;
}

bool ok(LL val) {
    LL ans = 0;
    build_graph(val);
    while(bfs()) ans += dinic(s,INF);
    return ans >= cow_sum;
}

void solve() {
    LL l = 1,r = maxedge,ans = -1,mid;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(ok(mid)) {
            r = mid - 1; ans = mid;
        } else l = mid + 1;
    }
    printf("%lld\n",ans);
}

int main() {
    while(~scanf("%d%d",&n,&m)) {
        input();
        solve();
    }
    return 0;
}
