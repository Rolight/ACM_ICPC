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
const int WALL = 0;
const int EMPTY = 1;
const int STR = 2;
const int TAR = 3;
const int RESET = 4;
const int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
int mp[maxn][maxn], st[maxn][maxn][7];
int n,m,sx,sy,ex,ey;

void bfs() {
    queue<int> qx,qy,qt;
    qx.push(sx); qy.push(sy); qt.push(6);
    st[sx][sy][6] = 0;
    while(!qx.empty()) {
        int x = qx.front(), y = qy.front(), t = qt.front();
        int nowt = st[x][y][t];
        qx.pop(); qy.pop(); qt.pop();
        for(int i = 0;i < 4;i++) {
            int nx = x + dx[i], ny = y + dy[i];
            int nt = mp[nx][ny] == RESET ? 6 : t - 1;
            if(t - 1 > 0 && mp[nx][ny] != WALL) {
                if(nowt + 1 < st[nx][ny][nt]) {
                    st[nx][ny][nt] = nowt + 1;
                    qx.push(nx); qy.push(ny); qt.push(nt);
                }
            }
        }
    }
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        memset(mp,0,sizeof(mp));
        memset(st,0x3f,sizeof(st));
        int inf = st[0][0][0],ans = inf;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                scanf("%d",&mp[i][j]);
                if(mp[i][j] == STR) {
                    sx = i; sy = j;
                }
                if(mp[i][j] == TAR) {
                    ex = i; ey = j;
                }
            }
        }
        bfs();
        for(int i = 1;i < 6;i++) ans = min(ans,st[ex][ey][i]);
        if(ans >= inf) puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}
