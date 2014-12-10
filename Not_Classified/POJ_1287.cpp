#include <cstdio>
#include <cstring>
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
const int maxn = 55;
const int maxk = 3000;
int fa[maxn],u[maxk],v[maxk],w[maxk],r[maxk];
int findp(int x) {
    return x == fa[x] ? x : fa[x] = findp(fa[x]);
}
bool cmp(int a,int b) {
    return w[a] < w[b];
}

int main() {
    int n,m;
    while(scanf("%d",&n),n) {
        scanf("%d",&m);
        for(int i = 1;i <= n;i++) fa[i] = i;
        for(int i = 0;i < m;i++) scanf("%d%d%d",&u[i],&v[i],&w[i]),r[i] = i;
        sort(r,r + m,cmp);
        int ans = 0;
        for(int i = 0;i < m;i++) {
            int pa = findp(u[r[i]]),pb = findp(v[r[i]]);
            if(pa == pb) continue;
            fa[pa] = pb;
            ans += w[r[i]];
        } 
        printf("%d\n",ans);
    }
    return 0;
}
