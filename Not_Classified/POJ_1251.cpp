#include <cstdio>
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
const int maxn = 1005;
int u[maxn],v[maxn],w[maxn],cnt,n,r[maxn],fa[30];

int findp(int x) { return x == fa[x] ? x : fa[x] = findp(fa[x]); }
bool cmp(int i,int j) { return w[i] < w[j]; }

int main() {
    while(scanf("%d",&n),n) {
        int ans = 0;
        cnt = 0;
        for(int i = 0;i < n;i++) fa[i] = i;
        for(int i = 1;i < n;i++) {
            char ch; int k,id;
            scanf(" %c%d",&ch,&k);
            id = ch - 'A';
            for(int j = 1;j <= k;j++) {
                scanf(" %c%d",&ch,&w[cnt]);
                u[cnt] = id; v[cnt] = ch - 'A';
                r[cnt] = cnt;
                cnt++;
            }
        }
        sort(r,r + cnt,cmp);
        for(int i = 0;i < cnt;i++) {
            int pa = findp(u[r[i]]),pb = findp(v[r[i]]);
            if(pa == pb) continue;
            fa[pa] = pb;
            ans += w[r[i]];
        }
        printf("%d\n",ans);

    }
    return 0;
}
