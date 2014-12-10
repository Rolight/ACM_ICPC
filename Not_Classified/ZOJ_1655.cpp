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
const int INF = INT_MAX / 4;
const int maxn = 105;
int vis[maxn],n,m,w[maxn];
double p[maxn][maxn],d[maxn];

void dijkstra() {
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= n;i++) {
        d[i] = -1;
    }
    d[n] = 1;
    for(int k = 1;k <= n;k++) {
        double maxv = -1; int x = n;
        for(int i = 1;i <= n;i++) if(!vis[i] && d[i] > maxv) {
            maxv = d[x = i];
        }
        vis[x] = true;
        for(int i = 1;i <= n;i++) if(!vis[i] && p[x][i] >= 0) {
            if(d[i] == -1) d[i] = d[x] * p[x][i];
            else d[i] = max(d[i],d[x] * p[x][i]);
        }
    }
}

int main() {
    while(scanf("%d%d",&n,&m) != EOF) {
        for(int i = 1;i < n;i++) {
            scanf("%d",&w[i]);
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                p[i][j] = -5;
            }
        }
        for(int i = 1;i <= m;i++) {
            int a,b;
            double c; scanf("%d%d%lf",&a,&b,&c);
            p[a][b] = p[b][a] = max((1 - c),p[a][b]);
        }
        dijkstra();
        double ans = 0;
        for(int i = 1;i < n;i++) if(d[i] > 0) {
            ans += d[i] * w[i];
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
