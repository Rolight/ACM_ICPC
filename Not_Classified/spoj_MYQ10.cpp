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
const int maxn = 50;
char buf1[maxn],buf2[maxn];
int len,lim[maxn],rec[maxn];
LL f[maxn][maxn];

inline bool check(char *buf) {
    for(int i = 0;i <= len / 2;i++) {
        if(buf[i] != buf[len - i - 1]) return false;
        if(buf[i] != '1' && buf[i] != '8' && buf[i] != '0') return false;
    } 
    return true;
}

LL dfs(int now,int str,int bound) {
    if(now == 0) return 1;
    int m = bound ? lim[now - 1] : 9;
    if(str != -1 && !bound && f[now][str] != -1) return f[now][str];
    LL ret = 0;
    for(int i = 0;i <= m;i++) if(i == 1 || i == 8 || i == 0) {
        if(i && str == -1) str = now;
        if(str == -1) ret += dfs(now - 1,-1,bound && i == m);
        else {
            if(now <= str / 2 && rec[str - now] != i) continue;
            rec[now - 1] = i;
            ret += dfs(now - 1,str,bound && i == m);
        }
    }
    if(!bound && str != -1) f[now][str] = ret;
    return ret;
}

inline void solve() {
    memset(rec,0,sizeof(rec));
    LL ret1,ret2;
    len = strlen(buf1);
    for(int i = 0,pos = len - 1;i < len;i++,pos--) lim[pos] = buf1[i] - '0';
    ret1 = dfs(len,-1,1) - check(buf1);

    len = strlen(buf2);
    for(int i = 0,pos = len - 1;i < len;i++,pos--) lim[pos] = buf2[i] - '0';
    ret2 = dfs(len,-1,1);
    cout << ret2 - ret1 << endl;
}

int main() {
    memset(f,-1,sizeof(f));
    int T; scanf("%d",&T);
    LL ret1,ret2;
    memset(f,-1,sizeof(f));
    while(T--) {
        scanf("%s%s",buf1,buf2);
        solve();
    }
    return 0;
}
