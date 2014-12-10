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
const int maxn  = 105;
int n,np,nc,m; //n节点数目，np电站数目，nc消费者数目，m电线
int cap[maxn][maxn],s,t;        //cap 容量，s源点，t汇点
int level[maxn],q[maxn * 2],qs,qe;

void input() {
    memset(cap,0,sizeof(cap));
    s = 0; t = n + 1;
    for(int i = 0;i < m;i++) {
        int a,b,L; scanf(" (%d,%d)%d",&a,&b,&L);
        a++; b++;
        cap[a][b] = L;
    }
    for(int i = 0;i < np;i++) {
        int a,P; scanf(" (%d)%d",&a,&P); a++;
        cap[s][a] = P;
    }
    for(int i = 0;i < nc;i++) {
        int a,C; scanf(" (%d)%d",&a,&C); a++;
        cap[a][t] = C;
    }
    /*
    printf("\n%d %d\n",s,t);
    for(int i = s;i <= t;i++) {
        for(int j = s;j <= t;j++) {
            printf("%d ",cap[i][j]);
        }
        putchar('\n');
    }
    */
}


bool bfs() {
    qs = qe = 0;
    q[qe++] = s;
    memset(level,0,sizeof(level));
    level[s] = 1;
    while(qs < qe) {
        int v = q[qs++];
        if(v == t) break;
        for(int i = s;i <= t;i++) if(cap[v][i] && !level[i]) {
            level[i] = level[v] + 1;
            q[qe++] = i;
        }
    }
    return level[t];
}

int dinic(int now,int alpha) {
    int sum = 0;
    if(now == t) return alpha;
    for(int i = s;i <= t;i++) {
        if(level[i] == level[now] + 1 && alpha && cap[now][i]) {
            int ret = dinic(i,min(alpha,cap[now][i]));
            cap[now][i] -= ret;
            cap[i][now] += ret;
            alpha -= ret;
            sum += ret;
        }
    }
    return sum;
}

void solve() {
    int ans = 0;
    while(bfs()) ans += dinic(s,INT_MAX);
    printf("%d\n",ans);
}

int main() {
    while(scanf("%d%d%d%d",&n,&np,&nc,&m) != EOF) {
        input();
        solve();
    }
    return 0;
}
