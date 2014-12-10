#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

typedef long long LL;
const int maxn = 305;
const int maxm = 55;
int f[maxn][maxm], pos[maxn], n, m, cost[maxn][maxn];

int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        for(int i = 1;i <= n;i++) {
            scanf("%d", &pos[i]);
        }

        memset(cost,0,sizeof(cost));
        for(int i = 1;i <= n;i++) {
            for(int j = i;j <= n;j++) {
                for(int k = i;k <= j;k++) {
                    cost[i][j] += abs(pos[k] - pos[(i + j) / 2]);
                }
            }
        }
        
        memset(f,0x3f,sizeof(f));
        int ans = INT_MAX;
        f[1][1] = 0; f[0][0] = 0;
        for(int i = 2;i <= n;i++) {
            for(int j = 1;j <= i && j <= m;j++) {
                for(int k = j - 1;k < i;k++) {
                    f[i][j] = min(f[i][j], f[k][j - 1] + cost[k + 1][i]);
                }
                if(i == n) ans = min(ans,f[i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}


