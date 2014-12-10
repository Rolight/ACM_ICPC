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
const int maxn = 70;
int lim[maxn],len;
int tmp[maxn];
LL f[maxn][maxn];

void getlim(LL num) {
    len = 0;
    memset(lim,0,sizeof(lim));
    while(num) {
        lim[len++] = num % 2;
        num /= 2;
    }
}

LL dfs(int now,int l,int ll,int first,int bound) {
    if(now == 0) {
        return first % l == 0 && first / l >= 2 && first == ll;
    }
    int m = bound ? lim[now - 1] : 1;
    if(first != -1 && !bound && f[now][first] != -1) return f[now][first] ;
    LL ret = 0;
    for(int i = 0;i <= m;i++) {
        if(i && first == -1) first = now;
        if(first == -1) ret += dfs(now - 1,l,ll,-1,bound && i == m);
        else {
            int pos = first - now;
            tmp[pos] = i;
            if(pos < l) ret += dfs(now - 1,l,ll,first,bound && i == m);
            else if(tmp[pos % l] == i) {
                ret += dfs(now - 1,l,ll,first,bound && i == m);
            }
        }
    }
    if(first != -1 && !bound) f[now][first] = ret;
    return ret;
}

LL solve(LL num) {
    getlim(num);
    LL ret = 0,cnt[maxn][maxn];
    memset(cnt,0,sizeof(cnt));
    for(int i = 1;i <= len / 2 + 1;i++) {
        for(int j = len;j >= 1;j--) {
            memset(f,-1,sizeof(f));
            cnt[i][j] = dfs(len,i,j,-1,1);
        }
    }
    for(int i = 2;i <= len / 2;i++) {
        for(int j = 1;j < i;j++) if(i % j == 0) {
            for(int k = i * 2;k <= len;k++) if(k % i == 0) {
                cnt[i][k] -= cnt[j][k];
            }
        }
    }
    for(int i = 1;i <= len / 2;i++) {
        for(int j = 1;j <= len;j++) {
            ret += cnt[i][j];
        }
    }
    return ret;
}

int main() {
    LL a,b; cin >> a >> b;
    cout << solve(b) - solve(a - 1) << endl;
    return 0;
}
