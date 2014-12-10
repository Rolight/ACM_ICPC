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
const int maxn = 3000;
const int maxm = 20000;
int v[maxm],first[maxn],nxt[maxm],cap[maxm],b[maxm],flow[maxm];
int rb[maxn],cb[maxn];
int r,c,s,t,sa,ta,ecnt;
char buf[128];

void adde(int uu,int vv,int bb,int cc) {
    v[ecnt] = vv; b[ecnt] = bb; cap[ecnt] = cc; 
    nxt[ecnt] = first[uu]; flow[ecnt] = 0;  first[uu] = ecnt++;
    v[ecnt] = uu; b[ecnt] = 
}

void input() {
    scanf("%d%d",&r,&c);
    sa = 0; ta = r + c + 1;
    s = ta + 1; t = s + 1;
    for(int i = 1;i <= r;i++) {
        scanf("%d",&rb[i]);
        adde(sa,i,rb[i],0);
    }
    
    for(int i = 1;i <= c;i++) {
        scanf("%d",&cb[i]);
        adde(i + r,cb[i],0);
    }

    int mm; scanf("%d",&mm);
    for(int i = 0;i < mm;i++) {
        int nr,nc,nv;
        scanf("%d%d%s%d",&nr,&nc,buf,&nv);
        if(buf[0] == '=') adde(nr,nc + r,nv,nv);
        if(buf[0] == '>') adde(nr,nc + r,nv,INF);
        if(buf[0] == '<') adde(nr,nc + r,0,nv);
    }
}

int main() {
    int T; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++) {
        input();
        solve();
    }
    return 0;
}
