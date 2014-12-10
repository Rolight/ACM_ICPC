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
const int maxn = 14;
const int INF = INT_MAX / 3;
int n,m,dist[maxn][maxn];
LL v[maxn];
LL f[maxn][maxn][1 << 14];
LL cnt[maxn][maxn][1 << 14];

void solve() {
    memset(f,-1,sizeof(f));
    memset(cnt,0,sizeof(cnt));
    int maxstate = (1 << n) - 1; //init
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) if(dist[i][j]) {
            int s = (1 << i) | (1 << j);
            f[i][j][s] = v[i] * v[j] + v[i] + v[j];
            cnt[i][j][s] = 1;
        }
    }
    //dp
    LL ans = 0,ct = 0;
    for(int s = 0;s <= maxstate;s++) {
        for(int i = 0;i < n;i++) if(s & (1 << i)) {
            for(int j = 0;j < n;j++) if(dist[i][j] && (s & (1 << j)) && f[i][j][s] != -1) {
                for(int k = 0;k < n;k++) if(dist[j][k] && !(s & (1 << k))) {
                    int ns = s | (1 << k);
                    LL &nowstate = f[i][j][s],&nextstate = f[j][k][ns];
                    LL &nowcnt = cnt[i][j][s],&nextcnt = cnt[j][k][ns];
                    LL addv = v[j] * v[k] + v[k];
                    if(dist[i][k]) addv += v[i] * v[j] * v[k];
                    if(nowstate + addv > nextstate) {
                        nextstate = nowstate + addv;
                        nextcnt = nowcnt;
                    }
                    else if(nowstate + addv == nextstate) {
                        nextcnt += nowcnt;
                    }
                }
                if(s == maxstate) {
                    if(f[i][j][s] > ans) {
                        ans = f[i][j][s];
                        ct = cnt[i][j][s];
                    }
                    else if(f[i][j][s] == ans) {
                        ct += cnt[i][j][s];
                    }
                }
            }
        }
    }
    if(ans == 0) cout << "0 0" << endl;
    else cout << ans << " " << ct / 2 <<  endl;
}

int main() {
    //freopen("in.txt","r",stdin);
    int T; scanf("%d",&T);
    while(T--) {
        memset(dist,0,sizeof(dist));
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n;i++) cin >> v[i];
        for(int i = 0;i < m;i++) {
            int a,b; cin >> a >> b;
            a--; b--;
            dist[a][b] = dist[b][a] = 1;
        }
        if(n == 1) cout << v[0] << " " << 1 << endl;
        else solve();
    }
    return 0;
}
