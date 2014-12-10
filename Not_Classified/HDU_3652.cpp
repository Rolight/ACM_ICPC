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
int f[15][15][2][13];

void getlim(int num) {
    len = 0;
    memset(lim,0,sizeof(lim));
    while(num) {
        lim[len++] = num % 10;
        num /= 10;
    }
}

int dfs(int now,int prev,int exist,int rest,int bound) {
    int &note = f[now][prev][exist][rest];
    if(now == 0) {
        return rest % 13 == 0 && exist;
    }
    int ret = 0,m = bound ? lim[now - 1] : 9;
    if(!bound && note != -1) return note;
    for(int i = 0;i <= m;i++) {
        int ne = 0;
        if(i == 3 && prev == 1) ne = 1;
        ret += dfs(now - 1,i,ne | exist,(rest * 10 + i) % 13,bound && i == m);
    }
    if(!bound) note = ret;
    return ret;
}

int work(int num) {
    getlim(num);
    return dfs(len,0,0,0,1);
}

int main() {
    int n;
    while(scanf("%d",&n) != EOF) {
        memset(f,-1,sizeof(f));
        printf("%d\n",work(n));
    }
    return 0;
}
