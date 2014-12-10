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
int lim[maxn],len;
int num[maxn];
LL f[20][3000][20]; 

LL dfs(int now,int power,int piv,int bound) {
    if(now == 0) {
        return power == 0;
    }
    if(power < 0) return 0;
    LL &note = f[now][power][piv];
    if(!bound && note != -1) return note;
    int m = bound ? lim[now - 1] : 9;
    LL ret = 0;
    for(int i = 0;i <= m;i++) {
        num[now - 1] = i;
        ret += dfs(now - 1,power + (now - 1 - piv) * i,piv,bound && i == m);
    }
    if(!bound) note = ret;
    return ret;
}

inline LL work(LL num) {
    len = 0;
    while(num) {
        lim[len++] = num % 10;
        num /= 10;
    }
    //枚举支点
    LL ret = 0;
    memset(f,-1,sizeof(f));
    for(int i = 0;i < len;i++) {
        ret += dfs(len,0,i,1);
    }
    return ret - len + 1;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        LL n,m; cin >> n >> m;
        cout << work(m) - work(n - 1) << endl;
    }
    return 0;
}
