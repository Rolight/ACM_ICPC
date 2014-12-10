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
const int maxn = 1000 + 5;
const int INF = INT_MAX / 2;
const int maxm = 100000 + 5;
int first[maxn],nxt[maxm],u[maxm],v[maxm],w[maxm];
int N,M,X,d1[maxn],d2[maxn];
bool vis[maxn];

void spfa(int *v,int *d) {
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= N;i++) d[i] = INF;
    d[X] = 0;
    queue<int> q;
    q.push(X);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for(int i = first[u];i != 0;i = nxt[i]) {
            if(d[v[i]] > d[u] + w[i]) {
                d[v[i]] = d[u] + w[i];
                if(!vis[v[i]]) {
                    vis[v[i]] = true;
                    q.push(v[i]);
                }
            }
        }
    }
}

void adde(int u,int i) {
    nxt[i] = first[u];
    first[u] = i;
}

int main() {
    while(scanf("%d%d%d",&N,&M,&X) != EOF) {
        memset(first,0,sizeof(first));
        memset(nxt,0,sizeof(nxt));
        for(int i = 1;i <= M;i++) {
            scanf("%d%d%d",&u[i],&v[i],&w[i]);
            adde(u[i],i);
        }
        spfa(v,d1);
        memset(first,0,sizeof(first));
        memset(nxt,0,sizeof(nxt));
        for(int i = 1;i <= M;i++) {
            adde(v[i],i);
        }
        spfa(u,d2);
        int ans = 0;
        for(int i = 1;i <= N;i++) ans = max(ans,d1[i] + d2[i]);
        printf("%d\n",ans);
    }
    return 0;
}
