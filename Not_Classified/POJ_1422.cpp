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
const int maxn = 150;
int bx[maxn],by[maxn];
int n,m;
bool g[maxn][maxn],vis[maxn];

int dfs(int now) {
    for(int i = 1;i <= n;i++) if(!vis[i] && g[i][now]) {
        vis[i] = true;
        if(!by[i] || dfs(by[i])) {
            bx[now] = i; by[i] = now; return 1;
        }
    }
    return 0;
}

void solve() {
    memset(bx,0,sizeof(bx));
    memset(by,0,sizeof(by));
    int ans = 0;
    for(int i = 1;i <= n;i++) if(!bx[i]) {
        memset(vis,0,sizeof(vis));
        if(dfs(i)) ans++;   
    }
    printf("%d\n",n - ans);
}

int main() {
    int T; cin >> T;
    while(T--) {
        memset(g,0,sizeof(g));
        cin >> n >> m;
        for(int i = 0;i < m;i++) {
            int a,b; cin >> a >> b;
            g[a][b] = true;
        }
        solve();
    }
    return 0;
}
