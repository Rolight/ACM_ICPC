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

using namespace std;
typedef long long LL;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
char buf[maxn];
int len,tmp[maxn];
LL f[maxn][5][5];

bool check() {
    for(int i = 1;i <= len;i++) {
        if(tmp[i] == 0) 
            if(tmp[i - 1] == 3 || tmp[i + 1] == 3) return false;
        if(tmp[i] == 1) {
            if((tmp[i - 1] == 3) ^ (tmp[i + 1] == 3) == 0) return false; 
        }
        if(tmp[i] == 2) {
            if(tmp[i - 1] != 3 || tmp[i + 1] != 3) return false;
        }
    }
    return true;
}

LL dfs(int now,int p1,int p2) {
    tmp[now - 1] = p1;
    if(now == len + 1) return check();
    LL ret = 0;
    if(buf[now] == '?') {
        for(int i = 0;i <= 3;i++) ret = (dfs(now + 1,i,p1) + ret) % mod;
    }
    else if(buf[now] == '*') ret += dfs(now + 1,3,p1);
    else ret += dfs(now + 1,buf[now] - '0',p1);
    ret %= mod;
    return ret;
}

int main() {
    scanf("%s",buf + 1);
    len = strlen(buf + 1);
    LL ret = dfs(1,0,0);
    cout << ret << endl;
    return 0;
}
