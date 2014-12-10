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
const int maxn = 3000 + 5;
//dp(i,j) 第i个节点找到j个客户的最大收益
int dp[maxn][maxn],N,M;
int first[maxn],nxt[maxn],w[maxn],v[maxn],ecnt;
int P[maxn],ccnt[maxn];

void adde(int uu,int vv,int ww) {
    w[ecnt] = ww; v[ecnt] = vv; nxt[ecnt] = first[uu]; first[uu] = ecnt++;
}

int getcnt(int now) {
    if(first[now] == -1) return ccnt[now] = 1;
    for(int i = first[now];~i;i = nxt[i]) {
        ccnt[now] += getcnt(v[i]);
    }
    return ccnt[now];
}

void dfs(int now) {
    //printf("now is %d\n",now);
    if(first[now] == -1) {
        //如果当前为叶子节点
        dp[now][0] = 0; dp[now][1] = P[now];
    }
    else {
        for(int i = first[now];~i;i = nxt[i]) {
            dfs(v[i]);
            //更新所有状态,01背包
            for(int j = ccnt[now];j >= 0;j--) {
                //枚举是从下一个节点拿几个,这里注意是01背包，从大到小更新
                for(int k = 0;k <= ccnt[v[i]] && k <= j;k++) {
                    dp[now][j] = max(dp[now][j],
                            dp[v[i]][k] + dp[now][j - k] - w[i]);
                    //printf("k is %d %d + %d - %d\n",k,dp[v[i]][k],dp[now][j - k],w[i]);
                }
                //printf("dp[%d][%d] = %d\n",now,j,dp[now][j]);
            }
        }
    }
}


int main() {
    while(scanf("%d%d",&N,&M) != EOF) {
        memset(first,-1,sizeof(first));
        memset(ccnt,0,sizeof(ccnt));
        ecnt = 0;
        for(int i = 1;i <= N - M;i++) {
            int k; scanf("%d",&k);
            for(int j = 1;j <= k;j++) {
                int ak,ck; scanf("%d%d",&ak,&ck);
                adde(i,ak,ck);
            }
        }
        for(int i = N - M + 1;i <= N;i++) scanf("%d",&P[i]);
        getcnt(1);
        for(int i = 1;i <= N;i++) {
            for(int j = 0;j <= ccnt[i];j++) dp[i][j] = -INF;
            dp[i][0] = 0;
        }
        dfs(1);
        int ans = 0;
        for(int i = 0;i <= ccnt[1];i++) if(dp[1][i] >= 0) ans = i;
        printf("%d\n",ans);
    }
    return 0;
}
