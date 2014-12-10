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
const int maxn = 15;
int n,dis[maxn][maxn];
int f[maxn][1 << maxn];

int dfs(int now,int state) {
    if(state == (1 << (n + 1)) - 1) return dis[now][0];
    if(f[now][state] != -1) return f[now][state];
    int ret = INF;
    for(int i = 0;i <= n;i++) if(!(state & (1 << i))) {
        ret = min(ret,dfs(i,state | (1 << i)) + dis[now][i]);
    }
    return f[now][state] = ret;
}

int main() {
    while(scanf("%d",&n),n) {
        memset(f,-1,sizeof(f));
        for(int i = 0;i <= n;i++) {
            for(int j = 0;j <= n;j++) {
                scanf("%d",&dis[i][j]);
            }
        }
        for(int k = 0;k <= n;k++) {
            for(int i = 0;i <= n;i++) {
                for(int j = 0;j <= n;j++) {
                    dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
                }
            }
        }
        int ret = dfs(0,1);
        printf("%d\n",ret);
    }
    return 0;
}
