#;include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cmath>
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
double posx[maxn],posy[maxn];
int N,u[maxn * maxn],v[maxn * maxn],r[maxn * maxn],cnt,fa[maxn];
double dis[maxn * maxn];

double getdis(int i,int j) {
    double x1 = posx[i],x2 = posx[j],y1 = posy[i],y2 = posy[j];
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool cmp(int i,int j) {
    return dis[i] < dis[j];
}

int findp(int x) {
    return x == fa[x] ? x : fa[x] = findp(fa[x]);
}

int main() {
    int kase = 1;
    while(scanf("%d",&N),N) {
        if(kase > 1) puts("");
        cnt = 0;
        for(int i = 1;i <= N;i++) scanf("%lf%lf",&posx[i],&posy[i]);
        for(int i = 1;i <= N;i++) fa[i] = i;
        for(int i = 1;i <= N;i++) {
            for(int j = 1;j <= N;j++) {
                dis[cnt] = getdis(i,j);
                u[cnt] = i;
                v[cnt] = j;
                r[cnt] = cnt;
                cnt++;
            }
        }
        sort(r,r + cnt,cmp);
        double ans = 0;
        for(int i = 0;i < cnt;i++) {
            int id = r[i],pa = findp(u[id]),pb = findp(v[id]);
            if(pa == pb) continue;
            fa[pa] = pb;
            ans += dis[id];
        }
        printf("Case #%d:\nThe minimal distance is: %.2f\n",kase++,ans);
    }
    return 0;
}
