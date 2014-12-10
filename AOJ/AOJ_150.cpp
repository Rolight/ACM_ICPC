#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 205;
const int INF = INT_MAX / 4;
int mp[maxn][maxn],d[maxn],vis[maxn];
int n,m,s,t;

int main() {
    while(~scanf("%d%d",&n,&m)) {
        memset(vis,false,sizeof(vis));
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                mp[i][j] = INF;
            }
        }
        for(int i = 1;i <= m;i++) {
            int a,b,c; scanf("%d%d%d",&a,&b,&c);
            mp[a][b] = mp[b][a] = c;
        }
        scanf("%d%d",&s,&t);
        for(int i = 1;i <= n;i++) {
            d[i] = INF;
        }
        d[s] = 0;
        for(int i = 1;i <= n;i++) {
            int x = INF,xi = -1;
            for(int j = 1;j <= n;j++) if(!vis[j] && d[j] < x) {
                x = d[j]; xi = j;
            }
            vis[xi] = true;
            for(int j = 1;j <= n;j++) if(!vis[j]) {
                d[j] = min(d[j],d[xi] + mp[xi][j]);
            }
        }
        if(d[t] >= INF || d[t] == 0) printf("-1");
        else printf("%d\n",d[t]);
    }
    return 0;
}

