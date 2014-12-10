#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <bitset>
#include <list>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <sstream>
#include <numeric>
#include <fstream>
#include <functional>

using namespace std;

#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 55;
const int maxt = 400;
int f[maxt][maxn], N, T;
int cost[maxn], M1, M2, d1[maxn], d2[maxn];
bool left_bus[maxn][maxt], right_bus[maxn][maxt];

int main() {
    int kase = 1;
    while(scanf("%d",&N), N) {
        memset(f,0x3f,sizeof(f));
        memset(cost,0,sizeof(cost));
        memset(left_bus,0,sizeof(left_bus));
        memset(right_bus,0,sizeof(right_bus));
        int inf = f[0][0];
        scanf("%d",&T);
        for(int i = 1;i < N;i++) scanf("%d",&cost[i]);
        scanf("%d",&M1);
        for(int i = 1;i <= M1;i++) scanf("%d",&d1[i]);
        scanf("%d",&M2);
        for(int i = 1;i <= M2;i++) scanf("%d",&d2[i]);
        for(int i = 1;i <= M1;i++) {
            int nowtime = d1[i];
            for(int j = 1;j <= N;j++) {
                left_bus[j][nowtime] = true;
                nowtime += cost[j];
            }
        }
        for(int i = 1;i <= M2;i++) {
            int nowtime = d2[i];
            for(int j = N;j >= 1;j--) {
                right_bus[j][nowtime] = true;
                nowtime += cost[j - 1];
            }
        }
        f[0][1] = 0;
        for(int i = 0;i <= T;i++) {
            for(int j = 1;j <= N;j++) {
                //wait
                f[i + 1][j] = min(f[i + 1][j],f[i][j] + 1);
                //go left_bus
                if(right_bus[j][i] && j > 1 && i + cost[j - 1] <= T) {
                    f[i + cost[j - 1]][j - 1] = min(f[i + cost[j - 1]][j - 1],
                            f[i][j]);
                }
                //go right_bus
                if(left_bus[j][i] && j < N && i + cost[j] <= T) {
                    f[i + cost[j]][j + 1] = min(f[i + cost[j]][j + 1],
                            f[i][j]);
                }
            }
        }
        printf("Case Number %d: ",kase++);
        if(f[T][N] == inf) puts("impossible");
        else printf("%d\n",f[T][N]);
    }
    return 0;
}
