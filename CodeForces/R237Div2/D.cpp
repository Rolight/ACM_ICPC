#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <bitset>
#include <list>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long LL;
const int maxn = 1000000 + 5;
const int mod = 1000000000 + 7;
const int mine = 3;
char buf[maxn];
int len;
LL f[maxn][5][5];
int tmp[maxn],val[maxn];

LL dfs(int now,int p1,int p2) {
    tmp[now - 1] = p1;
    if(now == len + 1) {
        if(p1 == 2 || (p1 == 1 && p2 != mine)) return 0;
        //for(int i = 1;i <= len;i++) printf("%d",tmp[i]); putchar('\n');
        return 1;
    }
    if(p1 >= 0 && p2 >= 0 && f[now][p1][p2] != -1) return f[now][p1][p2];
    LL ret = 0;
    if(val[now] == -1) {
        if(p1 == 0 || p1 == 3 || (p1 == 1 && p2 == 3)) ret = (ret + dfs(now + 1,1,p1)) % mod;
        if(p1 == 3) ret = (ret + dfs(now + 1,2,p1)) % mod;
        if(p1 == 0 || (p1 == 1 && p2 == 3)) ret = (ret + dfs(now + 1,0,p1)) % mod;
        if(now == 1 || (p1 == 1 && p2 != 3) || p1 == 2 || p1 == 3) ret = (ret + dfs(now + 1,3,p1)) % mod;
    }
    if(val[now] == 0) {
        if(p1 == 0 || (p1 == 1 && p2 == 3)) ret = dfs(now + 1,0,p1);
    }
    if(val[now] == 1) {
        if(!(p1 == 2 || (p1 == 1 && p2 != 3))) ret = dfs(now + 1,1,p1);
    }
    if(val[now] == 2) {
        if(p1 == 3) ret = dfs(now + 1,2,p1);
    }
    if(val[now] == 3) {
        if(now == 1 || p1 == 2 || (p1 == 1 && p2 != 3) || p1 == 3) ret = dfs(now + 1,3,p1);
    }
    if(p1 >= 0 && p2 >= 0) f[now][p1][p2] = ret % mod;
    return ret % mod;
}

int main() {
    memset(f,-1,sizeof(f));
    scanf("%s",buf + 1);
    len = strlen(buf + 1);
    int cnt = 0;
    for(int i = 1;i <= len;i++) {
        if(buf[i] == '*') val[i] = mine;
        else if(buf[i] == '?') val[i] = -1;
        else val[i] = buf[i] - '0';
    }
    LL ret = dfs(0,0,-1);
    cout << ret % mod << endl;
    return 0;
}
