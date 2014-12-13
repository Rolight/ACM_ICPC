#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;
LL a[4];

bool dfs(LL cnt[4]) {
    LL nowsum = cnt[0] + cnt[1] + cnt[2] + cnt[3];
    if(nowsum == 0) return true;
    else if(nowsum < 3) return false;
    bool ret = false;
    //case 1,2,3
    LL mcnt = min(cnt[0], min(cnt[1], cnt[2]));
    LL rcnt[4];
    for(int i = 0; i < 4; i++) rcnt[i] = cnt[i];
    for(int i = 0; i <= 2; i++) rcnt[i] -= mcnt;
    if(mcnt > 0) ret |= dfs(rcnt);
    for(int i = 0; i < 4; i++) rcnt[i] = cnt[i];
    //case 2,3,4
    mcnt = min(cnt[1], min(cnt[2], cnt[3]));
    for(int i = 1; i <= 3; i++) rcnt[i] -= mcnt;
    if(mcnt > 0)  ret |= dfs(rcnt);
    //case 111
    for(int i = 0; i <= 3; i++) if(cnt[i] >= 3) {
        for(int j = 0; j < 4; j++) rcnt[j] = cnt[j];
        rcnt[i] = 0;
        ret |= dfs(rcnt);
    }
    return ret;
}

int main() {
    int T; cin >> T;
    while(T--) {
          cin >> a[0] >> a[1] >> a[2] >> a[3];
        if(dfs(a)) puts("Yes");
        else puts("No");
    }
    return 0;
}
