#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

typedef long long LL;
const int maxn = 3e5 + 10;

struct Edge {
    int u,v,w;
    bool operator < (const Edge &x) const {
        return w < x.w;
    }
};

int f[maxn],n,m,val[maxn];
Edge e[maxn];

int main() {
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= m;i++) {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    int ans = 0;
    sort(e + 1,e + 1 + m);
    for(int i = 1;i <= m;i++) {
        int u = e[i].u,v = e[i].v,w = e[i].w;
        if(val[u] < w) {
            if(f[v] < f[u] + 1) {
                f[v] = f[u] + 1;
                val[v] = w;
            }
        }
        ans = max(ans,f[u]);
        ans = max(ans,f[v]);
    }
    printf("%d\n",ans);
    return 0;
}


