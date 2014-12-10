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
const int maxn = 30;
const int INF = INT_MAX / 3;
int cap[maxn][maxn],n,s,t;
int level[maxn],q[maxn],qs,qe;
char buf[128];

bool bfs() {
    qs = qe = 0;
    q[qe++] = s;
    memset(level,0,sizeof(level));
    level[s] = 1;
    while(qs < qe) {
        int now = q[qs++];
        for(int i = 0;i <= n;i++) if(cap[now][i] && level[i] == 0) {
            level[i] = level[now] + 1; q[qe++] = i;
        }
    }
    return level[t];
}

int dfs(int now,int alpha) {
    if(now == t) return alpha;
    int sum = 0;
    for(int i = 0;i <= n && alpha;i++) {
        if(cap[now][i] && level[i] == level[now] + 1) {
            int ret = dfs(i,min(alpha,cap[now][i]));
            sum += ret; alpha -= ret;
            cap[now][i] -= ret; cap[i][now] += ret;
        }
    }
    if(sum == 0) level[now] = -1;
    return sum;
}

void solve() {
    int ans = 0;
    while(bfs()) ans += dfs(s,INT_MAX);
    if(ans >= INF) puts("PANIC ROOM BREACH");
    else printf("%d\n",ans);
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        memset(cap,0,sizeof(cap));
        scanf("%d%d",&n,&t);
        s = n;
        for(int i = 0;i < n;i++) {
            int m;
            scanf("%s%d",buf,&m);
            for(int j = 0;j < m;j++) {
                int tmp; scanf("%d",&tmp);
                cap[i][tmp] = INF;
                cap[tmp][i]++;
            }
            if(buf[0] == 'I') cap[s][i] = INF;
        }
        solve();
    }
    return 0;
}
