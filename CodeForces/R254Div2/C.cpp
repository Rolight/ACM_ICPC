#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 505;
int x[maxn],u,v,w;

int main() {
    int n,m; scanf("%d%d",&n,&m);
    double ans = 0;
    for(int i = 1;i <= n;i++) {
        scanf("%d",&x[i]);
    }
    for(int i = 1;i <= m;i++) {
        scanf("%d%d%d",&u,&v,&w);
        ans = max(ans,(double)(x[u] + x[v]) / (double)w);
    }
    printf("%.9lf\n",ans);
    return 0;
}
