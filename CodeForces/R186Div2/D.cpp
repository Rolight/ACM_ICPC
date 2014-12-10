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
const int maxn = 305;
const LL INF = 1e16;
LL cost[maxn][maxn],cnt[maxn][maxn];
int n,m,k;

int main() {
    int n,m,p;
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0;i <= n;i++) {
        for(int j = 0;j <= n;j++) {
            cost[i][j] = INF;
            cnt[i][j] = INF;
        }
        cnt[i][0] = 0;
    }
    for(int i = 0;i < m;i++) {
        int a,b,v; scanf("%d%d%d",&a,&b,&v);
        cost[a][b] = min(cost[a][b],(LL)v);
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j < i;j++) {
            cost[j + 1][i] = min(cost[j + 1][i],cost[j][i]);
        }
    }
    LL minval = INF;
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j <= i;j++) {
            cnt[i][j] = cnt[i - 1][j];
            for(int k = 1;k <= i;k++) if(j - i + k - 1 >= 0) {
                cnt[i][j] = min(cnt[i][j],cnt[k - 1][j - i + k - 1] + cost[k][i]);
            }
            if(j >= k) minval = min(minval,cnt[i][j]);
        }
    }
    if(minval == INF) minval = -1;
    cout << minval << endl;
    return 0;
}
