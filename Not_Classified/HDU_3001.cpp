#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <bitset>
#include <list>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <sstream>
#include <numeric>
#include <fstream>
#include <functional>

using namespace std;

#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 2;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 12;
const int maxs = 59049;
const int p3[maxn] = {1,3,9,27,81,243,729,2187,6561,19683,59049};
int n,m,dist[maxn][maxn];
int f[maxn][maxs + maxn];
int st[maxs + maxn][maxn];
bool sok[maxs + maxn][maxn];

inline void expand(int st,int *arr) {
    int pos = 0;
    while(st) {
        arr[pos++] = st % 3; st /= 3;
    }
}

inline bool ok(int s,int t) {
    for(int i = 0;i < t;i++) 
        if(st[s][i] == 0) return false;
    return true;
}


int main() {
    for(int i = 0;i <= maxs;i++) expand(i,st[i]);
    for(int i = 0;i <= maxs;i++) 
        for(int j = 0;j <= 10;j++) sok[i][j] = ok(i,j);
    while(~scanf("%d%d",&n,&m)) {
        memset(dist,-1,sizeof(dist));
        for(int i = 0;i < m;i++) {
            int u,v,w; scanf("%d%d%d",&u,&v,&w); u--; v--;
            dist[u][v] = dist[v][u] = (
                dist[u][v] == -1 ? w : min(dist[u][v],w));
        }
        for(int i = 0;i < n;i++) 
            for(int j = 0;j < p3[n];j++)
                f[i][j] = INF;
        int ans = INF;
        for(int i = 0;i < n;i++) f[i][p3[i]] = 0;
        for(int j = 0;j < p3[n];j++) {
            for(int i = 0;i < n;i++) if(f[i][j] < INF)  {
                for(int k = 0;k < n;k++) if(dist[k][i] != -1 && st[j][k] < 2) {
                    f[k][j + p3[k]] = min(f[k][j + p3[k]],f[i][j] + dist[k][i]);
                }
            }
        }
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < p3[n];j++) {
                if(sok[j][n]) {
                    ans = min(ans,f[i][j]);
                }
            }
        }
        if(ans >= INF) puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}
