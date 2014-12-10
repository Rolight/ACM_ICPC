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
const int maxn = 5e5 + 5;
const int maxm = maxn * 3;
const int INF = INT_MAX / 3;
int first[maxm],nxt[maxm],v[maxm],w[maxm];
int d[maxm],n,ecnt,m,ln;
bool vis[maxm];

struct Pair {
    int di,i;
    Pair(int di,int i):di(di),i(i) {}
    bool operator < (const Pair &x) const {
        return di > x.di;
    }
};

void adde(int _u,int _v,int _w) {
    v[ecnt] = _v; w[ecnt] = _w;
    nxt[ecnt] = first[_u];
    first[_u] = ecnt;
    ecnt++;
}

void solve() {
    for(int i = 0;i <= n;i++) {
        vis[i] = false;
        d[i] = INF;
    }
    d[n] = 0;
    vis[n] = true;
    queue<int> q;
    q.push(n);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        vis[x] = false;
        for(int i = first[x];i != -1;i = nxt[i]) {
            if(d[v[i]] > d[x] + w[i]) {
                d[v[i]] = d[x] + w[i];
                if(!vis[v[i]]) {
                    vis[v[i]] = true;
                    q.push(v[i]);
                }
            }
        }
    }
    //for(int i = ln - 1;i <= n;i++) printf("%d %d\n",i,d[i]); putchar('\n');
    printf("%d\n",-d[ln - 1]);
}

int main() {
    while(~scanf("%d",&m)) {
        n = 0; ln = INF;
        memset(first,-1,sizeof(first));
        memset(nxt,-1,sizeof(nxt));
        int a,b,c;
        for(int i = 1;i <= m;i++) {
            scanf("%d%d%d",&a,&b,&c);
            adde(b,a - 1,-c);
            n = max(n,b);
            ln = min(ln,a);
        }
        for(int i = ln;i <= n;i++) {
            adde(i,i - 1,0);
            adde(i - 1,i,1);
        }
        solve();
    }  
    return 0;
}
