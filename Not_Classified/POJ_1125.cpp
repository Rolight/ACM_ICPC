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
const int maxn = 105;
int d[maxn][maxn],n;

int main() {
    while(scanf("%d",&n),n) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                d[i][j] = INF;
            }
        }
        for(int i = 1;i <= n;i++) {
            int m; scanf("%d",&m);
            for(int j = 1;j <= m;j++) {
                int b,w; scanf("%d%d",&b,&w);
                d[i][b] = w;
            }
        }
        for(int k = 1;k <= n;k++) {
            for(int i = 1;i <= n;i++) {
                for(int j = 1;j <= n;j++) {
                    d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
                }
            }
        }
        int ans = INF,ansi;
        for(int i = 1;i <= n;i++) {
            int maxv = -1;
            for(int j = 1;j <= n;j++) if(i != j) maxv = max(maxv,d[i][j]);
            if(maxv < ans) {
                ans = maxv; ansi = i;
            }
        }
        if(ans >= INF) puts("disjoint");
        else printf("%d %d\n",ansi,ans);
    }
    return 0;
}
