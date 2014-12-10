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
const int maxm = 50000 + 5;
const LL INF = LONG_LONG_MAX / 4;
int v[maxm],w[maxm],first[maxn],nxt[maxm];
int n,m,C,cnt[maxn],ecnt;
LL d[maxn];
bool inq[maxn];

void solve() {
    bool bad = false;
    queue<int> q;
    q.push(n);
    for(int i = 0;i <= n;i++) {
        inq[i] = false;
        d[i] = INF;
        cnt[i] = 0;
    }
    d[n] = 0;
    inq[n] = true;
    cnt[n] = 1;
    while(!q.empty() && !bad) {
        int x = q.front(); q.pop();
        inq[x] = false;
        for(int i = first[x];i != -1;i = nxt[i]) {
            if(d[v[i]] > d[x] + w[i]) {
                d[v[i]] = d[x] + w[i];
                if(!inq[v[i]]) {
                    q.push(v[i]);
                    cnt[v[i]]++;
                    inq[v[i]] = true;
                    if(cnt[v[i]] > n + 1) {
                        bad = true; break;
                    }
                }
            }
        }
    }
    if(bad) puts("Bad Estimations");
    else printf("%lld\n",-d[0]);
}

void adde(int _u,int _v,int _w) {
    v[ecnt] = _v; w[ecnt] = _w;
    nxt[ecnt] = first[_u];
    first[_u] = ecnt;
    ecnt++;
}

int main() {
    while(~scanf("%d%d",&n,&m)) {
        ecnt = 0;
        memset(first,-1,sizeof(first));
        memset(nxt,-1,sizeof(nxt));
        for(int i = 1;i <= n;i++) {
           scanf("%d",&C);
           adde(i - 1,i,C);
           adde(i,i - 1,0);
        }
        for(int i = 1;i <= m;i++) {
            int a,b,c; scanf("%d%d%d",&a,&b,&c);
            adde(b,a - 1,-c);
        }
        solve();
    }
    return 0;
}
