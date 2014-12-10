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
const int INF = INT_MAX / 4;
const int maxn = 305;
const int maxm = 3005;
int n,m,s,t;
int A[maxn],K[maxn][maxm],B[maxn];    //A为每个顾客有的钥匙数量，K为钥匙的类型,B为顾客的需求
int P[maxm],firstp[maxm];    //猪圈中猪的数量,每个猪圈的第一个客户
int dist[maxn][maxn];

void input() {
    for(int i = 1;i <= m;i++) {
        scanf("%d",&P[i]);
    }
    for(int i = 1;i <= n;i++) {
        scanf("%d",&A[i]);
        for(int j = 1;j <= A[i];j++) {
            scanf("%d",&K[i][j]);
        }
        scanf("%d",&B[i]);
    }
}

void init() {
    s = 0; t = n + 1;
    memset(firstp,0,sizeof(firstp));
    memset(dist,0,sizeof(dist));
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= A[i];j++) {
            if(firstp[K[i][j]] == 0) {
                firstp[K[i][j]] = i;
                dist[s][i] += P[K[i][j]];
            }
            else {
                dist[firstp[K[i][j]]][i] = INF;
                firstp[K[i][j]] = i;
            }
        }
        dist[i][t] = B[i];
    }
}

int flow[maxn][maxn];   //流量
int alpha[maxn],pre[maxn];      //每个点的可改进量和每个点的前驱
int q[maxn],qs,qe;      //队列

//Ford-Fulkerson
void solve() {
    memset(flow,0,sizeof(flow));
    alpha[s] = INF;
    while(1) {
        //初始化标号
        for(int i = 1;i <= t;i++) pre[i] = -2;
        pre[s] = -1;
        //初始化队列，源点入列
        qs = 0; qe = 1;
        q[qs] = s;
        //标号过程
        while(qs < qe && pre[t] == -2) {    //终点没有被标号并且队列非空
            int v = q[qs]; qs++;
            //printf("now v is %d\n",v);
            for(int i = 1;i <= t;i++) {
                //如果目标点没有被标号并且还有残余流量
                if(pre[i] == -2 && dist[v][i] - flow[v][i] != 0) {
                    pre[i] = v;
                    alpha[i] = min(alpha[v],dist[v][i] - flow[v][i]);
                    q[qe++] = i;
                }
            }
        }
        //没有找到到汇点的增广路，退出
        if(pre[t] == -2) {
            break;
        }
        //逆向更新
        int aval = alpha[t];
        for(int i = t;pre[i] != -1;i = pre[i]) {
            flow[pre[i]][i] += aval;
            flow[i][pre[i]] = -flow[pre[i]][i];
        }
    }
    //统计流量
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        ans += flow[i][t];
    }
    printf("%d\n",ans);
}

int main() {
    while(scanf("%d%d",&m,&n) != EOF) {
        input();
        init();
        solve();
    }
    return 0;
}
