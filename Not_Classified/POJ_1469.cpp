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
const int maxn = 400;
int p,n,bx[maxn],by[maxn],vis[maxn];
bool g[maxn][maxn];

int dfs(int now) {
    for(int i = 1;i <= n;i++) if(g[now][i] && !vis[i]) {
        vis[i] = true;
        if(!by[i] || dfs(by[i])) {
            bx[now] = i; by[i] = now;
            return 1;
        }
    }
    return 0;
}

void solve() {
    memset(bx,0,sizeof(bx));
    memset(by,0,sizeof(by));
    //为每一门课程寻找代表
    int ans = 0;
    for(int i = 1;i <= p;i++) {
        if(!bx[i]) {
            memset(vis,0,sizeof(vis));
            ans += dfs(i);
        }
    }
    if(ans == p) puts("YES");
    else puts("NO");
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&p,&n);
        memset(g,0,sizeof(g));
        for(int i = 1;i <= p;i++) {
            int cnt; scanf("%d",&cnt);
            for(int j = 1;j <= cnt;j++) {
                int tmp; scanf("%d",&tmp);
                g[i][tmp] = true;
            }
        }
        solve();
    }
    return 0;
}
