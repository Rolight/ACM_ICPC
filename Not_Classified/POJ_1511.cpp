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
const int maxn = 1000000 + 5;
const LL INF = 10000000005LL;
int u[maxn],v[maxn],w[maxn];
long long d[maxn];
int first[maxn],nxt[maxn];
bool vis[maxn];
int n,m;

void add(int _u,int id) {
    nxt[id] = first[_u];
    first[_u] = id;
}

struct Node {
    long long a;
    int b;
    Node(long long a,int b):a(a),b(b) {}
    bool operator < (const Node &x) const {
        return a > x.a;
    }
};

//优先队列优化的dijkstra
void dijkstra(int *v) {
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= n;i++) d[i] = INF;
    d[1] = 0;
    priority_queue<Node> q;
    q.push(Node(d[1],1));
    while(!q.empty()) {
        Node now = q.top(); q.pop();
        int x = now.b;
        if(vis[x]) continue;
        vis[x] = true;
        for(int i = first[x];i != 0;i = nxt[i]) {
            if(d[v[i]] > d[x] + w[i]) {
                d[v[i]] = d[x] + w[i];
                q.push(Node(d[v[i]],v[i]));
            }
        }
    }
}

int main() {
    int T; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++) {
        memset(first,0,sizeof(first));
        memset(nxt,0,sizeof(nxt));;
        long long ans = 0;
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= m;i++) {
            scanf("%d%d%d",&u[i],&v[i],&w[i]);
            add(u[i],i);
        }
        dijkstra(v);
        for(int i = 1;i <= n;i++) ans += d[i];
        memset(first,0,sizeof(first));
        memset(nxt,0,sizeof(nxt));
        for(int i = 1;i <= m;i++) {
            add(v[i],i);
        }
        dijkstra(u);
        for(int i = 1;i <= n;i++) ans += d[i];
        cout << ans << endl;
    }
    return 0;
}
