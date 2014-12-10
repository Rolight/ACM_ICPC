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
const int maxn = 105;
double d[maxn][maxn];
int n,m;

int main() {
    while(scanf("%d",&n),n) {
        scanf("%d",&m);
        memset(d,0,sizeof(d));
        for(int i = 1;i <= m;i++) {
            int a,b,c; scanf("%d%d%d",&a,&b,&c);
            d[a][b] = d[b][a] = max(d[a][b],(double)c);
        }
        for(int k = 1;k <= n;k++) {
            for(int i = 1;i <= n;i++) {
                for(int j = 1;j <= n;j++) {
                    d[i][j] = max(d[i][j],d[i][k] * d[k][j] / 100);
                }
            }
        }
        printf("%.6lf percent\n",d[1][n]);
    }
    return 0;
}
