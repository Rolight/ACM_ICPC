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
const int maxn = 505;
const int maxs = (4096 + 5);
int num[maxn],n;
int f[maxn][maxs];

inline int lowbit(int x) {
    return x & -x;
}

void solve() {
    memset(f,-1,sizeof(f));
    f[0][0] = 0;
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < 4096;j++) if(f[i - 1][j] != -1) {
            int nownum = num[i], nowst = j, nowval = nownum;
            f[i][j] = max(f[i][j], f[i - 1][j]);
            while(lowbit(nowst) == (nownum >> 1)) {
                nowval += (nownum << 1);
                nowst ^= (nownum >> 1);
                nownum <<= 1;
            }
            if(lowbit(nowst) < (nownum >> 1)) nowst = 0;
            nowst |= (nownum >> 1);
            f[i][nowst] = max(f[i][nowst],f[i - 1][j] + nowval);
        }
    }
    for(int i = 0;i < 4096;i++) ans = max(ans,f[n][i]);
    printf("%d\n",ans);
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
       scanf("%d",&n);
       for(int i = 1;i <= n;i++) {
           scanf("%d",&num[i]);
       }
       solve();
    }
    return 0;
}
