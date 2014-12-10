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
const int maxn = 15;
int lim[maxn],len;
char buf[maxn],str[maxn];
LL f[90][90];

void getlim(char *str) {
    memset(lim,0,sizeof(lim));
    len = strlen(str);
    for(int i = 0;i < len;i++) lim[i] = buf[i] - 'a' + 1;
}

LL dfs(int now,int prev,int bound) {
    LL &note = f[now][prev == -1 ? 0 : prev];
    if(now == len - 1) {
        if(prev > 0) return 1;
        return 0;
    } 
    if(!bound && note != -1) return note;
    int m = bound ? lim[now + 1] : 26;
    LL ret = 0;
    for(int i = prev == -1 ? 0 : prev + 1;i <= m;i++) {
        ret += dfs(now + 1,i == 0 ? -1 : i,bound && i == lim[now + 1]);
    }
    if(!bound) note = ret;
    return ret;
}

int main() {
    while(scanf("%s",buf) != EOF) {
        bool bad = false;
        len = strlen(buf);
        for(int i = 1;i < len;i++) if(buf[i] <= buf[i - 1]) bad = true;
        if(bad) {
            puts("0"); continue;
        }
        memset(f,-1,sizeof(f));
        getlim(buf);
        cout << dfs(-1,-1,1) << endl;
    }
    return 0;
}
