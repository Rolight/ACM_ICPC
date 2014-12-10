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
const int INF = INT_MAX / 3;

struct Edge {
    int u,v,cap;
    Edge(int u,int v,int cap):u(u),v(v),cap(cap) {}
};

int n,m,incnt[maxn],outcnt[maxn];
int deg[maxn],s,t;
vector<Edge> edges;
vector<int> e[maxn];

void adde(int u,int v,int w) {
    int m = edges.size();
    edges.push_back(Edge(u,v,w));
    edges.push_back(Edge(v,u,0));
    e[u].push_back(m);
    e[v].push_back(m ^ 1);
}

int level[maxn],q[maxn * 2],qs,qe;
bool bfs() {
    //建立层次网络
    memset(level,0,sizeof(level));
    level[s] = 1;
    qs = qe = 0;
    q[qe++] = s;
    while(qs < qe) {
        int now = q[qs++],nm = e[now].size();
        if(now == t) break;
        for(int i = 0;i < nm;i++) {
            Edge &ne = edges[e[now][i]];
            if(ne.cap && level[ne.v] == 0) {
                level[ne.v] = level[now] + 1;
                q[qe++] = ne.v;
            }
        }
    }
    return level[t];
}

int dfs(int now,int alpha) {
    if(now == t) return alpha;
    int sum = 0,nm = e[now].size();
    for(int i = 0;i < nm;i++) {
        Edge &ne = edges[e[now][i]];
        if(level[now] + 1 == level[ne.v] && ne.cap && alpha) {
            int ret = dfs(ne.v,min(alpha,ne.cap));
            ne.cap -= ret; edges[e[now][i] ^ 1].cap += ret;
            sum += ret; alpha -= ret;
        }
    }
    if(sum == 0) level[now] = -1;
    return sum;
}

void dinic() {
    while(bfs()) dfs(s,INF);
}

bool solve() {
    s = 0; t = n + 1;
    //判断入度出度之差是否为偶数
    for(int i = 1;i <= n;i++) {
        deg[i] = incnt[i] - outcnt[i];
        if(deg[i] & 1) return false;
    }
    //建立容量网络
    for(int i = 1;i <= n;i++) {
        //如果入度小于出度,建立从起点到这个点的边，容量为deg/2
        if(deg[i] < 0) adde(s,i,-deg[i] / 2);
        //如果出度大于入读，建立从当前点到汇点的边，容量同样为deg/2
        if(deg[i] > 0) adde(i,t,deg[i] / 2);
    }
    //计算最大流
    dinic();
    //判断从源点出发的所有边是否满流
    int m = e[s].size();
    for(int i = 0;i < m;i++) {
        if(edges[e[s][i]].cap != 0) return false;
    }
    return true;
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        edges.clear();
        for(int i = 0;i <= n + 1;i++) e[i].clear();
        memset(incnt,0,sizeof(incnt));
        memset(outcnt,0,sizeof(outcnt));
        for(int i = 1;i <= m;i++) {
            int u,v,c; scanf("%d%d%d",&u,&v,&c);
            //先将无向边全部作为有向边处理
            incnt[v]++; outcnt[u]++;
            //无向边存起来
            if(c == 0) adde(u,v,1);
        }
        if(solve()) puts("possible");
        else puts("impossible");
    }
    return 0;
}
