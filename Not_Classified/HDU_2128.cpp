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
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
const int maxn = 8;
char mp[maxn][maxn];
int n,m,sx,sy,ex,ey;


struct Node {
    int x,y,dis,bomb;
    ULL maze,vis;
    Node(int x,int y,ULL maze,int dis,int bomb,ULL vis): 
        x(x),y(y),maze(maze),dis(dis),bomb(bomb),vis(vis) {}
    bool operator < (const Node &p) const {
        if(dis != p.dis) return dis > p.dis;
        int e_dis1 = abs(x - ex) + abs(y - ey);
        int e_dis2 = abs(p.x - ex) + abs(p.y - ey);
        if(e_dis1 != e_dis2) return e_dis1 > e_dis2;
        if(bomb != p.bomb) return bomb < p.bomb;
        return maze > p.maze;
    }
};

struct st_Node {
    int x,y,bomb,dis;
    ULL maze,vis;
    st_Node(Node &p) {
        x = p.x; y = p.y; bomb = p.bomb;
        maze = p.maze; vis = p.vis; dis = p.dis;
    }

    bool operator < (const st_Node &p) const {
        if(x != p.x) return x < p.x;
        if(y != p.y) return y < p.y;
        if(bomb != p.bomb) return bomb < p.bomb;
        if(maze != p.maze) return maze < p.maze;
        return vis < p.vis;
    }
};

set<st_Node> st;


inline int U(int x,int y) {
    return x * m + y;
}

inline bool in_bd(int x,int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

inline ULL maze_comp() {
    ULL ret = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(mp[i][j] == 'X') ret |= (1LL << U(i,j));
        }
    }
    return ret;
}

inline bool insert_st(Node &tmp) {
    st_Node now(tmp);
    set<st_Node>::iterator ret = st.find(now);
    if(ret == st.end()) {
        st.insert(now); return true;
    }
    return false;
}

void printmap(ULL maze,int x,int y) {
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(i == x && j == y) printf("@");
            else if(maze & (1LL << U(i,j))) printf("X");
            else printf(".");
        }
        puts("");
    }
}

void solve() {
    st.clear();
    priority_queue<Node> q;
    q.push(Node(sx,sy,maze_comp(),0,0,0));
    int ans = INF;
    while(!q.empty()) {
        Node now = q.top(); q.pop();
        int x = now.x, y = now.y, dis = now.dis, bomb = now.bomb;
        ULL maze = now.maze, vis = now.vis;
        if(x == ex && y == ey) {
            ans = dis;
            break;
        }
        for(int i = 0;i < 4;i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(!in_bd(nx,ny)) continue;
            if(maze & (1LL << U(nx,ny))) {
                //如果是墙
                if(bomb == 0) continue;
                int nbomb = bomb - 1;
                ULL nmaze = maze ^ (1LL << U(nx,ny));
                Node nnode = 
                    Node(nx,ny,nmaze,dis + 2,nbomb,vis);
                if(insert_st(nnode)) q.push(nnode);
            }
            else {
                //空地
                if (mp[nx][ny] >= '1' && mp[nx][ny] <= '9' && !(vis & (1LL << U(nx,ny)))) {
                    //炸弹储备
                    ULL nvis = vis | (1LL << U(nx,ny));
                    int nbomb = bomb + mp[nx][ny] - '0';
                    Node nnode = 
                        Node(nx,ny,maze,dis + 1,nbomb,nvis);
                    if(insert_st(nnode)) {
                        q.push(nnode);
                    }
                }
                else {
                    Node nnode = Node(nx,ny,maze,dis + 1,bomb,vis);
                    if(insert_st(nnode)) q.push(nnode);
                }
            }
        }
    }
    printf("%d\n",ans == INF ? -1 : ans);
}

int main() {
    while(scanf("%d%d",&n,&m), n) {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                scanf(" %c",&mp[i][j]);
                if(mp[i][j] == 'S') {
                    sx = i; sy = j; mp[i][j] = '.';
                }
                if(mp[i][j] == 'D') {
                    ex = i; ey = j; mp[i][j] = '.';
                }
            }
        }
        solve();
    }
    return 0;
}
