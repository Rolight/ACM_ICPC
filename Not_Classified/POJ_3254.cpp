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
#include <stack>
#include <sstream>
#include <numeric>
#include <fstream>
#include <functional>

using namespace std;

#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int mod = 1e8;
const int maxn = 12;
int n,m,field[maxn],tmp[maxn];
int f[maxn][1 << 13];

bool ok(int row,int state) {
    if(~field[row] & state) return false;
    int prev = 0,now;
    while(state) {
        now = state & 1;
        if(now == prev && now == 1) return false;
        prev = now;
        state >>= 1;
    }
    return true;
}

int dfs(int now,int prev) {
    if(now == n) return 1;
    if(~f[now][prev]) return f[now][prev];
    int ret = 0;
    for(int i = 0;i < (1 << 12);i++) if(ok(now,i)) {
        if((i | prev) == prev) {
            ret = (dfs(now + 1,~i & field[now + 1]) + ret) % mod;
        }
    }
    return f[now][prev] = ret;
}

int main() {
    while(scanf("%d%d",&n,&m) != EOF) {
        memset(field,0,sizeof(field));
        memset(f,-1,sizeof(f));
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                scanf("%d",&tmp[j]);
            }
            for(int j = m - 1;j >= 0;j--) {
                field[i] = (field[i] << 1) | tmp[j];
            }
        }
        int ans = dfs(0,(1 << 12) - 1);
        printf("%d\n",ans);
    }
    return 0;
}
