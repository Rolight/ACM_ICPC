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
const int maxn = 10;
const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;
const int UP_AND_DOWN = (1 << UP) | (1 << DOWN);
const int LEFT_AND_RIGHT = (1 << LEFT) | (1 << RIGHT);
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

struct Node {
    int x,y,pre;
    Node(int x,int y,int pre = -1): x(x), y(y), pre(pre) {}
};

int n,m,mp[maxn][maxn],sx,sy,ex,ey,tmp[maxn][maxn];
int dist[maxn][maxn][4],px,py;
bool vis[maxn][maxn];


bool bfs1(int x1,int y1,int x2,int y2) {
    if(tmp[x1][y1] != 0 || tmp[x2][y2] != 0) return false;
    queue<int> qx,qy;
    qx.push(x1); qy.push(y1);
    memset(vis,0,sizeof(vis));
    vis[x1][y1] = true;
    while(!qx.empty()) {
        int x = qx.front(), y = qy.front();
        qx.pop(); qy.pop();
        if(x == x2 && y == y2) return true;
        for(int i = 0;i < 4;i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(!vis[nx][ny] && tmp[nx][ny] == 0) {
                qx.push(nx); qy.push(ny); 
                vis[nx][ny] = true;
            }
        }
    }
    return false;
}

int bfs() {
    queue<Node> box,man;
    box.push(Node(sx,sy,0));
    man.push(Node(px,py));
    for(int i = 0;i < 4;i++) dist[sx][sy][i] = -1;
    int x,y,nx,ny,xp,yp,nxp,nyp,pre;
    while(!box.empty()) {
        Node nowbox = box.front(), nowman = man.front();
        box.pop(); man.pop();
        x = nowbox.x; y = nowbox.y; pre = nowbox.pre;
        xp = nowman.x; yp = nowman.y;
        //printf("box: %d %d  man: %d %d time: %d\n",x,y,xp,yp,dist[x][y][pre]);
        if(x == ex && y == ey) return dist[x][y][pre] + 1;
        for(int i = 0;i < 4;i++) {
            nx = x + dx[i]; ny = y + dy[i];
            nxp = x - dx[i]; nyp = y - dy[i];
            tmp[x][y] = 1;
            if((dist[nx][ny][i] == -1 || dist[nx][ny][i] >= dist[x][y][pre] + 1) 
                    && tmp[nx][ny] == 0
                    && bfs1(xp,yp,nxp,nyp)) {
                dist[nx][ny][i] = dist[x][y][pre] + 1;
                box.push(Node(nx,ny,i)); man.push(Node(x,y));
            }
            tmp[x][y] = 0;
        }
    }
    return -1;
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        memset(dist,-1,sizeof(dist));
        memset(tmp,0x3f,sizeof(tmp));
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                scanf("%d",&tmp[i][j]);
                if(tmp[i][j] == 2) {
                    sx = i; sy = j;
                }
                if(tmp[i][j] == 3) {
                    ex = i; ey = j;
                }
                if(tmp[i][j] == 4) {
                    px = i; py = j;
                }
                if(tmp[i][j] != 1) tmp[i][j] = 0;
            }
        }
        printf("%d\n",bfs());
    }
    return 0;
}
