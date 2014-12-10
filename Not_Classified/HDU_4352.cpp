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
LL a,b,k;
int len = 0,lim[maxn];
LL f[maxn][1 << 10][11];

void getlim(LL n) {
    len = 0;
    memset(lim,0,sizeof(lim));
    while(n) {
        lim[len++] = n % 10; n /= 10;
    }
}

int check(int state) {
    int cnt = 0;
    while(state) {
        cnt += state & 1;
        state >>= 1;
    }
    return cnt;
}

int gao(int state,int num) {
    for(int i = num;i <= 9;i++) if(state & (1 << i)) {
        state &= ~(1 << i);
        break;
    }
    state |= (1 << num);
    return state;
}

LL dfs(int now,int state,int first,int bound) {
    if(now == 0) {
        if(check(state) == k) {
            return 1;
        }
        return 0;
    }
    LL &note = f[now][state][k];
    int m = bound ? lim[now - 1] : 9;
    if(!bound && first && note != -1) return note;
    LL ret = 0;
    for(int i = 0;i <= m;i++) {
        int ns = gao(state,i);
        if(i || first) ret += dfs(now - 1,ns,1,bound && i == m);
        else ret += dfs(now - 1,state,0,bound && i == m);
    }
    if(!bound && first) note = ret;
    return ret;
}

LL solve(LL num) {
    getlim(num);
    return dfs(len,0,0,1);
}

int main() {
    memset(f,-1,sizeof(f));
    int T,kase = 1;
    cin >> T;
    while(T--) {
        cout << "Case #" << kase++ << ":" << " ";
        cin >> a >> b >> k;
        cout << solve(b) - solve(a - 1) << endl;
    }
    return 0;
}
