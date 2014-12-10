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
const int maxn = 600;
int d[maxn],e[maxn][maxn],n,m;
bool vis[maxn];

void dijkstra() {
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= n;i++) d[i] = INT_MAX / 4;
    d[1] = 0;
    for(int k = 1;k <= n;k++) {
        int x,minv = INT_MAX;
        for(int i = 1;i <= n;i++) if(!vis[i]) {
            if(d[i] < minv) minv = d[x = i];
        }
        vis[x] = true;
        for(int i = 1;i <= n;i++) if(!vis[i] && e[i][x] != -1) {
            d[i] = min(d[i],d[x] + e[i][x]);
        }
    }
}

void solve(int &kase) {
    printf("System #%d\n",kase++);
    if(m == 0) {
        puts("The last domino falls after 0.0 seconds, at key domino 1.\n");
        return;
    }
    dijkstra();
    int maxt = -1,t = 1,tx = 1;
    double lastt = -1;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) if(i != j && d[i] >= d[j]) {
            double last = (e[i][j] - d[i] + d[j]) / 2.0f + d[i] - d[j] + d[j];
            if(last > lastt) {
                t = i; tx = j; lastt = last;
            }
        }
    }
    if(fabs(lastt - d[t]) < 1e-6) {
        printf("The last domino falls after %.1f seconds, at key domino %d.",lastt,t);
    }
    else {
        if(t > tx) {
            int tmp = t; t = tx; tx = tmp;
        }
        printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.",lastt,t,tx);
    }
    puts("\n");
}

int main() {
    int kase = 1;
    while(scanf("%d%d",&n,&m),n) {
        memset(e,-1,sizeof(e));
        for(int i = 0;i < m;i++) {
            int a,b,c; scanf("%d%d%d",&a,&b,&c);
            e[a][b] = e[b][a] = c;
        }
        solve(kase);
    }
    return 0;
}
