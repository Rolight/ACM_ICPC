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
const int maxn = 105;
const double INF = 1e60;
const double eps = 1e-9;
int level[maxn],n,m,c,q[maxn],qs,qe;
double cap[maxn][maxn];
int s,t;

bool bfs() {
    qs = qe = 0;
    memset(level,0,sizeof(level));
    level[s] = 1;
    q[qe++] = s;
    while(qs < qe) {
        int now = q[qs++];
        if(now == t) break;
        for(int i = s;i <= t;i++) if(cap[now][i] >= eps) {
            if(level[i] == 0) {
                q[qe++] = i; level[i] = level[now] + 1;
            }
        }
    } 
    return level[t];
}

double dfs(int now,double alpha) {
    if(now == t) return alpha;
    double sum = 0;
    for(int i = s;i <= t && alpha >= eps;i++) {
        if(cap[now][i] >= eps && level[i] == level[now] + 1) {
            double ret = dfs(i,min(alpha,cap[now][i]));
            sum += ret; alpha -= ret;
            cap[now][i] -= ret; cap[i][now] += ret;
        }
    }
    if(sum < eps) level[now] = -1;
    return sum;
}

void solve() {
    double ans = 0;
    while(bfs()) ans += dfs(s,INF);
    printf("%.4f\n",exp(ans));
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        memset(cap,0,sizeof(cap));
        scanf("%d%d%d",&n,&m,&c);
        s = 0; t = n + m + 1;
        for(int i = 1;i <= n;i++) {
            double tmp; scanf("%lf",&tmp);
            cap[s][i] = log(tmp);
        }
        for(int i = 1;i <= m;i++) {
            double tmp; scanf("%lf",&tmp);
            cap[i + n][t] = log(tmp);
        }
        for(int i = 1;i <= c;i++) {
            int a,b; scanf("%d%d",&a,&b);
            cap[a][b + n] = INF;
        }
        solve();
    }
    return 0;
}
