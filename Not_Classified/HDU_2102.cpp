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
const int maxn = 20;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
char mp[maxn][maxn][2];
int n,m,mt,dist[maxn][maxn][2];
int px,py,pz;

void bfs() {
    queue<int> qx,qy,qz;
    qx.push(1); qy.push(1); qz.push(0);
    dist[1][1][0] = 0;
    int x,y,z,nx,ny,t;
    while(!qx.empty()) {
        x = qx.front(); y = qy.front(); z = qz.front();
        qx.pop(); qy.pop(); qz.pop();
        t = dist[x][y][z];
        if(mp[x][y][z] == '#') {
            if(mp[x][y][z ^ 1] == '.' && t < dist[x][y][z ^ 1]) {
                qx.push(x); qy.push(y); qz.push(z ^ 1);
                dist[x][y][z ^ 1] = t;
            }
            continue;
        }
        for(int i = 0;i < 4;i++) {
            nx = x + dx[i]; ny = y + dy[i];
            int &nt =  dist[nx][ny][z];
            if(mp[nx][ny][z] != '*' && t + 1 < nt) {
                nt = t + 1;
                qx.push(nx); qy.push(ny); qz.push(z);
            }
        }
    }
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&n,&m,&mt);
        memset(mp,'*',sizeof(mp));
        memset(dist,0x3f,sizeof(dist));
        for(int c = 0;c < 2;c++) {
            for(int i = 1;i <= n;i++) {
                for(int j = 1;j <= m;j++) {
                    scanf(" %c",&mp[i][j][c]);
                    if(mp[i][j][c] == 'P') {
                        px = i; py = j; pz = c;
                        mp[i][j][c] = '.';
                    }
                }
            }
        }
        bfs();
        if(dist[px][py][pz] <= mt) puts("YES");
        else puts("NO");
    }
    return 0;
}
