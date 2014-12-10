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
bool g[maxn][maxn];
bool vis[maxn];
int n,bx[maxn],by[maxn];

int dfs(int now) {
    for(int i = 0;i < n;i++) if(g[now][i] && !vis[i]) {
        vis[i] = true;
        if(!by[i] || dfs(by[i])) {
            by[i] = now; bx[now] = i;
            return 1;
        }
    }
    return 0;
}

void solve() {
    memset(bx,0,sizeof(bx));
    memset(by,0,sizeof(by));
    int ans = 0;
    for(int i = 0;i < n;i++) if(!bx[i]) {
        memset(vis,0,sizeof(vis));
        if(dfs(i)) ans++;
    }
    printf("%d\n",n - ans / 2);
}

int main() {
    while(scanf("%d",&n) != EOF) {
        memset(g,0,sizeof(g));
        for(int i = 0;i < n;i++) {
            int cnt,id; scanf("%d: (%d)",&id,&cnt);
            for(int j = 0;j < cnt;j++) {
                int tmp; scanf("%d",&tmp);
                g[id][tmp] = true;
            }
        }
        solve();
    }
    return 0;
}
