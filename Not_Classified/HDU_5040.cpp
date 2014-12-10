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
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 505;
const int dx[] = {-1, 0, 1, 0, 0};
const int dy[] = {0, 1, 0, -1, 0};
map<char, int> dmp;
char mp[maxn][maxn];
int n, sx, sy, ex, ey;

void init() {
    dmp['S'] = 0; dmp['W'] = 1; dmp['N'] = 2; dmp['E'] = 3;
}

struct Node {
    int dist, x, y;
    Node(int x, int y, int dist): dist(dist), x(x), y(y) {}
    bool operator < (const Node &node) const {
        if(dist == node.dist) {
            return abs(x - ex) + abs(y + ey) > abs(node.x - ex) + abs(node.y - ey);
        }
        return dist > node.dist;
    }
};

bool cvis[maxn][maxn];
bool can() {
    memset(cvis, 0, sizeof(cvis));
    queue<PII> q;
    q.push(MP(sx, sy));
    while(!q.empty()) {
        PII now = q.front(); q.pop();
        int x = now.first, y = now.second;
        if(x == ex && y == ey) break;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(mp[nx][ny] != '#' && !cvis[nx][ny]) {
                q.push(MP(nx, ny));
                cvis[nx][ny] = true;
            }
        }
    }
    return cvis[ex][ey];
}

bool vis[maxn][maxn][4];

int getstate(int x, int y, int nowtime) {
    if(mp[x][y] == '#') return -1;
    if(mp[x][y] != '.') return 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(mp[nx][ny] == '.' || mp[nx][ny] == '#') continue;
        int nd = (dmp[mp[nx][ny]] + nowtime) % 4;
        if(nd == i) return 1;
    }
    return 0;
}

void solve() {
    if(!can()) {
        puts("-1"); return;
    }
    memset(vis, 0, sizeof(vis));
    priority_queue<Node> q;
    q.push(Node(sx, sy, 0));
    vis[sx][sy][0] = true;
    while(!q.empty()) {
        Node now = q.top(); q.pop();
        int x = now.x, y = now.y, dist = now.dist;
        if(x == ex && y == ey) {
            printf("%d\n", dist);
            return;
        }
        for(int i = 0; i < 5; i++) {
            if(i == 4) {
                if(!vis[x][y][(dist + 1) % 4]) {
                    vis[x][y][(dist + 1) % 4] = true;
                    q.push(Node(x, y, dist + 1));
                }
                continue;
            }
            int nx = x + dx[i], ny = y + dy[i];
            int nowstate = getstate(x, y, dist), nxtstate = getstate(nx, ny, dist);
            if(nxtstate == -1) continue;
            if(nowstate == 0 && nxtstate == 0) {
                if(vis[nx][ny][(dist + 1) % 4]) continue;
                vis[nx][ny][(dist + 1) % 4] = true;
                q.push(Node(nx, ny, dist + 1));
            }
            else if(!vis[nx][ny][(dist + 3) % 4]) {
                vis[nx][ny][(dist + 3) % 4] = true;
                q.push(Node(nx, ny, dist + 3));
            }
        }
    }
    puts("-1");
}

int main() {
    init();
    int T; scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++) {
        scanf("%d", &n);
        memset(mp, '#', sizeof(mp));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                scanf(" %c", &mp[i][j]);
                if(mp[i][j] == 'M') {
                    sx = i; sy = j; mp[i][j] = '.';
                }
                if(mp[i][j] == 'T') {
                    ex = i; ey = j; mp[i][j] = '.';
                }
            }
        }
        printf("Case #%d: ", kase);
        solve();
    }
    return 0;
}
