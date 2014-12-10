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
const int maxm = 10000 + 5;
const int maxn = 500 + 5;
const int INF = INT_MAX / 2;
int u[maxm],v[maxm],w[maxm],cnt;
int first[maxn],nxt[maxm];
int N,M,W,d[maxn],inq[maxn];
bool vis[maxn];

bool bellmanford() {
    //bellmanford判环原理是，如果经过了N轮操作还能继续松弛，则出现了负环
    for(int i = 1;i <= N;i++) {
        d[i] = INF;
    }
    d[1] = 0;
    for(int i = 1;i <= N;i++) {
        bool flag = false;
        for(int j = 1;j <= cnt;j++) {
            if(d[v[j]] > d[u[j]] + w[j]) {
                d[v[j]] = d[u[j]] + w[j];
                flag = true;
            }
        }
        //已经不能松弛了
        if(flag == false) return false;
    }
    for(int j = 1;j <= cnt;j++) {
        if(d[v[j]] > d[u[j]] + w[j]) return true;
    }
    return false;
}

bool spfa() {
    //spfa 的思想是，如果一个节点的入队次数大于N，那么肯定有负环
    memset(inq,0,sizeof(inq));
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= N;i++) d[i] = INF;
    d[1] = 0;
    queue<int> q;
    q.push(1);
    inq[1] = 1;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        vis[x] = false;
        for(int i = first[x];i != 0;i = nxt[i])  {
            if(d[v[i]] > d[x] + w[i]) {
                d[v[i]] = d[x] + w[i];
                if(!vis[v[i]]) {
                    q.push(v[i]);
                    inq[v[i]]++;
                    vis[v[i]] = true;
                    if(inq[v[i]] > N) return true;
                }
            }
        }
    }
    return false;
}

void adde(int _u,int _v,int _w) {  
    cnt++;
    u[cnt] = _u; v[cnt] = _v; w[cnt] = _w;
    nxt[cnt] = first[_u];
    first[_u] = cnt;
}

int main() {
    int F; scanf("%d",&F);
    while(F--) {
        memset(first,0,sizeof(first));
        memset(nxt,0,sizeof(nxt));
        cnt = 0;
        scanf("%d%d%d",&N,&M,&W);
        for(int i = 1;i <= M;i++) {
            int a,b,c; scanf("%d%d%d",&a,&b,&c);
            adde(a,b,c);
            adde(b,a,c);
        }
        for(int i = M + 1;i <= M + W;i++) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            adde(a,b,-c);
        }
        bool ret = spfa();
        if(ret) puts("YES");
        else puts("NO");
    }
    return 0;
}
