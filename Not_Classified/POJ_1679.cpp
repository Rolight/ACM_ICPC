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
const int maxk = 105 * 105;
struct Edge {
    int u,v,w;
    bool operator < (const Edge &x) const {
        return w < x.w;
    }
};
Edge e[maxk];
bool del[maxk],equ[maxk],used[maxk];
int n,m,fa[maxn];

int findp(int x) {
    return x == fa[x] ? x : fa[x] = findp(fa[x]);
}

int Kruskal(bool flag) {
    int ret = 0;
    for(int i = 1;i <= n;i++) fa[i] = i;
    for(int i = 0;i < m;i++) if(!del[i]) {
        int pa = findp(e[i].u),pb = findp(e[i].v);
        if(pa == pb) continue;
        if(flag) used[i] = true;
        fa[pa] = pb;
        ret += e[i].w;
    }
    return ret;
} 

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        memset(del,0,sizeof(del));
        memset(equ,0,sizeof(equ));
        memset(used,0,sizeof(used));
        for(int i = 0;i < m;i++) {
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        }
        sort(e,e + m);
        for(int i = 1;i < m;i++) {
            if(e[i].w == e[i - 1].w) {
                equ[i] = equ[i - 1] = true;
            }
        }
        int first = Kruskal(1);
        bool unique = true;
        for(int i = 0;i < m;i++) if(used[i] && equ[i]) {
            del[i] = true;
            int now = Kruskal(0);
            if(now == first) {
                unique = false;
                break;
            }
        }
        if(unique) printf("%d\n",first);
        else puts("Not Unique!");
    }
    return 0;
}
