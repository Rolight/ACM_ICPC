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
const int maxn = 1005;
const double eps = 1e-9;
bool mp[maxn][maxn];
int n,tt[maxn];
double L,posx[maxn],posy[maxn];

double dist(int i,int j) {
    return sqrt((posx[i]-posx[j])*(posx[i]-posx[j]) + (posy[i]-posy[j])*(posy[i]-posy[j]));
}

void bfs() {
    queue<int> q;
    q.push(1);
    tt[1] = 0;
    while(!q.empty()) {
        int now = q.front(); q.pop();
        if(now == 2) break;
        for(int i = 1;i <= n;i++) if(tt[i] == -1 && mp[now][i]) {
            tt[i] = tt[now] + 1;
            q.push(i);
        }
    }
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        memset(mp,0,sizeof(mp));
        memset(tt,-1,sizeof(tt));
        scanf("%d%lf",&n,&L);
        n += 2;
        for(int i = 1;i <= n;i++) {
            scanf("%lf%lf",&posx[i],&posy[i]);
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                if(i != j && dist(i,j) - eps <= L) {
                    mp[i][j] = true;
                }
            }
        }
        bfs();
        if(tt[2] == -1) puts("impossible");
        else printf("%d\n",tt[2] - 1);
    }
    return 0;
}
