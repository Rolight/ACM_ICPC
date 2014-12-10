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
const int maxn = 25;
const int dx[] = {0,0,1,-1,0}, dy[] = {1,-1,0,0,0};
char mp[maxn][maxn][2], ff[2] = {'-','|'};
int dist[maxn][maxn][2],n,m,ft;
int sx,sy,ex,ey,fx,fy;

void printnow(int x,int y,int t,int a) {
    printf("nowtime is %d\n",t);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(i == x && j == y) printf("@/%c",mp[i][j][a]);
            else printf("%c  ",mp[i][j][a]);
        }
        puts("");
    }
}

void bfs() {
    int x,y,nx,ny,a,na,t,nt;
    dist[sx][sy][0] = 0;
    queue<int> qx,qy,qa;
    qx.push(sx); qy.push(sy); qa.push(0);
    while(!qx.empty()) {
        x = qx.front(), y = qy.front(), a = qa.front();
        qx.pop(); qy.pop(); qa.pop();
        t = dist[x][y][a];
        //printnow(x,y,t,a);
        for(int i = 0;i < 5;i++) {
            nx = x + dx[i]; ny = y + dy[i]; na = a ^ 1; nt = t + 1;
            if(mp[nx][ny][0] == '*') continue;
            //当前在桥上
            if(mp[x][y][0] == '|' || mp[x][y][0] == '-') {
                if(i == 4) continue;
                if(mp[x][y][a] == '-' && dx[i] != 0) continue;
                if(mp[x][y][a] == '|' && dy[i] != 0) continue;
                nt--;
            }
            //准备走到桥上
            if(mp[nx][ny][0] == '|' || mp[nx][ny][0] == '-') {
                if(mp[nx][ny][a] == '|' && dy[i] != 0) continue;
                if(mp[nx][ny][a] == '-' && dx[i] != 0) continue;
                na ^= 1;
            }
            if(nt < dist[nx][ny][na]) {
                dist[nx][ny][na] = nt;
                qx.push(nx); qy.push(ny); qa.push(na);
            }
        }
    }
}

int main() {
    while(scanf("%d%d",&n,&m) != EOF) {
        memset(mp,'*',sizeof(mp));
        memset(dist,0x3f,sizeof(dist));
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                scanf(" %c",&mp[i][j][0]);
                mp[i][j][1] = mp[i][j][0];
                if(mp[i][j][0] == '-') {
                    ft = 0; fx = i; fy = j; mp[i][j][1] = '|';
                }
                if(mp[i][j][0] == '|') {
                    ft = 1; fx = i; fy = j; mp[i][j][1] = '-';
                }
                if(mp[i][j][0] == 'S') {
                    sx = i; sy = j; mp[i][j][0] = mp[i][j][1] = '.';
                }
                if(mp[i][j][0] == 'T') {
                    ex = i; ey = j; mp[i][j][0] = mp[i][j][1] = '.';
                }
            }
        }
        bfs();
        printf("%d\n", min(dist[ex][ey][0], dist[ex][ey][1]));
    }
    return 0;
}
