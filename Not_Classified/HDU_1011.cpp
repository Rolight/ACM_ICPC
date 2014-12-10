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
const int maxn = 105;
const int maxv = 505;
int cost[maxn],val[maxn];
VI ch[maxn];
//dp(i,j)表示到第i个点，还剩j能量最大的possible
int dp[maxn][maxv],N,M,V,ccnt[maxn];
int vis[maxn];

void dfs(int now) {
    int m = ch[now].size();
    vis[now] = true;
    for(int i = cost[now];i <= V;i++) dp[now][i] = val[now];
    //枚举每个子节点
    for(int i = 0;i < m;i++) {
        int nc = ch[now][i];
        if(vis[nc]) continue;
        dfs(nc);
        //当前节点的j
        for(int j = V;j >= cost[j];j--) {
            //分给当前儿子的能量,最多j - cost[j]
            for(int k = 0;k <= j - cost[now];k++) {
                dp[now][j] = max(dp[nc][k] + dp[now][j - k],
                        dp[now][j]);
            }
        }
    }
    /*
    for(int i = 0;i <= V;i++) {
        printf("%d %d %d\n",now,i,dp[now][i]);
    }
    */
}


int main() {
    while(scanf("%d%d",&N,&M),~N) {
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        for(int i = 1;i <= N;i++) {
            ch[i].clear();
            scanf("%d%d",&cost[i],&val[i]);
            cost[i] = (cost[i] + 19) / 20;
        }
        for(int i = 1;i < N;i++) {
            int a,b; scanf("%d%d",&a,&b);
            ch[a].PB(b); ch[b].PB(a);
        }
        if(M == 0) {
            puts("0"); continue;
        }
        V = M;
        dfs(1);
        printf("%d\n",dp[1][V]);
    }
    return 0;
}
