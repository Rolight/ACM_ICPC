#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

int n;
LL f[1 << 20][20][2];

LL dfs(int state,int prev,bool shang) {
    if(state == (1 << n) - 1) return 1;
    LL ret = 0;
    LL &note = f[state][prev - 1][shang];
    if(note != -1) return note;
    for(int i = 1;i <= n;i++) if(!(state & (1 << (i - 1)))) {
        if(shang && i < prev) continue;
        if(!shang && i > prev) continue;
        ret += dfs(state | (1 << (i - 1)),i,!shang);
    }
    return note = ret;
}

LL gao(int t) {
    n = t;
    memset(f,-1,sizeof(f));
    LL ret = 0;
    ret += dfs(0,-1,1);
    //memset(f,-1,sizeof(f));
    ret += dfs(0,100,0);
    if(n == 1) return 1;
    return ret << 1;
}

int main() {
    freopen("out.txt","w",stdout);
    for(int i = 1;i <= 20;i++) {
        cout << gao(i) << "LL ,";
    }
    return 0;
}
