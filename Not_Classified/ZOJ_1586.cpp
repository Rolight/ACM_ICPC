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
const int INF = INT_MAX / 2;
const int maxn = 1005;
int dist[maxn][maxn],lowcost[maxn],val[maxn];
int N;

int main() {
    int T; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++) {
        int ans = 0;
        scanf("%d",&N);
        for(int i = 1;i <= N;i++) {
            scanf("%d",val + i);
        }
        for(int i = 1;i <= N;i++) {
            for(int j = 1;j <= N;j++) {
                scanf("%d",&dist[i][j]);
                if(i != j) dist[i][j] += val[i] + val[j];
            }
        }
        for(int i = 1;i <= N;i++) {
            lowcost[i] = dist[1][i];
        }
        lowcost[1] = -1;
        for(int i = 2;i <= N;i++) {
            int minv = INF,x;
            for(int j = 1;j <= N;j++) if(lowcost[j] != -1) {
                if(lowcost[j] < minv) {
                    minv = lowcost[j]; x = j;
                }
            }
            ans += minv;
            lowcost[x] = -1;
            for(int j = 1;j <= N;j++) if(lowcost[j] != -1) {
                lowcost[j] = min(lowcost[j],dist[x][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
