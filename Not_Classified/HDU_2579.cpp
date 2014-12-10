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
const int maxn = 105;
const int maxk = 10;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int d[maxn][maxn][maxk];
int n,m,k,sx,sy,ex,ey;
char mp[maxn][maxn];

void bfs() {
    queue<int> qx,qy,qk;
    qx.push(sx); qy.push(sy); qk.push(0);
    d[sx][sy][0] = 0;
    int x,y,nowk,nx,ny,nk;
    while(!qx.empty()) {
        x = qx.front(); y = qy.front(); nowk = qk.front();
        qx.pop(); qy.pop(); qk.pop();
        int nowt = d[x][y][nowk];
        for(int i = 0;i < 4;i++) {
            nx = x + dx[i]; ny = y + dy[i]; nk = (nowk + 1) % k;
            int &nt = d[nx][ny][nk];
            if((nk == 0 || mp[nx][ny] != '#') && nt > nowt + 1) {
                if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
                nt = nowt + 1;
                qx.push(nx); qy.push(ny); qk.push(nk);
            }
        }
    }
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        memset(mp,'#',sizeof(mp));
        memset(d,0x3f,sizeof(d));
        int inf = d[0][0][0];
        scanf("%d%d%d",&n,&m,&k);
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                scanf(" %c",&mp[i][j]);
                if(mp[i][j] == 'Y') {
                    sx = i; sy = j;
                }
                if(mp[i][j] == 'G') {
                    ex = i; ey = j;
                }
            }
        }
        bfs();
        int ans = inf;
        for(int i = 0;i < k;i++) ans = min(ans,d[ex][ey][i]);
        if(ans < inf) printf("%d\n",ans);
        else puts("Please give me another chance!");
    }
    return 0;
}
