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
const int maxn = 100;
int lim[maxn],B,K,len;
int f[maxn][maxn];

void getlim(int num) {
    len = 0; memset(lim,0,sizeof(lim));
    while(num) {
        lim[len++] = num % B;
        num /= B;
    }
}

int dfs(int now,int cnt,int bound) {
    if(now == 0) {
        return cnt == K;
    }
    int ret = 0,m = bound ? lim[now - 1] : 1;
    int &note = f[now][cnt];
    if(!bound && note != -1) return note;
    for(int i = 0;i <= m;i++) {
        if(i == 0) ret += dfs(now - 1,cnt,bound && i == m);
        else if(i == 1) {
            if(cnt == K) continue;
            ret += dfs(now - 1,cnt + 1,bound && i == m);
        }
    }
    if(!bound) note = ret;
    return ret;
}

int solve(int num) {
    getlim(num);
    memset(f,-1,sizeof(f));
    return dfs(len,0,1);
}


int main() {
    int X,Y;
    cin >> X >> Y >> K >> B;
    cout << solve(Y) - solve(X - 1) << endl;
    return 0;
}
