#include <cstdio>
#include <cstring>
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
const int maxn = 15;
int mp[maxn][maxn];
char buf[128];
int e[maxn][maxn],incnt[10];
bool vis[10];
int dx[8] = {0,0,-1,1,1,1,-1,-1},dy[8] = {-1,1,0,0,1,-1,1,-1};

void solve() {
    memset(incnt,0,sizeof(incnt));
    memset(e,0,sizeof(e));
    bool clean = true;
    for(int i = 1;i <= 3;i++) {
        for(int j = 1;j <= 3;j++) {
            int u = (i - 1) * 3 + j;
            for(int k = i;k < i + 2;k++) {
                for(int l = j;l < j + 2;l++) {
                    if(mp[k][l] != u) {
                        if(!e[mp[k][l]][u]) incnt[u]++;
                        e[mp[k][l]][u] = true;
                    }
                }
            }
        }
    }
    memset(vis,0,sizeof(vis));
    for(int k = 1;k <= 9;k++) {
        int x = -1;
        for(int i = 1;i <= 9;i++) if(!vis[i]) {
            if(incnt[i] == 0) {
                x = i; break;
            }
        }
        if(x == -1) {
            clean = false; break;
        }
        vis[x] = true;
        for(int i = 1;i <= 9;i++) if(!vis[i] && e[x][i]) {
            incnt[i]--;
        }
    }
    if(clean) puts("THESE WINDOWS ARE CLEAN");
    else puts("THESE WINDOWS ARE BROKEN");
}

int main() {
    while(scanf("%s",buf),strcmp(buf,"ENDOFINPUT") != 0) {
        memset(mp,0,sizeof(mp));
        for(int i = 1;i <= 4;i++) {
            for(int j = 1;j <= 4;j++) {
                scanf("%d",&mp[i][j]);
            }
        }
        solve();
        scanf("%s",buf);
    }
    return 0;
}
