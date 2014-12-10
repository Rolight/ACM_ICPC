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
const int maxn = 505;
int n,m,bx[maxn],by[maxn];
bool vis[maxn],g[maxn][maxn];

int dfs(int now) {
    for(int i = 1;i <= n;i++) if(!vis[i] && g[now][i]) {
        vis[i] = true;
        if(!by[i] || dfs(by[i])) {
            bx[now] = i; by[i] = now; return 1;
        }
    }
    return 0;
}

int main() {
    while(scanf("%d%d",&n,&m) != EOF) {
        memset(g,0,sizeof(g));
        memset(bx,0,sizeof(bx));
        memset(by,0,sizeof(by));
        for(int i = 1;i <= m;i++) {
            int a,b; scanf("%d%d",&a,&b);
            g[a][b] = true;
        }
        int ans = 0;
        for(int i = 1;i <= n;i++) if(!bx[i]) {
            memset(vis,0,sizeof(vis));
            if(dfs(i)) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
