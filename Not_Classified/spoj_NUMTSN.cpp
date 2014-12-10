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
const int maxn = 51;
const int MOD = 1000000007;
char buf[maxn];
int lim[maxn],len;
LL f[maxn][maxn][maxn][maxn];

void getnum(bool sub) {
    memset(lim,0,sizeof(lim));
    len = strlen(buf);
    for(int i = 0;i < len;i++) {
        lim[len - i - 1] = buf[i] - '0';
    }
    if(!sub) return;
    lim[0] -= 1;
    int pos = 0;
    while(lim[pos] < 0) {
        lim[pos] = 9;
        lim[pos + 1]--; pos++;
    }
}

LL dfs(int now,int three,int six,int nine,int bound) {
    if(now == 0) {
        if(three >= 1 && three == six && nine == six) {
            return 1;
        }
        else {
            return 0;
        }
    }
    LL note = f[now][three][six][nine];
    int m = bound ? lim[now - 1] : 9;
    LL ret = 0;
    for(int i = 0;i <= m;i++) {
        int nthree = three,nsix = six,nnine = nine;
        if(i == 3) nthree++;
        if(i == 6) nsix++;
        if(i == 9) nnine++;
        ret += dfs(now - 1,nthree,nsix,nnine,bound && i == m);
        ret %= MOD;
    }
    if(!bound) note = ret;
    return ret;
}

LL work() {
    memset(f,-1,sizeof(f));
    return dfs(len,0,0,0,1);
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        scanf("%s",buf);
        getnum(true);
        LL ret1 = work();
        scanf("%s",buf);
        getnum(false);
        LL ret2 = work();
        cout << (ret2 - ret1 + MOD) % MOD << endl;
    }
    return 0;
}
