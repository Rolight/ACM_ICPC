/*
ID: flsnnx1
LANG: C++
TASK: agrinet
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 105;
const int maxm = maxn * maxn;
int lowcost[maxn];
int dist[maxn][maxn],n;
bool vis[maxn];

int main() {
    freopen("agrinet.in","r",stdin);
    freopen("agrinet.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            scanf("%d",&dist[i][j]);
        }
    }
    //prim
    int ans = 0;
    for(int i = 1;i <= n;i++) lowcost[i] = 1e8;
    lowcost[1] = 0;
    for(int i = 1;i <= n;i++) {
        int x,minval = 1e8;
        for(int j = 1;j <= n;j++) if(!vis[j] && lowcost[j] < minval) {
            minval = lowcost[x = j];
        }
        vis[x] = true;
        ans += lowcost[x];
        for(int j = 1;j <= n;j++) if(!vis[j]) {
            lowcost[j] = min(lowcost[j],dist[x][j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}

