#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <string>
#include <iostream>
#include <map>
#include <cstdlib>
#include <list>
#include <set>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
const int maxw = 35;
const int maxh = 65;
const int maxn = maxw * maxh;
const int INF = INT_MAX / 3;
struct Point {
    int x,y;
    Point(int x = 0,int y = 0):x(x),y(y) {}
    bool operator < (const Point &p) const {
        if(x == p.x) return y < p.y;
        return x < p.x;
    }
    bool operator == (const Point &p) const {
        return p.x == x && p.y == y;
    }
};

struct Feet {
    Point l,r;
    Feet(Point l,Point r):l(l),r(r) {}
    bool operator < (const Feet &x) const {
        if(l == x.l) return r < x.r;
        return l < x.l;
    }
};

struct Edge {
    int u,v,w;
    Edge(int u=0,int v=0,int w=0):u(u),v(v),w(w) {}
};

map<Feet,int> pi;
vector<int> goal,str;
vector<Edge> e[maxn * 20];
int d[maxn * 20],n,m,picnt;
char mp[maxh][maxw];
bool vis[maxn * 20];
vector<Point> tmp;

void spfa(int str) {
    queue<int> q;
    memset(vis,0,sizeof(vis));
    q.push(str);
    for(int i = 0;i <= pi.size();i++) d[i] = INF;
    d[str] = 0;
    vis[str] = true;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        vis[x] = false;
        for(int i = 0;i < e[x].size();i++) {
            Edge &now = e[x][i];
            if(d[now.v] > d[x] + now.w) {
                d[now.v] = d[x] + now.w;
                if(vis[now.v] == false) {
                    q.push(now.v);
                    vis[now.v] = true;
                }
            }
        }
    }
}

int getid(Feet ft) {
    if(pi.count(ft) == 0) {
        pi[ft] = picnt++;
        return picnt - 1;
    }
    return pi[ft];
}

int abs(int x) {
    return x < 0 ? -x : x;
}

void addfootright(int rx,int ry) {
    tmp.clear();
    for(int i = rx - 3;i <= rx + 3;i++) if(i >= 1 && i <= n) {
        for(int j = ry - 3;j < ry;j++) if(j >= 1 && abs(i - rx) + abs(j - ry) <= 3) {
            if(mp[i][j] == 'T') {
                int vv = getid(Feet(Point(i,j),Point(rx,ry)));
                if(find(goal.begin(),goal.end(),vv) == goal.end()) {
                    goal.push_back(vv);
                }
            }
            if(mp[i][j] != 'X') {
                tmp.push_back(Point(i,j));
            }
            if(mp[i][j] == 'S' && mp[rx][ry] != 'S') {
                tmp.push_back(Point(i,j));
            }
        }
    }
    int tmps = tmp.size();
    for(int i = 0;i < tmps;i++) {
        for(int j = 0;j < tmps;j++) if(i != j) {
            int u = getid(Feet(Point(tmp[i].x,tmp[i].y),Point(rx,ry)));
            int v = getid(Feet(Point(tmp[j].x,tmp[j].y),Point(rx,ry)));
            char c = mp[tmp[j].x][tmp[j].y];
            int w = (c == 'T' || c == 'S') ? 0 : c - '0';
            e[u].push_back(Edge(u,v,w));
        }
    }
}

void addfootleft(int lx,int ly) {
    tmp.clear();
    for(int i = lx - 3;i <= lx + 3;i++) if(i >= 1 && i <= n) {
        for(int j = ly + 1;j <= ly + 3;j++) if(j <= m && abs(i - lx) + abs(j - ly) <= 3) {
            if(mp[i][j] == 'T') {
                int vv = getid(Feet(Point(lx,ly),Point(i,j)));
                if(find(goal.begin(),goal.end(),vv) == goal.end()) {
                    goal.push_back(vv);
                }
            }
            if(mp[i][j] != 'X') {
                tmp.push_back(Point(i,j));
            }
            if(mp[i][j]  == 'S' && mp[lx][ly] != 'S') {
                tmp.push_back(Point(i,j));
            }
        }
    }
    int tmps = tmp.size();
    for(int i = 0;i < tmps;i++) {
        for(int j = 0;j < tmps;j++) if(i != j) {
            int u = getid(Feet(Point(lx,ly),Point(tmp[i].x,tmp[i].y)));
            int v = getid(Feet(Point(lx,ly),Point(tmp[j].x,tmp[j].y)));
            char c = mp[tmp[j].x][tmp[j].y];
            int w = (c == 'T' || c == 'S') ? 0 : c - '0';
            e[u].push_back(Edge(u,v,w));
        }
    }
}

void solve() {
    picnt = 0;
    pi.clear();
    goal.clear();
    str.clear();
    for(int i = 0;i < n * m * 20;i++) e[i].clear();
    //枚举出发点
    for(int i = 1;i <= m;i++) {
        for(int j = i - 1;j > 0 && j - i <= 3;j--) {
            if(mp[n][i] == 'S' && mp[n][j] == 'S') {
                str.push_back(getid(Feet(Point(n,j),Point(n,i))));
                break;
            }
        }
    }
    //建图 复杂度 30*60*20
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            addfootleft(i,j);
            addfootright(i,j);
        }
    }
   //spfa 复杂度 30*30*60*10 = 10^6
    int ans = INF;
    spfa(str[0]);
    for(int j = 0;j < goal.size();j++) {
        ans = min(ans,d[goal[j]]);
    }
    if(ans >= INF) printf("-1\n");
    else printf("%d\n",ans);
}

int main() {
    while(scanf("%d%d",&m,&n),n) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                scanf(" %c",&mp[i][j]);
            }
        }
        solve();
    }
    return 0;
}
