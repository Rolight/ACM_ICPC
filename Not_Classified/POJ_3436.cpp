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
const int maxp = 15;
const int maxn = 55;
const int INF = INT_MAX / 5;
int mcin[maxp][maxn],mcout[maxp][maxn];
int cap[maxn][maxn],flow[maxn][maxn],Q[maxn];
int p,n,s,t;

void input() {
    memset(cap,0,sizeof(cap));
    for(int i = 1;i <= n;i++) {
        scanf("%d",&Q[i]);
        for(int j = 1;j <= p;j++)
            scanf("%d",&mcin[i][j]);
        for(int j = 1;j <= p;j++) {
            scanf("%d",&mcout[i][j]);
        }
    }
    s = 0,t = n + 1;
}

bool cantrans(int a,int b) {
    for(int i = 1;i <= p;i++) {
        if(mcout[a][i] == 1 && mcin[b][i] == 0) return false; 
        if(mcout[a][i] == 0 && mcin[b][i] == 1) return false;
    }
    return true;
}

void build_graph() {
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) if(i != j) {
            if(cantrans(i,j) && j != s) {
                cap[i][j] = Q[i];
            } else cap[i][j] = 0;
        }
    }
    for(int i = 1;i <= n;i++) {
        int sumout = 0,sumin = 0;
        for(int j = 1;j <= p;j++) {
            sumout += mcout[i][j];
            sumin += mcin[i][j];
        }
        if(sumin == 0 || sumin == 2 * p) cap[s][i] = Q[i];
        if(sumout == p) cap[i][t] = Q[i];
    }
}

int q[maxn * 2],qs,qe;
int pre[maxn],alpha[maxn];
void solve() {
    build_graph();
    memset(flow,0,sizeof(flow));
    while(1) {
        qs = qe = 0;
        q[qe++] = s;
        for(int i = s;i <= t;i++) pre[i] = -2;
        pre[s] = -1; alpha[s] = INF;
        while(qs < qe) {
            int now = q[qs++];
            for(int i = s;i <= t;i++) if(cap[now][i] - flow[now][i] && pre[i] == -2) {
                q[qe++] = i; pre[i] = now; 
                alpha[i] = min(alpha[now],cap[now][i] - flow[now][i]);
            }
        }
        if(pre[t] == -2) break;
        for(int i = t;pre[i] != -1;i = pre[i]) {
            flow[pre[i]][i] += alpha[t];
            flow[i][pre[i]] -= alpha[t];
        }
    }
    int ans = 0,ecnt = 0;
    for(int i = 1;i <= n;i++) ans += flow[i][t];
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(flow[i][j] > 0) ecnt++;
        }
    }
    printf("%d %d\n",ans,ecnt);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(flow[i][j] > 0) printf("%d %d %d\n",i,j,flow[i][j]);
        }
    }
}

int main() {
    while(scanf("%d%d",&p,&n) != EOF) {
        input();
        solve();
    }
    return 0;
}
