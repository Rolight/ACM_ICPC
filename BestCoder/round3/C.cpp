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
const int maxn = 30000 + 5;
char buf[maxn];
int len,spos,val[maxn];
int mp[1 << 26];
bool vis[27];

LL solve(int l,int r) {
    if(l > r) return 0;
    LL ret = 0;
    int nowval = 0;
    mp[0]++;
    for(int i = l;i <= r;i++) if(val[i] >= 0) {
        nowval ^= (1 << val[i]);
        ret += mp[nowval];
        mp[nowval]++;
    } else ret += mp[nowval],mp[nowval]++;
    nowval = 0;
    mp[0] = 0;
    for(int i = l;i <= r;i++) if(val[i] >= 0) {
        nowval ^= (1 << val[i]);
        mp[nowval] = 0;
    }
    return ret;
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        memset(vis,0,sizeof(vis));
        scanf("%s",buf + 1);
        len = strlen(buf + 1);
        spos = -1;
        for(int i = 1;i <= len;i++) {
            if(buf[i] == '?') spos = i;
            //转化成数字
            val[i] = buf[i] - 'a';
            if(buf[i] != '?') vis[val[i]] = true;
        }
        if(spos == -1) cout << solve(1,len) << endl;
        else {
            LL ans = solve(1,len);
            LL rest = solve(1,spos - 1) + solve(spos + 1,len);
            int cnt = 0;
            for(int i = 0;i < 26;i++) if(vis[i]) {
                val[spos] = i; ans += solve(1,len);
                cnt++;
            }
            cout << ans - cnt * rest << endl;
        }
    }
    return 0;
}
