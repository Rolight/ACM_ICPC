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
const int maxn = 2000;
const int maxm = 6e5;
const int INF = INT_MAX / 4;
int first[maxn],nxt[maxm],d[maxn],qcnt[maxn];
int n,v[maxm],w[maxm],ecnt,last[maxn];
bool inq[maxn];
char buf[1024];

void adde(int uu,int vv,int ww) {
    //printf("add %d %d %d\n",uu,vv,ww);
    v[ecnt] = vv; w[ecnt] = ww;
    nxt[ecnt] = first[uu];
    first[uu] = ecnt;
    ecnt++;
}

bool spfa(int str) {
    bool bad = false;
    queue<int> q;
    for(int i = 0;i <= n;i++) {
        d[i] = -INF;
        inq[i] = false;
        qcnt[i] = 0;
    }
    q.push(str);
    qcnt[str] = 1;
    d[str] = 0;
    inq[str] = true;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        inq[x] = false;
        for(int i = first[x];i != -1;i = nxt[i]) {
            if(d[v[i]] < d[x] + w[i]) {
                d[v[i]] = d[x] + w[i];
                if(!inq[v[i]]) {
                    qcnt[v[i]]++;
                    inq[v[i]] = true;
                    q.push(v[i]);
                    if(qcnt[v[i]] > n + 1) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void solve() {
    if(spfa(0) == false) puts("impossible");
    else {
        for(int i = 1;i <= n;i++) {
            printf("%d %d\n",i,d[i]);
        }
    }
}

int main() {
    int kase = 1;
    while(scanf("%d",&n),n) {
        printf("Case %d:\n",kase++);
        memset(first,-1,sizeof(first));
        memset(nxt,-1,sizeof(nxt));
        ecnt = 0;
        for(int i = 1;i <= n;i++) {
            scanf("%d",&last[i]);
        }
        while(scanf("%s",buf),buf[0] != '#') {
            int a,b; scanf("%d%d",&a,&b);
            if(strcmp(buf,"SAF") == 0) adde(b,a,last[b]);
            if(strcmp(buf,"FAF") == 0) adde(b,a,last[b] - last[a]);
            if(strcmp(buf,"SAS") == 0) adde(b,a,0);
            if(strcmp("FAS",buf) == 0) adde(b,a,-last[a]);
        }
        //建立超级源点
        for(int i = 1;i <= n;i++) {
            adde(0,i,0);
        }
        solve();
        puts("");
    }
    return 0;
}
