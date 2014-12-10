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
const int maxn = 25;
const int maxm = 4e3;
const int INF = INT_MAX / 4;
int first[maxn],nxt[maxm],w[maxm],v[maxm];
int d[maxn],n,cnt[maxn],ecnt,qcnt[maxn],a[maxn];
bool inq[maxn];

void adde(int a,int b,int c) {
    w[ecnt] = c; v[ecnt] = b;
    nxt[ecnt] = first[a];
    first[a] = ecnt;
    ecnt++;
}

bool bellmanford() {
    for(int i = 0;i <= 24;i++) d[i] = INF;
    d[0] = 0;
    for(int i = 0;i <= 24;i++) {
        for(int j = 0;j <= 24;j++) {
            for(int k = first[j];k != -1;k = nxt[k]) {
                if(d[v[k]] > d[j] + w[k]) {
                    d[v[k]] = d[j] + w[k];
                }
            }
        }
    }
    for(int i = 0;i <= 24;i++) {
        for(int j = first[i];j != -1;j = nxt[j]) {
            if(d[v[j]] > d[i] + w[j]) return false;
        }
    }
    return true;
}

bool ok(int sum) {
    int necnt = ecnt,tmpnxt[maxm],tmpfirst[maxn];
    memcpy(tmpnxt,nxt,sizeof(nxt));
    memcpy(tmpfirst,first,sizeof(first));
    for(int i = 0;i < 24;i++) {
        int j = (i + 7) % 24 + 1;
        if(j > i) adde(j,i,-a[j]);
        else adde(j,i,sum-a[j]);
    }
    //adde(0,24,sum);
    adde(24,0,-sum);
    bool ret = bellmanford();
    ecnt = necnt;
    memcpy(nxt,tmpnxt,sizeof(nxt));
    memcpy(first,tmpfirst,sizeof(first));
    return ret;
}

void solve() {
    int l = 0,r = n;
    while(l < r) {
        int mid = (l + r) >> 1;
        //printf("now is %d %d %d\n",l,r,mid);
        if(ok(mid)) r = mid;
        else l = mid + 1;
    }
    if(!ok(l)) puts("No Solution");
    else printf("%d\n",l);
}

int main() {
    //freopen("/tmp/in.txt","r",stdin);
    int T; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++) {
        ecnt = 0;
        memset(first,-1,sizeof(first));
        memset(nxt,-1,sizeof(nxt));
        memset(cnt,0,sizeof(cnt));
        for(int i = 1;i <= 24;i++) {
            scanf("%d",&a[i]);
        }
        scanf("%d",&n);
        for(int i = 1;i <= n;i++) {
            int str; scanf("%d",&str);
            cnt[str + 1]++;
        }
        for(int i = 1;i <= 24;i++) {
            adde(i - 1,i,cnt[i]);
            adde(i,i - 1,0);
        }
        solve();
    }
    return 0;
}
