#include <cstdio>
#include <cmath>
#include <cstring>
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
const int maxn = 300;
const int maxk = maxn * maxn;
const double eps = 1e-5;
int u[maxk],v[maxk],r[maxk],cnt;
double w[maxk],posx[maxn],posy[maxn],posz[maxn],sz[maxn];
int fa[maxn];

double sq(double x) {return x * x;}
double dist(int i,int j) {
    return sqrt(sq(posx[i]-posx[j]) + sq(posy[i]-posy[j]) + sq(posz[i]-posz[j]));
}
int findp(int x) {
    return x == fa[x] ? x : fa[x] = findp(fa[x]);
}
bool cmp(int a,int b) {
    return w[a] < w[b];
}

int main() {
    int n;
    while(scanf("%d",&n),n) {
        cnt = 0;
        for(int i = 1;i <= n;i++) {
            fa[i] = i;
            scanf("%lf%lf%lf%lf",&posx[i],&posy[i],&posz[i],&sz[i]);
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                u[cnt] = i; v[cnt] = j;
                w[cnt] = dist(i,j) - sz[i] - sz[j];
                if(w[cnt] < eps) w[cnt] = 0;
                r[cnt] = cnt;
                cnt++;
            }
        }
        sort(r,r + cnt,cmp);
        double ans = 0;
        for(int i = 0;i < cnt;i++) {
            int pa = findp(u[r[i]]),pb = findp(v[r[i]]);
            if(pa == pb) continue;
            fa[pa] = pb;
            ans += w[r[i]];
        }
        printf("%.3f\n",ans);
    }
    return 0;
}
