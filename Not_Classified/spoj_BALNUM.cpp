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

typedef unsigned long long ULL;
typedef long long LL;
const ULL INF = ~0ULL;
const int maxn = 20;
const int maxstate = 59049;
int lim[maxn],len = 0;
int ccon[maxstate][10];
bool ok[maxstate];

void getlim(ULL num) {
    memset(lim,0,sizeof(lim));
    len = 0;
    while(num) {
        lim[len++] = num % 10;
        num /= 10;
    }
}

ULL f[maxn][maxstate];

int tmp[10];
inline int con(int ns,int pos) {
    for(int i = 9;i >= 0;i--) {
        tmp[i] = ns % 3; ns /= 3;
    }
    if(tmp[pos] == 0) tmp[pos] = 1;
    else if(tmp[pos] == 1) tmp[pos] = 2;
    else tmp[pos] = 1;
    int ret = 0;
    for(int i = 0;i <= 9;i++) {
        ret *= 3; ret += tmp[i]; }
    return ret;
}

inline bool check(int st) {
    for(int i = 9;i >= 0;i--)  {
        tmp[i] = st % 3; st /= 3;
    }
    for(int i = 0;i <= 9;i++) if(tmp[i]) {
        if((i % 2) == (tmp[i] % 2)) return false;
    }
    return true;
}

ULL dfs(int now,int state,int first,int bound) {
    if(now == 0) {
        return ok[state];
    }
    ULL &note = f[now][state];
    if(!bound && first && note != INF) return note;
    int m = bound ? lim[now - 1] : 9;
    ULL ret = 0;
    for(int i = 0;i <= m;i++) {
        if(first || i) {
            ret += dfs(now -  1,ccon[state][i],1,i == m && bound);
        } else {
            ret += dfs(now - 1,state,0,i == m && bound);
        }
    }
    if(!bound && first) note = ret;
    return ret;
}

ULL solve(ULL num) {
    getlim(num);
    return dfs(len,0,0,1);
}

void init() {
    for(int i = 0;i < maxstate;i++) {
        for(int j = 0;j < 10;j++) {
            ccon[i][j] = con(i,j);
        }
        ok[i] = check(i);
    }
}

int main() {
    int T; cin >> T;
    ULL a,b;
    init();
    memset(f,0xff,sizeof(f));
    while(T--) {
        cin >> a >> b;
        cout << solve(b) - solve(a - 1) << endl;
    }
    return 0;
}
