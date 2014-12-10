#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;
const int maxn = 1e3 + 100;
const LL mod = 1e9 + 7;
char buf[maxn];
int lim[maxn], n, len;
LL p2[maxn];
bool vis[maxn][maxn];

struct EE {
    LL cnt, sum;
    EE(LL cnt = 0, LL sum = 0): cnt(cnt), sum(sum) {}
};

EE f[maxn][maxn];

EE dfs(int now, int bitcnt, bool bound) {
    if(now == 0) return EE(bitcnt == 0, 0);
    if(vis[now][bitcnt] && !bound) return f[now][bitcnt];
    int m = bound ? lim[now - 1] : 1;
    EE ret(0, 0);
    for(int i = 0; i <= m; i++) {
        EE nret = dfs(now - 1, bitcnt - i, bound && i == m);
        LL ff = p2[now - 1] * i % mod;
        ret.cnt = (ret.cnt + nret.cnt) % mod;
        ret.sum = ((nret.cnt * ff % mod + nret.sum) % mod + ret.sum) % mod;
    }
    if(!bound) {
        vis[now][bitcnt] = true;
        f[now][bitcnt] = ret;
    }
    return ret;
}

void gao() {
    len = strlen(buf);
    bool flag = false;
    for(int i = 0, j = len - 1; i < len; i++, j--) {
        lim[j] = buf[i] - '0';
    }
    int pos;
    for(pos = 0; lim[pos] == 0; pos++) lim[pos] = 1;
    lim[pos] = 0;
    if(pos == len - 1) len--;
    EE ret = dfs(len, n, true);
    cout << ret.sum  << endl;
}

void init() {
    p2[0] = 1;
    for(int i = 1; i <= 1000; i++) {
        p2[i] = (p2[i - 1] * 2) % mod;
    }
}

int main() {
    init();
    while(scanf("%d%s", &n, buf) != EOF) {
        gao();
    }
    return 0;
}

