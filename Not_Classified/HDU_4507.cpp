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
int lim[maxn],len = 0;
LL p10[maxn] = {1};

struct EE {
    LL sqsum,sum,cnt;
    bool vis;
    EE(LL sqsum = 0,LL sum = 0,LL cnt = 0):sqsum(sqsum),sum(sum),cnt(cnt),vis(0) {}
};

EE f[maxn][10][10];

void getlim(LL num) {
    len = 0;
    memset(lim,0,sizeof(lim));
    while(num) {
        lim[len++] = num % 10;
        num /= 10;
    }
}

EE dfs(int now,int bitsum,int rest,int bound,LL num) {
    if(now == 0) {
        if(bitsum % 7 == 0 || rest % 7 == 0) return EE(0,0,0);
        return EE(0,0,1);
    }
    EE &note = f[now][bitsum][rest];
    if(note.vis && !bound) return note;
    int m = bound ? lim[now - 1] : 9;
    EE ret(0,0,0);
    for(int i = 0;i <= m;i++) {
        if(i == 7) continue;
        int nbitsum = (bitsum + i) % 7;
        int nrest = (rest * 10 + i) % 7;
        int nbound = (i == m && bound);
        EE nret = dfs(now - 1,nbitsum,nrest,nbound,num * 10 + i);
        LL ff = p10[now - 1] * i % MOD;
        ret.cnt = (nret.cnt + ret.cnt) % MOD;
        ret.sum = ((nret.cnt * ff % MOD + nret.sum) % MOD + ret.sum) % MOD;
        ret.sqsum = ((nret.cnt * ff % MOD * ff % MOD + nret.sqsum) % MOD + 2 * ff % MOD * nret.sum % MOD + ret.sqsum) % MOD ;
    }
    if(!bound) note = ret,note.vis = true;
    return ret;
}


LL work(LL num) {
    for(int i = 0;i < maxn;i++) {
        for(int j = 0;j < 10;j++) {
            for(int k = 0;k < 10;k++) {
                f[i][j][k] = EE();
            }
        }
    }
    getlim(num);
    EE ret = dfs(len,0,0,1,0);
    return ret.sqsum;
}


int main() {
    for(int i = 1;i < maxn;i++) p10[i] = p10[i - 1] * 10;
    int T; cin >> T;
    LL n,m;
    while(T--) {
        cin >> n >> m;
        cout << (work(m) - work(n - 1) + MOD) % MOD << endl;
    }
    return 0;
}
