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
double posx[maxn],posy[maxn];
int u[maxn * maxn],v[maxn * maxn],r[maxn * maxn],fa[maxn];
bool ss[maxn];
double w[maxn * maxn];

int findp(int x) {
    return x == fa[x] ? x : fa[x] = findp(fa[x]);
}


bool cmp(int a,int b) {
    return w[a] < w[b];
}

double sq(double x) {
    return x * x;
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        vector<double> ans;
        memset(ss,0,sizeof(ss));
        int cnt = 0;
        int N,M; scanf("%d%d",&M,&N);
        for(int i = 1;i <= N;i++) scanf("%lf%lf",&posx[i],&posy[i]);
        for(int i = 1;i <= N;i++) fa[i] = i;
        for(int i = 1;i <= N;i++) {
            for(int j = i + 1;j <= N;j++) {
                u[cnt] = i; v[cnt] = j; r[cnt] = cnt;
                w[cnt] = sqrt(sq(posx[i]-posx[j]) + sq(posy[i]-posy[j]));
                cnt++;
            }
        }
        sort(r,r + cnt,cmp);
        for(int i = 0;i < cnt;i++) {
            int pa = findp(u[r[i]]),pb = findp(v[r[i]]);
            if(pa == pb) continue;
            fa[pa] = pb;
            ans.push_back(w[r[i]]);
        }
        printf("%.2f\n",ans[ans.size() - M]);
    }
    return 0;
}
