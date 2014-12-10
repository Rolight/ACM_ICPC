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
const int dx[] = {0,0,0,0,1,-1};
const int dy[] = {0,0,1,-1,0,0};
const int dz[] = {1,-1,0,0,0,0};
const int maxn = 55;
bool mp[maxn][maxn][maxn];
int n,m,o,maxtime;
int dist[maxn][maxn][maxn];

void bfs() {
    queue<int> qx,qy,qz;
    qx.push(1); qy.push(1); qz.push(1);
    dist[1][1][1] = 0;
    while(!qx.empty()) {
        int x = qx.front(), y = qy.front(), z = qz.front();
        qx.pop(); qy.pop(); qz.pop();
        for(int i = 0;i < 6;i++) {
            int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
            int nt = dist[x][y][z] + 1;
            if(dist[nx][ny][nz] > nt && !mp[nx][ny][nz] && nt <= maxtime) {
                qx.push(nx); qy.push(ny); qz.push(nz);
                dist[nx][ny][nz] = nt;
            }
        }
    }
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        int tmp;
        memset(mp,1,sizeof(mp));
        memset(dist,0x3f,sizeof(dist));
        scanf("%d%d%d%d",&n,&m,&o,&maxtime);
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                for(int k = 1;k <= o;k++) {
                    scanf("%d",&tmp);
                    mp[i][j][k] = tmp;
                }
            }
        }
        bfs();
        if(dist[n][m][o] > maxtime) puts("-1");
        else printf("%d\n",dist[n][m][o]);
    }
    return 0;
}
