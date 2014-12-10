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
const int maxn = 105;
int mp[maxn][maxn];
int n,m;

bool ok(int x,int y) {
    bool b1 = true,b2 =  true;
    for(int i = 1;i <= n;i++) if(mp[i][y] > mp[x][y]) b1 = false;
    for(int i = 1;i <= m;i++) if(mp[x][i] > mp[x][y]) b2 = false;
    return b1 || b2;
}


int main() {
    int T; scanf("%d",&T);
    int kase = 1;
    while(T--) {
        int minval = INF;
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                scanf("%d",&mp[i][j]);
            }
        }
        bool ret = true;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                ret &= ok(i,j);
            }
        }
        printf("Case #%d: %s\n",kase++,ret ? "YES" : "NO");
    }
}
