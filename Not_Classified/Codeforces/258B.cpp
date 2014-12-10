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
const LL MOD = 1e9 + 7;
int M,lim[maxn],len;
bool vis[maxn][maxn];
struct EE {
    LL cnt[maxn];
    EE() {
        memset(cnt,0,sizeof(cnt));
    }
};
EE f[maxn][maxn], ans;

void getlim(int num) {
    len = 0;
    memset(lim,0,sizeof(lim));
    while(num) {
        lim[len++] = num % 10;
        num /= 10;
    }
}

EE dfs(int now,int cnt,int bound) {
    if(now == 0) {
        EE ret;
        ret.cnt[cnt] = 1;
        return ret;
    }
    if(!bound && vis[now][cnt]) return f[now][cnt];
    int m = bound ? lim[now - 1] : 9;
    EE ret;
    for(int i = 0;i <= m;i++) {
        EE nret = dfs(now - 1,cnt + (i == 4 || i == 7),bound && i == m);
        for(int i = 0;i <= len;i++) ret.cnt[i] += nret.cnt[i];
    }
    if(!bound) {
        f[now][cnt] = ret;
        vis[now][cnt] = true;
    }
    return ret;
}

LL A(LL m,LL n) {
    LL ret = 1;
    for(int i = 1;i <= n;i++) {
        ret *= m; m--; ret %= MOD;
    }
    return ret;
}

LL rest[maxn],rcnt[maxn];
LL dfs1(int now,int sum,int limm) {
    if(sum >= limm) return 0;
    if(now == 7) {
        LL ret = 1;
        for(int i = 0;i < limm;i++) if(rcnt[i]) {
            ret = (ret * A(ans.cnt[i],rcnt[i])) % MOD;
        }
        return ret;
    }
    LL ret = 0;
    for(int i = 0;i < limm;i++) if(rest[i]) {
        rcnt[i]++; rest[i]--;
        ret = (ret + dfs1(now + 1,sum + i,limm)) % MOD;
        rcnt[i]--; rest[i]++;
    }
    return ret;
}

void solve() {
    memset(vis,0,sizeof(vis));
    getlim(M);
    ans = dfs(len,0,1);
    ans.cnt[0]--;
    LL out = 0;
    for(int i = 1;i <= len;i++) if(ans.cnt[i]) {
        memcpy(rest,ans.cnt,sizeof(rest));
        memset(rcnt,0,sizeof(rcnt));
        out = (dfs1(1,0,i) * ans.cnt[i] % MOD + out) % MOD;
    }
    cout << out << endl;
}


int main() {
    cin >> M;
    solve();
    return 0;
}
