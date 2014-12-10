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
const int maxn = 200000 + 5;
int dp[maxn][2];
int first[maxn],nxt[maxn * 2],w[maxn * 2],v[maxn * 2],ecnt;
bool vis[maxn];

void adde(int _u,int _v,int _w) {
    v[ecnt] = _v; w[ecnt] = _w; nxt[ecnt] = first[_u]; first[_u] = ecnt++;
    v[ecnt] = _u; w[ecnt] = _w ^ 1; nxt[ecnt] = first[_v]; first[_v] = ecnt++;
}

int dfs_root(int now) {
    int ret = 0;
    vis[now] = true;
    for(int i = first[now];~i;i = nxt[i]) if(!vis[v[i]]) {
        ret += dfs_root(v[i]) + w[i];
    }
    return dp[now][0] = ret;
}

void dfs_ch(int now,int prev,int eid) {
    vis[now] = true;
    if(prev != -1) {
        dp[now][1] = dp[prev][0] - w[eid] + w[eid ^ 1];
    }
    else dp[now][1] = dp[now][0];
    for(int i = first[now];~i;i = nxt[i]) if(!vis[v[i]]) {
        dfs_ch(v[i],now,i);
    }
}

int main() {
    memset(first,-1,sizeof(first));
    int n; scanf("%d",&n);
    for(int i = 1;i < n;i++) {
        int a,b; scanf("%d%d",&a,&b);
        adde(a,b,0);
    }
    dfs_root(1); 
    memset(vis,0,sizeof(vis));
    dfs_ch(1,-1,-1);
    int minval = INF;
    for(int i = 1;i <= n;i++) {
        printf("%d %d %d\n",i,dp[i][0],dp[i][1]);
    }
    //printf("%d\n",minval);
    return 0; 
}
