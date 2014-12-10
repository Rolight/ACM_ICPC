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
const int maxn = 110;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int dk[maxn][maxn];
char mp[maxn][maxn];
int sx,sy,ex,ey,n,m,k;

void bfs() {
    queue<int> qx,qy,qk;
    qx.push(sx); qy.push(sy);
    dk[sx][sy] = 0;
    while(!qx.empty()) {
        int x = qx.front(), y = qy.front(), nk = dk[x][y];
        qx.pop(); qy.pop();
        for(int i = 0;i < 4;i++) {
            int nx = x + dx[i], ny = y + dy[i];
            while(mp[nx][ny] != '*' && dk[x][y] + 1 <= dk[nx][ny]) {
                qx.push(nx); qy.push(ny);
                dk[nx][ny] = dk[x][y] + 1;
                nx += dx[i]; ny += dy[i];
            }
        }
    }
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        memset(dk,0x3f,sizeof(dk));
        memset(mp,'*',sizeof(mp));
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                scanf(" %c",&mp[i][j]);
            }
        }
        scanf("%d%d%d%d%d",&k,&sy,&sx,&ey,&ex);
        bfs();
        if(dk[ex][ey] > k + 1) puts("no");
        else puts("yes");
    }
    return 0;
}
