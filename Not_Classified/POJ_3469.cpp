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
const int maxn = 20000 + 5;
const int maxm = 200000 * 30;
const LL INF = INT_MAX - 2;
int first[maxn],nxt[maxm],v[maxm],cap[maxm];
int n,m,s,t,ans,ecnt;

inline void adde(int uu,int vv,int ww) {
    v[ecnt] = vv; cap[ecnt] = ww;
    nxt[ecnt] = first[uu];
    first[uu] = ecnt++;
    v[ecnt] = uu; cap[ecnt] = 0;
    nxt[ecnt] = first[vv];
    first[vv] = ecnt++;
}

inline void input() {
    int a,b,c;
    for(int i = 1;i <= n;i++) {
        scanf("%d%d",&a,&b);
        adde(s,i,a); adde(i,t,b);
    }
    for(int i = 1;i <= m;i++) {
        scanf("%d%d%d",&a,&b,&c);
        adde(a,b,c);
        adde(b,a,c);
    }
}

int q[maxn * 2],qs,qe,level[maxn];
inline bool bfs() {
    qs = qe = 0;
    memset(level,0,sizeof level);
    q[qe++] = s;
    level[s] = 1;
    while(qs < qe) {
        int now = q[qs++];
        if(now == t) break;
        for(int i = first[now];~i;i = nxt[i]) {
            if(!level[v[i]] && cap[i]) {
                level[v[i]] = level[now] + 1;
                q[qe++] = v[i];
            }
        }
    }
    return level[t];
}

int dfs(int now,int alpha) {
    if(now == t) return alpha;
    int sum = 0;
    for(int i = first[now];~i && alpha;i = nxt[i]) {
        if(level[v[i]] == level[now] + 1 && cap[i]) {
            int ret = dfs(v[i],min(alpha,cap[i]));
            cap[i] -= ret; cap[i ^ 1] += ret;
            sum += ret; alpha -= ret;
        }
    }
    if(sum == 0) level[now] = -1;
    return sum;
}

inline int dinic() {
    int ans = 0;
    while(bfs()) ans += dfs(s,INF);
    return ans;
}

inline void solve() {
    int ret = dinic();
    printf("%d\n",ret);
}

int main() {
    while(scanf("%d%d",&n,&m) != EOF) {
        ecnt = 0;
        s = 0; t = n + 1;
        memset(first,-1,sizeof(first));
        input();
        solve();
    }
    return 0;
}
