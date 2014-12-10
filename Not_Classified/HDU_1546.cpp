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
const int maxn = 1005;
int len[maxn],d[maxn],T[maxn],e[maxn][maxn],n;
bool vis[maxn];
char buf[maxn][5000];

void dijkstra() {
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= n;i++) d[i] = -1;
    d[1] = 0;
    for(int k = 1;k <= n;k++) {
        int x = -1,minv = INT_MAX;
        for(int i = 1;i <= n;i++) {
            if(!vis[i] && d[i] < minv && d[i] != -1) {
                minv = d[i]; x = i;
            }
        }
        if(x == -1) return;
        vis[x] = true;
        for(int i = 1;i <= n;i++) if(!vis[i] && e[x][i] != -1) {
            if(d[i] == -1) d[i] = d[x] + e[x][i];
            else d[i] = min(d[i],d[x] + e[x][i]);
        }
    }
}

int main() {
    while(scanf("%d",&n),n) {
        memset(e,-1,sizeof(e));
        for(int i = 1;i <= n;i++) {
            scanf("%d%s",&T[i],buf[i]);
            len[i] = strlen(buf[i]);
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) if(i != j) {
                if(strncmp(buf[i],buf[j] + len[j] - 4,4) == 0) {
                    e[j][i] = T[j];
                }
            }
        }
        dijkstra();
        printf("%d\n",d[n]);
    }
    return 0;
}
