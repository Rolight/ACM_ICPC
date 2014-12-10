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
const int maxn = 1 << 16;
int ans[maxn],n,k,now,lim;
int s[maxn],snow[maxn],top,spos[maxn];
bool hs[maxn];

void dfs1() {
    memset(snow,0,sizeof(snow));
    top = n - 1;
    ans[top] = 0; snow[0] = 0; top++;
    while(top < lim) {
        int w = ans[top - 1];
        if(snow[w] == 2) {
            top--;
            snow[w] = 0;
            hs[w] = false;
            continue;
        }
        for(;snow[w] < 2;snow[w]++) {
            int vv = w & ((1 << (n - 1)) - 1);
            vv = (vv << 1) +  snow[w];
            if(!hs[vv]) {
               ans[top] = vv;
               snow[w]++;
               top++;
               hs[vv] = true;
               break;
            }
        }
    }
}

bool dfs(int now) {
    bool ret = false;
    if(now == lim) return true;
    for(int i = 0;i <= 1;i++) {
        int vv = ans[now - 1] & ((1 << (n - 1)) - 1);
        vv = (vv << 1) + i;
        if(!hs[vv]) {
            hs[vv] = true;
            ans[now] = vv;
            ret |= dfs(now + 1);
        }
        if(ret) break;
    }
    return ret;
}

void solve() {
    for(int i = 0;i < n;i++) ans[i] = 0;
    hs[0] = true;
    /*
    dfs(n);
    */
    dfs1();
    int ret = 0;
    for(int i = 0;i < n;i++) {
        ret = ret << 1;
        ret += ans[(k + i) % (1 << n)] % 2;
    }
    printf("%d\n",ret);
}

int main() {
    while(scanf("%d%d",&n,&k),n) {
        memset(hs,0,sizeof(hs));
        now = 0;
        lim = (1 << n) + n - 1;
        solve();
    }
    return 0;
}
