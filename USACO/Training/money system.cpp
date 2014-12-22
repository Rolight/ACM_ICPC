/*
ID: flsnnx1
LANG: C++
TASK: money
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
typedef long long LL;
const int maxn = 10000 + 5;
const int maxv = 26;
int N,V;
LL f[maxn][maxv];
int c[maxv];
bool vis[maxn];

LL dfs(int now,int prev) {
    LL ret = 0;
    if(now < 0) return 0;
    if(now == 0) return 1;
    if(f[now][prev] != -1) return f[now][prev];
    for(int i = prev;i <= V;i++) {
        ret += dfs(now - c[i],i);
    }
    return f[now][prev] = ret;
}

int main() {
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    memset(f,-1,sizeof(f));
    cin >> V >> N;
    for(int i = 1;i <= V;i++) cin >> c[i];
    sort(c + 1,c + 1 + V);
    LL ret = dfs(N,1);
    cout << ret << endl;
    return 0;
}

