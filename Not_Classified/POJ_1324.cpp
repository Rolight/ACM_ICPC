#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
const int maxn = 30;
const int maxl = 9;
const int maxq = 400000;
int n,m,L,K;
int mp[maxn][maxn];
int dx[4] = {0,0,-1,1},dy[4] = {-1,1,0,0};
bool vis[21][21][1 << 15];

struct Point {
    int x,y;
};

struct State {
    Point pos[maxl];
    int dis;
};

State str;
State q[400000];

int hash(State &s) {
    int ret = 0;
    for(int i = 1;i < L;i++) {
        ret <<= 2;
        int ddx = s.pos[i].x - s.pos[i - 1].x;
        int ddy = s.pos[i].y - s.pos[i - 1].y;
        if(ddx == 1) ret += 1;
        if(ddx == -1) ret += 2;
        if(ddy == 1) ret += 3;
    }
    return ret;
}

bool check(int nx,int ny,State &st) {
    if(mp[nx][ny] == 0) return false;
    for(int i = 1;i < L;i++) {
        if(nx == st.pos[i].x && ny == st.pos[i].y) {
            return false;
        }
    }
    return true;
}

int bfs() {
    int front = 0,rear = 1;
    str.dis = 0;
    memset(vis,0,sizeof(vis));
    vis[str.pos[0].x][str.pos[0].y][hash(str)] = true;
    q[0] = str;
    while(front < rear) {
        State &now = q[front % maxq]; front++;
        if(now.pos[0].x == 1 && now.pos[0].y == 1) {
            return now.dis;
        }
        for(int i = 0;i < 4;i++) {
            int nx = now.pos[0].x + dx[i],ny = now.pos[0].y + dy[i];
            if(check(nx,ny,now)) {
                State ns = now;
                for(int j = L - 1;j > 0;j--) {
                    ns.pos[j].x = ns.pos[j - 1].x;
                    ns.pos[j].y = ns.pos[j - 1].y;
                }
                ns.pos[0].x = nx;
                ns.pos[0].y = ny;
                ns.dis++;             
                if(vis[nx][ny][hash(ns)] == false) {
                    vis[nx][ny][hash(ns)] = true;
                    q[rear % maxq] = ns;
                    rear++;
                }
            }
        }
    }
    return -1;
}

int main() {   
    int kase = 1;
    while(scanf("%d%d%d",&n,&m,&L),n) {
        memset(mp,0,sizeof(mp));
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                mp[i][j] = 1;
            }
        }
        for(int i = 0;i < L;i++) {
            scanf("%d%d",&str.pos[i].x,&str.pos[i].y);
        }
        scanf("%d",&K);
        for(int i = 1;i <= K;i++) {
            int x,y; scanf("%d%d",&x,&y);
            mp[x][y] = 0;
        }
        printf("Case %d: %d\n",kase++,bfs());
    }
    return 0;
}

