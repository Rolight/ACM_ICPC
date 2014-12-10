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
int lowcost[maxn],dist[maxn][maxn],N;
bool vis[maxn];

int main() {
    while(scanf("%d",&N) != EOF) {
        memset(vis,0,sizeof(vis));
        for(int i = 1;i <= N;i++) {
            for(int j = 1;j <= N;j++) {
                scanf("%d",&dist[i][j]);
            }
            lowcost[i] = dist[1][i];
        }
        vis[1] = true;
        LL ans = 0;
        for(int i = 2;i <= N;i++) {
            int minv = INT_MAX,x;
            for(int j = 1;j <= N;j++) if(!vis[j]) {
                if(lowcost[j] < minv) {
                    minv = lowcost[j]; x = j;
                }
            }
            vis[x] = true;
            ans += lowcost[x];
            for(int j = 1;j <= N;j++) if(!vis[j]) lowcost[j] = min(lowcost[j],dist[x][j]);
        }
        cout << ans << endl;
    }
    return 0;
}
