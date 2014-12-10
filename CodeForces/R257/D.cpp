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
const int maxn = 100000 + 5;
const int maxm = 600000 + 5 + maxn;
const LL INF = LONG_LONG_MAX / 4;
LL u[maxm],v[maxm],w[maxm],cnt;
bool r[maxm],inq[maxn],used[maxn],have[maxn];
int n,m,k;
int first[maxn],nxt[maxm];
LL d[maxn];

void adde(int _u,int _v,int _w,bool flag) {
    ++cnt;
    r[cnt] = flag;
    u[cnt] = _u; v[cnt] = _v; w[cnt] = _w;
    nxt[cnt] = first[_u];
    first[_u] = cnt;
}

struct Pair {
    LL di,i;
    bool operator < (const Pair &x) const {
        return di > x.di;
    }
};

void solve() {
    //dijkstra
    priority_queue<Pair> q;
    for(int i = 1;i <= n;i++) d[i] = INF;
    memset(inq,0,sizeof(inq));
    q.push((Pair){0,1});
    d[1] = 0;
    while(!q.empty()) {
        Pair now = q.top(); q.pop();
        int x = now.i;
        if(inq[x]) continue;
        inq[x] = true;
        for(int i = first[x];i != 0;i = nxt[i]) {
            if(d[v[i]] >= d[x] + w[i]) {
                if(r[i]  && d[v[i]] > d[x] + w[i]) {
                    used[v[i]] = true;
                }
                if(!r[i]) used[v[i]] = false;
                d[v[i]] = d[x] + w[i];
                q.push((Pair){d[v[i]],v[i]});
            }
        }
    }
    int ans = k;
    for(int i = 1;i <= n;i++) if(used[i]) ans--;
    printf("%d\n",ans);
}


int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i <= m;i++) {
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        adde(a,b,c,false);
        adde(b,a,c,false);
    }   
    for(int i = 1;i <= k;i++) {
        int b,c; scanf("%d%d",&b,&c);
        adde(1,b,c,true);
    }
    solve();
    return 0;
}