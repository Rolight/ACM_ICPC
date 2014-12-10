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
const int mod = 2520;
int lim[maxn],len;
LL f[maxn][50][mod];
map<int,int> st;
int ccon[(1 << 10)],clcm[50];

void getlim(LL num) {
    len = 0;
    memset(lim,0,sizeof(lim));
    while(num) {
        lim[len++] = num % 10;
        num /= 10;
    }
}

LL gcd(LL a,LL b) {
    return b == 0 ? a : gcd(b,a % b);
}

LL lcm(LL a,LL b) {
    return a / gcd(a,b) * b;
}

void init() {
    int cnt = 0;
    for(int i = 1;i < (1 << 10);i++) {
        int nlcm = 1;
        for(int j = 1;j <= 9;j++) if(i & (1 << j)) {
            nlcm = lcm(nlcm,j);
        }
        if(!st.count(nlcm)) {
            st[nlcm] = cnt;
            clcm[cnt++] = nlcm;
        }
        ccon[i] = st[nlcm];
    }
    ccon[0] = -1;
}

LL dfs(int now,int mask,int rest,int bound) {
    if(now == 0) {
        if(mask <= 1) return 0;
        return rest % clcm[ccon[mask]] == 0;
    }
    LL &note = f[now][ccon[mask]][rest];
    if(!bound && note != -1 && mask > 1) return note;
    int m = bound ? lim[now - 1] : 9;
    LL ret = 0;
    for(int i = 0;i <= m;i++) {
        ret += dfs(now - 1,mask | (1 << i),(rest * 10 + i) % mod,i == m && bound);
    }
    if(!bound && mask > 1) note = ret;
    return ret;
}

LL solve(LL num) {
    getlim(num);
    return dfs(len,0,0,1);
}

int main() {
    memset(f,-1,sizeof(f));
    init();
    int T; cin >> T;
    while(T--) {
        LL a,b; cin >> a >> b;
        cout << solve(b) - solve(a - 1) << endl;
    }
    return 0;
}
