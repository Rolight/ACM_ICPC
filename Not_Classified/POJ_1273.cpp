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
const int maxm = 205;
const int INF = INT_MAX / 2;
LL flow[maxn][maxn],C[maxn][maxn];
int n,m;

void input() {
    memset(C,0,sizeof(C));
    for(int i = 1;i <= m;i++) {
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        C[a][b] += c;
    }
}

LL alpha[maxn];
int pre[maxn];
int q[maxn + 20],qs,qe;

void solve() {
    int s = 1,t = n;
    memset(flow,0,sizeof(flow));
    while(1) {
        for(int i = s + 1;i <= t;i++) pre[i] = -2;
        pre[s] = -1;
        qs = 0; qe = 1; q[qs] = s;
        alpha[s] = 1e13;
        while(qs < qe && pre[t] == -2) {
            int v = q[qs]; qs++;
            for(int i = s;i <= t;i++) {
                if(pre[i] == -2 && C[v][i] - flow[v][i] != 0) {
                    alpha[i] = min(alpha[v],C[v][i] - flow[v][i]);
                    pre[i] = v;
                    q[qe++] = i;
                }
            }
        }
        if(pre[t] == -2) break;
        for(int i = t;pre[i] != -1;i = pre[i]) {
            flow[pre[i]][i] += alpha[t];
            flow[i][pre[i]] = -flow[pre[i]][i];
        }
    }
    LL ans = 0;
    for(int i = s;i < t;i++) ans += flow[i][t];
    printf("%lld\n",ans);
}

int main() {
    while(scanf("%d%d",&m,&n) != EOF) {
        input();
        solve();
    }
    return 0;
}
