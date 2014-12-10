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
const int maxn = 205;
const int maxm = maxn * maxn;
const int INF = INT_MAX / 3;
int cap[maxn][maxn],flow[maxn][maxn],low[maxm];
int q[maxn],alpha[maxn],pre[maxn];
int uu[maxm],vv[maxm];
int n,m,s,t,qs,qe;

void solve() {
    memset(flow,0,sizeof(flow));
    while(1) {
        qs = qe = 0;
        for(int i = s;i <= t;i++) pre[i] = -2;
        pre[s] = -1; alpha[s] = INF;
        q[qe++] = s;
        while(qs < qe) {
            int now = q[qs++];
            for(int i = s;i <= t;i++) {
                if(cap[now][i] - flow[now][i] != 0 && pre[i] == -2) {
                    q[qe++] = i;
                    pre[i] = now; 
                    alpha[i] = min(alpha[now],cap[now][i] - flow[now][i]);
                }
            }
        }
        if(pre[t] == -2) break;
        for(int i = t;pre[i] != -1;i = pre[i]) {
            flow[pre[i]][i] += alpha[t];
            flow[i][pre[i]] -= alpha[t];
        }
    }
    bool ok = true;
    for(int i = s + 1;i <= t;i++) {
        if(cap[s][i] - flow[s][i]) ok = false;
    }
    for(int i = s;i < t;i++) if(cap[i][t] - flow[i][t]) ok = false;
    if(!ok) puts("NO");
    else {
        puts("YES");
        for(int i = 0;i < m;i++) {
            printf("%d\n",flow[uu[i]][vv[i]] + low[i]);
        }
    }
}

int main() {
    scanf("%d%d",&n,&m);
    s = 0; t = n + 1;
    memset(cap,0,sizeof(cap));
    for(int i = 0;i < m;i++) {
        int u,v,l,c; scanf("%d%d%d%d",&u,&v,&l,&c);
        low[i] = l;
        cap[u][v] += c - l;
        cap[s][v] += l;
        cap[u][t] += l;
        uu[i] = u; vv[i] = v;
    }
    solve();
    return 0;
}
