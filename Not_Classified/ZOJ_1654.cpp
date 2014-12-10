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
const int maxn = 61;
const int maxk = maxn * maxn;
char buf[maxn][maxn];
int bx[maxk],by[maxk],n,m,cntx,cnty;
int xid[maxn][maxn],yid[maxn][maxn];
bool g[maxk][maxk],vis[maxk];

int dfs(int now) {
    for(int i = 1;i <= cnty;i++) if(g[now][i] && !vis[i]) {
        vis[i] = true;
        if(!by[i] || dfs(by[i])) {
            bx[now] = i; by[i] = now;
            return 1;
        }
    }
    return 0;
}

int solve() {
    int ret = 0;
    memset(bx,0,sizeof(bx));
    memset(by,0,sizeof(by));
    for(int i = 1;i <= cntx;i++) if(!bx[i]) {
        memset(vis,0,sizeof(vis));
        ret += dfs(i);
    }
    return ret;
}

int main() {
    int T; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++) {
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++) scanf("%s",buf[i] + 1);
        //build-graph
        memset(xid,0,sizeof(xid));
        memset(yid,0,sizeof(yid));
        memset(g,0,sizeof(g));
        cntx = cnty = 0;
        for(int i = 1;i <= n;i++) {
            int flag = 0;
            for(int j = 1;j <= m;j++) {
                if(buf[i][j] == 'o') {
                    if(flag == 0) cntx++,flag = 1;
                    xid[i][j] = cntx;
                } else if(buf[i][j] == '#') flag = 0;
            }
        }
        for(int j = 1;j <= m;j++) {
            int flag = 0;
            for(int i = 1;i <= n;i++) {
                if(buf[i][j] == 'o') {
                    if(!flag) cnty++,flag = 1;
                    yid[i][j] = cnty;
                } else if(buf[i][j] == '#') flag = 0;
            }
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) if(xid[i][j] && yid[i][j]) {
                g[xid[i][j]][yid[i][j]] = true;
            }
        }
        int ans = solve();
        printf("Case :%d\n%d\n",kase,ans);
    }
    return 0;
}
