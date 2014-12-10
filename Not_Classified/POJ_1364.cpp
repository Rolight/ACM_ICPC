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
const int maxn = 105;
const int maxm = 5005;
int first[maxn],nxt[maxm],v[maxm],w[maxm];
int d[maxn],n,m,ecnt,cnt[maxn];
bool inq[maxn];

void adde(int _u,int _v,int _w) {
    v[ecnt] = _v; w[ecnt] = _w;
    nxt[ecnt] = first[_u];
    first[_u] = ecnt;
    ecnt++;
}

void solve() {
    bool bad = false;
    queue<int> q;
    for(int i = 0;i <= n;i++) {
        d[i] = 0;
        cnt[i] = 1;
        inq[i] = true;
        q.push(i);
    }
    while(!q.empty() && !bad) {
        int x = q.front(); q.pop();
        inq[x] = false;
        for(int i = first[x];i != -1;i = nxt[i]) {
            if(d[v[i]] > d[x] + w[i]) {
                if(!inq[v[i]]) {
                    inq[v[i]] = true;
                    cnt[v[i]]++;
                    q.push(v[i]);
                    if(cnt[v[i]] > n + 2) {
                        bad = true;
                        break;
                    }
                }
                d[v[i]] = d[x] + w[i];
            }
        }
    }
    if(bad) puts("successful conspiracy");
    else puts("lamentable kingdom");
}

int main() {
    while(scanf("%d",&n),n) {
        ecnt = 0;
        char sig[16];
        scanf("%d",&m);
        memset(first,-1,sizeof(first));
        memset(nxt,-1,sizeof(nxt));
        for(int i = 0;i < m;i++) {
            int a,b,c;
            scanf("%d %d %s %d",&a,&b,sig,&c);
            if(sig[0] == 'g') adde(b + a,a - 1,-c - 1);
            else adde(a - 1,b + a,c - 1);
        }
        /*
        for(int i = 1;i <= n;i++) {
            adde(i,i - 1,0);
        }
        */
        solve();
    }
    return 0;
}
