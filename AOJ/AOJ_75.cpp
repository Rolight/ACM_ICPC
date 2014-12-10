#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 500;
int n, m;
int f[maxn][maxn], cost[maxn];

int dfs(int now, int rest) {
    if(now > n) return 0;
    int ncost = 0, ret = 0;
    if(f[now][rest] != -1) return f[now][rest];
    for(int i = now; i <= n && ncost + cost[i] <= rest; i++) {
        ncost += cost[i];
        int nret = dfs(i + 1, rest - ncost) + (i - now + 1) * (i - now + 1);
        ret = max(ret, nret);
    }
    for(int i = now + 1; i <= n; i++) {
        int nret = dfs(i, rest);
        ret = max(ret, nret);
    }
    return f[now][rest] = ret;
}

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        memset(f, -1, sizeof(f));
        for(int i = 1; i <= n; i++) scanf("%d", &cost[i]);
        printf("%d\n", dfs(1, m));
    }
    return 0;
}
