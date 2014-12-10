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
const int maxn = 505;
const int maxm = 5005;
struct Edge {
    int u,v,w;
    bool operator < (const Edge &x) const {
        return w > x.w;
    }
};

Edge e[maxm];
int fa[maxn];

int findp(int x) {
    return x == fa[x] ? x : fa[x] = findp(fa[x]);
}

int gcd(int a,int b) {
    return b == 0 ? a : gcd(b,a % b);
}

int main() {
    int n,m; scanf("%d%d",&n,&m);
    for(int i = 0;i < m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    int s,t; scanf("%d%d",&s,&t);
    //排序并且枚举最大边
    sort(e,e + m);
    double ans = 1e90;
    int ansa = -1,ansb = -1;
    for(int i = 0;i < m;i++) {
        int minv = -1;
        for(int i = 1;i <= n;i++) fa[i] = i;
        for(int j = 0;j < m;j++) if(e[j].w <= e[i].w) {
            int pa = findp(e[j].u),pb = findp(e[j].v);
            if(pa != pb) fa[pa] = pb;
            if(findp(s) == findp(t)) {
                minv = e[j].w; break;
            }
        }
        if(findp(s) != findp(s)) break;
        if(minv != -1 && (double)e[i].w / minv < ans) {
            ans = (double)e[i].w / minv;
            ansa = e[i].w; ansb = minv;
        }
    }
    if(ansa == -1)  puts("IMPOSSIBLE");
    else {
        int pp = gcd(ansa,ansb);
        ansa /= pp; ansb /= pp;
        if(ansb == 1) printf("%d\n",ansa);
        else printf("%d/%d\n",ansa,ansb);
    }
    return 0;
}

