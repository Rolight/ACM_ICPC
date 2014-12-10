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
int s[maxn][maxm];

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
        for(int i = 1;i <= n;i++) {
            f[i][1] = cost[1][i];
            s[i][1] = 1;
        }

        for(int i = 2;i <= n;i++) {
            int sj = min(i, m);
            s[i][sj + 1] = i - 1;
            for(int j = sj; j >= 2; j--) {
                for(int k = s[i - 1][j]; k <= s[i][j + 1]; k++) {
                    if(f[k][j - 1] + cost[k + 1][i] < f[i][j]) {
                        s[i][j] = k; 
                        f[i][j] = f[k][j - 1] + cost[k + 1][i];
                    }
                }
            }
        }
        printf("%d\n", f[n][m]);
    }
    return 0;
}


