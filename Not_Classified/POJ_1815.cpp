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

using namespace std;

typedef long long LL;
const int maxn = 405;
const int INF = INT_MAX / 2;
int N,S,T,cap[maxn][maxn],flow[maxn][maxn],s,t;
int mp[maxn][maxn];

void build_graph() {
    memset(cap,0,sizeof(cap));
    s = 0; t = 2 * N + 1;
    cap[s][S] = INF;
    cap[T + N][t] = INF;
    for(int i = 1;i <= N;i++) {
        cap[i][i + N] = 1;
        for(int j = 1;j <= N;j++) if(mp[i][j] && i != j) {
            cap[i + N][j] = INF;
        }
    } 
    cap[S][S + N] = cap[T][T + N] = INF;
}

int level[maxn],q[maxn],qs,qe;
bool bfs() {
    memset(level,0,sizeof(level));
    qs = qe = 0;
    q[qe++] = s;
    level[s] = 1;
    while(qs < qe) { int now = q[qs++]; if(now == t) break;
        for(int i = s;i <= t;i++) {
            if(cap[now][i] - flow[now][i] && !level[i]) {
                q[qe++] = i; level[i] = level[now] + 1;
            }
        }
    }
    return level[t];
}

int dfs(int now,int alpha) {
    if(now == t) return alpha;
    int sum = 0;
    for(int i = s;i <= t && alpha;i++) {
        if(cap[now][i] - flow[now][i] && level[now] + 1 == level[i]) {
            int ret = dfs(i,min(alpha,cap[now][i] - flow[now][i]));
            flow[now][i] += ret; flow[i][now] -= ret;
            sum += ret; alpha -= ret;
        }
    }
    //printf("now is %d,sum is %d\n",now,sum);
    if(sum == 0) level[now] = -1;
    return sum;
}

void solve() {
    if(cap[S + N][T]) {
        puts("NO ANSWER!");
        return;
    }
    int ansval = 0,cnt = 0;
    while(bfs()) ansval += dfs(S,INF);
    printf("%d\n",ansval);
    //开始枚举
    for(int i = 1;i <= N;i++) if(i != S && i != T) {
        memset(flow,0,sizeof(flow));
        cap[i][i + N] = 0;
        int nowans = 0;
        while(bfs()) nowans += dfs(S,INF);
        if(nowans != ansval) {
            if(cnt != 0) putchar(' ');
            printf("%d",i);
            ansval = nowans;
            cnt++;
        } else cap[i][i + N] = 1;
        if(ansval == 0) break;
    }
    if(cnt) puts("");
}

int main() {
    while(~scanf("%d%d%d",&N,&S,&T)) {
        for(int i = 1;i <= N;i++) {
            for(int j = 1;j <= N;j++) {
                scanf("%d",&mp[i][j]);
            }
        }
        build_graph();
        solve();
    }
    return 0;
}
