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
const int maxn = 800 + 5;
const int maxm = 80000;
const int INF = INT_MAX / 2;
int n,m,s,t;
int first[maxn],nxt[maxm];
int ecnt,v[maxm],cap[maxm];
int q[maxn],qs,qe;
bool vis[maxn];

void adde(int uu,int vv,int ww) {
    v[ecnt] = vv; cap[ecnt] = ww; nxt[ecnt] = first[uu]; first[uu] = ecnt++;
    v[ecnt] = uu; cap[ecnt] = 0; nxt[ecnt] = first[vv]; first[vv] = ecnt++;
}

int level[maxn];
bool bfs() {
    memset(level,0,sizeof(level));
    qs = qe = 0;
    q[qe++] = s;
    level[s] = 1;
    while(qs < qe) {
        int now = q[qs++];
        if(now == t) break;
        for(int i = first[now];~i;i = nxt[i]) {
            if(cap[i] && level[v[i]] == 0) {
                q[qe++] = v[i]; level[v[i]] = level[now] + 1;
            }
        }
    }
    return level[t];
}

int dfs(int now,int alpha) {
    if(now == t) return alpha;
    int sum = 0;
    for(int i = first[now];~i && alpha;i = nxt[i]) {
        if(cap[i] && level[v[i]] == level[now] + 1) {
            int ret = dfs(v[i],min(alpha,cap[i]));
            sum += ret; alpha -= ret;
            cap[i] -= ret; cap[i ^ 1] += ret;
        }
    }
    if(sum == 0) level[now] = -1;
    return sum;
}

void solve() {
    //先做一遍最大流   
    while(bfs()) dfs(s,INF);
    //分别从起点和终点做一遍bfs
    memset(vis,0,sizeof(vis));
    qs = qe = 0;
    q[qe++] = s;
    vis[s] = true;
    while(qs < qe) {
        int now = q[qs++];
        for(int i = first[now];~i;i = nxt[i]) {
            if(cap[i] && !vis[v[i]]) {
                vis[v[i]] = true; q[qe++] = v[i];
            }
        }
    }
    qs = qe = 0;
    q[qe++] = t;
    vis[t] = true;
    while(qs < qe) {
        int now = q[qs++];
        for(int i = first[now];~i;i = nxt[i]) {
            if(cap[i ^ 1] && !vis[v[i]]) {
                vis[v[i]] = true; q[qe++] = v[i];
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        if(!vis[i]) {
            puts("AMBIGUOUS");
            return;
        }
    }
    puts("UNIQUE");
}

int main() {
    while(scanf("%d%d%d%d",&n,&m,&s,&t),n) {
        memset(first,-1,sizeof(first));
        ecnt = 0;
        for(int i = 0;i < m;i++) {
            int a,b,c; scanf("%d%d%d",&a,&b,&c);
            adde(a,b,c); adde(b,a,c);
        }
        solve();
    }
    return 0;
}
