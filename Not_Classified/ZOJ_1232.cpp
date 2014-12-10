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
const int maxn = 105;
const int maxm = maxn * maxn * 4;
const int INF = INT_MAX / 4;
int first[maxn],nxt[maxm],v[maxm],w[maxm],d[maxn][maxn];
int A,B,M,L,K,N,dp[maxn][maxn],cnt;
bool inq[maxn];

void spfa_nocastle(int str,int *d) {
    memset(inq,0,sizeof(inq));
    queue<int> q;
    q.push(str);
    for(int i = 1;i <= N;i++) d[i] = INF;
    d[str] = 0;
    inq[str] = true;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        inq[x] = false;
        for(int i = first[x];i != 0;i = nxt[i]) {
            if(d[v[i]] > d[x] + w[i]) {
                d[v[i]] = d[x] + w[i];
                if((v[i] <= A || v[i] == str) && !inq[v[i]]) {
                    q.push(v[i]);
                    inq[v[i]] = true;
                }
            }
        }
    }
}

void adde(int _u,int _v,int _w) {
    cnt++;
    v[cnt] = _v;
    w[cnt] = _w;
    nxt[cnt] = first[_u];
    first[_u] = cnt;
}

void solve() {
    memset(inq,0,sizeof(inq));
    queue<int> q;
    q.push(1);
    inq[1] = true;
    for(int i = 0;i <= N;i++) {
        for(int j = 0;j <= K;j++) {
            dp[i][j] = INF;
        }
    }
    dp[1][0] = 0;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        inq[x] = false;
        for(int i = 0;i <= K;i++) {
            //不用鞋子
            for(int j = first[x];j != 0;j = nxt[j]) {
                if(dp[v[j]][i] > dp[x][i] + w[j]) {
                    dp[v[j]][i] = dp[x][i] + w[j];
                    if(!inq[v[j]]) {
                        q.push(v[j]);
                        inq[v[j]] = true;
                    }
                }
            }
            if(i == 0) continue;
            //用鞋子
            for(int j = 1;j <= N;j++) if(j != x && d[x][j] <= L) {
                if(dp[j][i] > dp[x][i - 1]) {
                    dp[j][i] = dp[x][i - 1];
                    if(!inq[j]) {
                        inq[j] = true;
                        q.push(j);
                    }
                }
            }
        }
    }
    int ans = INF;
    for(int i = 0;i <= K;i++) ans = min(ans,dp[N][i]);
    printf("%d\n",ans);
}

int main() {
    int T; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++) {
        memset(first,0,sizeof(first));
        memset(nxt,0,sizeof(nxt));
        scanf("%d%d%d%d%d",&A,&B,&M,&L,&K);
        cnt = 0;
        N = A + B;
        for(int i = 1;i <= M;i++) {
            int u,v,w; scanf("%d%d%d",&u,&v,&w);
            adde(u,v,w);
            adde(v,u,w);
        }
        for(int i = 1;i <= N;i++) spfa_nocastle(i,d[i]);
        /*
        for(int i = 1;i <= N;i++) {
            for(int j = 1;j <= N;j++) {
                if(d[i][j] < INF) printf("%d  ",d[i][j]);
                else printf("X  ");
            }
            putchar('\n');
        }
        */
        solve();
    }
    return 0;
}
