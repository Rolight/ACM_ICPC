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
const int maxn = 10000 + 5;
const int maxm = 500000 + 5;
const int INF = INT_MAX / 4;
int first[maxn],nxt[maxm],d[maxn],v[maxm],w[maxm];
int N,ML,MD,qcnt[maxn],ecnt;
bool inq[maxn];

void adde(int _u,int _v,int _w) {
    //printf("adde %d %d %d\n",_u,_v,_w);
    v[ecnt] = _v;   w[ecnt] = _w;
    nxt[ecnt] = first[_u];
    first[_u] = ecnt;
    ecnt++;
}

void solve() {
    bool bad = false;
    for(int i = 0;i <= N;i++) {
        d[i] = INF;
        inq[i] = false;
        qcnt[i] = 0;
    }
    d[1] = 0;
    inq[1] = true;
    queue<int> q;
    q.push(1);
    qcnt[1] = 1;
    while(!q.empty() && !bad) {
        int x = q.front(); q.pop();
        inq[x] = false;
        for(int i = first[x];i != -1;i = nxt[i]) {
            if(d[v[i]] > d[x] + w[i]) {
                d[v[i]] = d[x] + w[i];
                if(!inq[v[i]]) {
                    q.push(v[i]);
                    inq[v[i]] = true;
                    qcnt[v[i]]++;
                    if(qcnt[v[i]] > N + 1) {
                        bad = true; break;
                    }
                }
            }
        }
    }
    //for(int i = 0;i <= N;i++) printf("%d ",d[i]); putchar('\n');
    //for(int i = 0;i <= N;i++) printf("%d ",qcnt[i]); putchar('\n');
    if(bad == true) puts("-1");
    else if(d[N] >= INF) puts("-2");
    else printf("%d\n",d[N]);
}

int main() {
    while(~scanf("%d%d%d",&N,&ML,&MD)) {
        ecnt = 0;
        memset(first,-1,sizeof(first));
        memset(nxt,-1,sizeof(nxt));
        for(int i = 1;i <= ML;i++) {
            int a,b,c; scanf("%d%d%d",&a,&b,&c);
            adde(a,b,c);
        }
        for(int i = 1;i <= MD;i++) {
            int a,b,c; scanf("%d%d%d",&a,&b,&c);
            adde(b,a,-c);
        }
        for(int i = 1;i <= N;i++) {
            adde(i,i - 1,0);
        }
        solve();
    }
    return 0;
}
