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
int f[15][15][15][2];

void getlim(int num) {
    memset(lim,0,sizeof(lim));
    len = 0;
    while(num) {
        lim[len++] = num % 10;
        num /= 10;
    }
}

int myabs(int x) {
    return x < 0 ? -x : x;
}

int dfs(int now,int prev,int maxd,int first,int bound) {
    int &note = f[now][prev][maxd][first];
    if(now == 0) {
        if(first && maxd >= 2) {
            return 1;
        }
        return 0;
    }
    if(!bound && note != -1) return note;
    int m = bound ? lim[now - 1] : 9,ret = 0;
    for(int i = 0;i <= m;i++) {
        num[now - 1] = i;
        if(first) {
            int nmaxd = min(maxd,myabs(i - prev));
            ret += dfs(now - 1,i,nmaxd,1,bound && i == m);
        }
        else {
            ret += dfs(now - 1,i,maxd,i || first,bound && i == m);
        }
    }
    if(!bound) note = ret;
    return ret;
}

int work(int num) {
    memset(f,-1,sizeof(f));
    if(num < 10) return num;
    getlim(num);
    return dfs(len,0,11,0,1);
}

int main() {
    int n,m;
    while(scanf("%d%d",&n,&m) == 2) {
        printf("%d\n",work(m) - work(n - 1));
    }
    return 0;
}
