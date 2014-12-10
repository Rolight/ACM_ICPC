#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <iostream>
#include <map>
#include <cstdlib>
#include <set>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
const int maxn = 1e8 + 100;
int n,ans[maxn],lim,p10[10],vnow[maxn];
int s[maxn],top,spos[maxn];
bool hs[maxn];

void dfs1() {
    memset(vnow,0,sizeof(vnow));
    top = 0;
    for(int i = 0;i < lim;i++) ans[i] = 0;
    hs[0] = true;
    vnow[0] = 1;
    s[top] = 0;
    spos[top] = n;
    top++;
    while(top > 0) {
        int w = s[top - 1],pos = spos[top - 1];
        if(pos == lim) break;
        if(vnow[w] == 10) {
            hs[w] = false;
            vnow[w] = 0;
            top--;
        }
        for(;vnow[w] < 10;vnow[w]++) {
            int vv = w * 10 % p10[n] + vnow[w];
            if(!hs[vv]) {
                hs[vv] = true;
                s[top] = vv; spos[top] = pos + 1; top++;
                vnow[w]++;
                ans[pos] = vv;
                break;
            }
        }
    }
}

bool dfs(int now) {
    bool ret = false;
    if(now == lim) return true;
    for(int i = 0;i < 10;i++) {
        int val = 0;
        if(now >= n - 1) val = ans[now - 1] * 10 % p10[n] + i;
        if(now >= n) {
            if(!hs[val]) {
                hs[val] = true;
                ans[now] = val;
                ret |= dfs(now + 1);
                hs[val] = false;
            }
        }
        else if(now == n - 1) {
            hs[val] = true;
            ans[now] = val;
            ret |= dfs(now + 1);
            hs[val] = false;
        }
        else { 
            ans[now] = i;
            ret |= dfs(now + 1);
        }
        if(ret) break;
    }
    return ret;
}

void solve() {
    memset(hs,0,sizeof(hs));
    lim = p10[n] + n - 1;
    dfs1();
    for(int i = 0;i < lim;i++) printf("%d",ans[i] % 10);
    puts("");
    /*
    memset(hs,0,sizeof(hs));
    dfs(0);
    for(int i = 0;i < lim;i++) printf("%d",ans[i] % 10);
    puts("");
    */
}

int main() {
    p10[0] = 1;
    for(int i = 1;i < 10;i++) p10[i] = p10[i - 1] * 10;
    while(scanf("%d",&n),n) solve();
    return 0;
}
