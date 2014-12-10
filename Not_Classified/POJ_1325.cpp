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
const int maxn = 200;
bool g[maxn][maxn];
int nx,ny,m;
int bx[maxn],by[maxn];
bool vis[maxn];

int path(int now) {
    for(int i = 1;i <= ny;i++) if(g[now][i] && !vis[i]) {
        vis[i] = true;
        if(!by[i] || path(by[i])) {
            bx[now] = i; by[i] = now;
            return 1;
        }
    }
    return 0;
}

void solve() {
    memset(bx,0,sizeof(bx));
    memset(by,0,sizeof(by));
    int ans = 0;
    for(int i = 1;i <= nx;i++) {
        if(!bx[i]) {
            memset(vis,0,sizeof(vis));
            ans += path(i);
        }
    }
    printf("%d\n",ans);
}

int main() {
    while(scanf("%d",&nx),nx) {
        scanf("%d%d",&ny,&m);
        memset(g,0,sizeof(g));
        for(int i = 0;i < m;i++) {
            int a,b,c; scanf("%d%d%d",&a,&b,&c);
            g[b][c] = 1;
        }
        solve();
    }
    return 0;
}
