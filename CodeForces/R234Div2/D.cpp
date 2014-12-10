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
const int maxk = 600;
const int INF = INT_MAX / 3;
int fa[maxn],c[maxk];
int n,m,k,mp[maxk][maxk];

int findp(int x) {
    return x == fa[x] ? x : fa[x] = findp(fa[x]);
}

inline int getid(int x) {
    return lower_bound(c + 1,c + 1 + k,x) - c;
}

void solve() {
    for(int p = 1;p <= k;p++)  {
        for(int i = 1;i <= k;i++) {
            for(int j = 1;j <= k;j++) {
                mp[i][j] = min(mp[i][j],mp[i][p] + mp[p][j]);
            }
        }
    }
    puts("Yes");
    for(int i = 1;i <= k;i++) {
        for(int j = 1;j <= k;j++) {
            if(j > 1) putchar(' ');
            if(mp[i][j] >= INF) printf("-1");
            else printf("%d",mp[i][j]);
        }
        puts("");
    }
} 

int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i <= k;i++) scanf("%d",&c[i]);
    for(int i = 1;i <= k;i++) c[i] += c[i - 1];
    for(int i = 1;i <= k;i++) {
        for(int j = 1;j <= k;j++) {
            mp[i][j] = INF;
        }
        mp[i][i] = 0;
    }
    for(int i = 1;i <= n;i++) fa[i] = i;
    int u,v,w,pa,pb,idu,idv;
    for(int i = 1;i <= m;i++) {
        scanf("%d%d%d",&u,&v,&w);
        if(w == 0) {
            pa = findp(u); pb = findp(v);
            if(pa != pb) fa[pa] = pb;
        }
        idu = getid(u); idv = getid(v);
        mp[idu][idv] = mp[idv][idu] = min(mp[idu][idv],w);
    }
    bool bad = false;
    for(int i = 1;i <= k;i++) {
        int nowfa = findp(c[i - 1] + 1);
        for(int j = c[i - 1] + 1;j <= c[i];j++) {
            if(findp(j) != nowfa) {
                bad = true; break;
            }
        }
        if(bad) break;
    }
    if(bad) puts("No");
    else solve();
    return 0;
}
