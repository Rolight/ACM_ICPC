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
const int maxn = 25;
const int INF = INT_MAX / 4;
int d[maxn][maxn],n,m;

int main() {
    int kase = 1;
    while(scanf("%d",&m) != EOF) {
        printf("Test Set #%d\n",kase++);
        for(int i = 1;i <= 20;i++) {
            for(int j = 1;j <= 20;j++) {
                d[i][j] = INF;
            }
        }
        for(int i = 1;i <= m;i++) {
            int b; scanf("%d",&b);
            d[1][b] = d[b][1] = 1;
        }
        for(int i = 2;i <= 19;i++) {
            scanf("%d",&m);
            for(int j = 1;j <= m;j++) {
                int b; scanf("%d",&b);
                d[i][b] = d[b][i] = 1;
            }
        }
        for(int k = 1;k <= 20;k++) {
            for(int i = 1;i <= 20;i++) {
                for(int j = 1;j <= 20;j++) {
                    d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
                }
            }
        }
        scanf("%d",&n);
        for(int i = 1;i <= n;i++) {
            int a,b; scanf("%d%d",&a,&b);
            printf("%d to %d: %d\n",a,b,d[a][b]);
        }
        puts("");
    }
    return 0;
}
