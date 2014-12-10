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
const int maxn = 100 + 5;
const int maxk = maxn * maxn;
int fa[maxn],u[maxk],v[maxk],w[maxk],r[maxk],cnt;
int dist[maxn][maxn];
int findp(int a) {
    return a == fa[a] ? a : fa[a] = findp(fa[a]);
}
bool cmp(int a,int b) {
    return w[a] < w[b];
}

int main() {
    int n,ans;
    while(scanf("%d",&n) != EOF) {
        ans = cnt = 0;
        for(int i = 1;i <= n;i++) fa[i] = i;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                scanf("%d",&dist[i][j]);
            }
        }
        int Q; scanf("%d",&Q);
        for(int i = 1;i <= Q;i++) {
            int a,b; scanf("%d%d",&a,&b);
            dist[a][b] = dist[b][a] = 0;
        }
        for(int i = 1;i <= n;i++) {
            for(int j = i + 1;j <= n;j++) {
                u[cnt] = i; v[cnt] = j; r[cnt] = cnt;
                w[cnt] = dist[i][j];
                cnt++;
            }
        }
        sort(r,r + cnt,cmp);
        for(int i = 0;i < cnt;i++) {
            int pa = findp(u[r[i]]),pb = findp(v[r[i]]);
            if(pa == pb) continue;
            fa[pa] = pb;
            ans += w[r[i]];
        }
        printf("%d\n",ans);
    }
    return 0;
}
