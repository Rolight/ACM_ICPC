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
const int maxn = 15;
int dist[maxn][maxn],n,f[1 << 11];

int dfs(int state) {
    int ret = 0;
    if(~f[state]) return f[state];
    for(int i = 0;i < n;i++) if(state & (1 << i)) {
        for(int j = 0;j < n;j++) if(state & (1 << j)) {
            if(i == j) continue;
            ret = max(ret,dfs(state & (~(1 << j))) + dist[i][j]);
        }
    }
    return f[state] = ret;
}

int main() {
    while(scanf("%d",&n),n) {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                scanf("%d",&dist[i][j]);
            }
        }
        memset(f,-1,sizeof(f));
        int ans = dfs((1 << n) - 1);
        printf("%d\n",ans);
    }
    return 0;
}
