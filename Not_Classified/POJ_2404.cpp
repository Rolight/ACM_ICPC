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
const int maxn = 20;
const int INF = INT_MAX / 4;
int dist[maxn][maxn],n,m,dcnt[maxn],sume;
int f[1 << 18];

void floyd() {
    for(int k = 1;k <= n;k++) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                dist[i][j] = min(dist[i][j],
                        dist[i][k] + dist[k][j]);
            }
        }
    }
}

bool nz(int state,int i) {
    return (state & (1 << i));
}

int dfs(int state) {
    int &note = f[state];
    int ret = INF;
    if(state == 0) return 0;
    if(~note) return note;
    for(int i = 1;i <= n;i++) if((dcnt[i] & 1) && nz(state,i)) {
        for(int j = i + 1;j <= n;j++) if((dcnt[j] & 1) && nz(state,j)) {
            int nstate = state;
            nstate &= ~(1 << i);
            nstate &= ~(1 << j);
            ret = min(ret,dfs(nstate) + dist[i][j]);
        }
    }
    return note = ret;
}

int main() {
    while(scanf("%d",&n),n) {
        memset(f,-1,sizeof(f));
        scanf("%d",&m);
        memset(dcnt,0,sizeof(dcnt));
        sume = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                dist[i][j] = INF;
            }
        }
        for(int i = 1;i <= m;i++) {
            int a,b,c; scanf("%d%d%d",&a,&b,&c);
            dist[a][b] = dist[b][a] = min(dist[a][b],c);
            dcnt[a]++; dcnt[b]++;
            sume += c;
        }
        floyd();
        int strstate = 0;
        for(int i = 1;i <= n;i++) {
            if(dcnt[i] & 1) strstate |= (1 << i);
        }
        int ret = dfs(strstate);
        printf("%d\n",ret + sume);
    }
    return 0;
}
