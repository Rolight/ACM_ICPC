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

int lim[256],len = 0;
LL f[40][40][40];

void getlim(LL N) {
    memset(lim,0,sizeof(lim));
    memset(f,-1,sizeof(f));
    len = 0;
    LL tmp = N;
    while(tmp) {
        lim[len++] = tmp & 1;
        tmp >>= 1;
    }
}

LL dfs(int now,int cz,int co,int bound,int first) {
    LL &note = f[now][cz][co];
    if(now == 0) {
        if(first) return cz >= co;
        else return 0;
    }
    if(!bound && note != -1 && first) {
        return note;
    }
    int m = bound ? lim[now - 1] : 1;
    LL ret = 0;
    for(int i = 0;i <= m;i++) {
        if(first) {
            ret += dfs(now - 1,cz + !i,co + i,bound && i == lim[now - 1],first);
        } else {
            if(i == 0) ret += dfs(now - 1,cz,co,0,0);
            else ret += dfs(now - 1,0,1,bound && i == lim[now - 1],1);
        }
    }
    if(!bound && first) note = ret;
    return ret;
}

int main() {
    LL N,M;
    while(cin >> N >> M) {
        LL ret1,ret2;
        getlim(M); ret1 = dfs(len,0,0,1,0);
        getlim(N - 1); ret2 = dfs(len,0,0,1,0);
        cout << ret1 - ret2 << endl;
    }
    return 0;
}
