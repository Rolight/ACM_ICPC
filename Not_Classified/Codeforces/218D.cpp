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
#include <ctime>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 1000000 + 5;
int tmp[maxn],n,v,nans;
int ans[maxn];

void dfs(int now,int cnt,int a,int b,int val,int prev) {
    if(now == n + 1) {
        if(cnt < nans && val == v) {
            nans = cnt;
            for(int i = 1;i <= n;i++) ans[i] = tmp[i];
        }
        return;
    }
    if(cnt > nans || val > v) return;
    tmp[now] = 0;
    dfs(now + 1,cnt + (prev == 0),a + b,b,a + b,0);
    if(now != 1) {
        tmp[now] = 1;
        dfs(now + 1,cnt + (prev == 1),a,a + b,a + b,1);
    }
}

int main() {
    nans = INF;
    cin >> n >> v;
    dfs(1,0,0,1,0,-1);
    if(nans > n ) puts("IMPOSSIBLE");
    else {
        printf("%d\n",nans);
        for(int i = 1;i <= n;i++) {
            putchar(ans[i] == 0 ? 'T' : 'B');
        }
        putchar('\n');
    }
    return 0;
}
