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
const int maxn = 25;
const int maxk = 10;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
char mp[maxn][maxn];
int n,m,t,sx,sy,ex,ey;
int dist[maxn][maxn][1 << maxk];

struct Node {
    int x,y,state;
    Node(int x,int y,int state): x(x), y(y), state(state) {}
};


int solve() {
    queue<Node> q;
    q.push(Node(sx,sy,0));
    dist[sx][sy][0] = 0;
    int x,y,nx,ny,s,ns;
    while(!q.empty()) {
        Node now = q.front(); q.pop();
        x = now.x; y = now.y; s = now.state;
        if(dist[x][y][s] == t) continue;
        if(x == ex && y == ey) return dist[x][y][s];
        for(int i = 0;i < 4;i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            ns = s;
            char nc = mp[nx][ny];
            if(nc == '*') continue;
            if(nc >= 'A' && nc <= 'J' && !(s & (1 << (nc - 'A')))) continue;
            if(nc >= 'a' && nc <= 'j') ns |= (1 << (nc - 'a'));
            if(dist[nx][ny][ns] == -1 || dist[nx][ny][ns] > dist[x][y][s] + 1) {
                dist[nx][ny][ns] = dist[x][y][s] + 1;
                q.push(Node(nx,ny,ns));
            }
        }
    }
    return -1;
}

int main() {
    while(scanf("%d%d%d",&n,&m,&t) != EOF) {
        memset(mp,'*',sizeof(mp));
        memset(dist,-1,sizeof(dist));
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                scanf(" %c",&mp[i][j]);
                if(mp[i][j] == '@') {
                    sx = i; sy = j; mp[i][j] = '.';
                }
                else if(mp[i][j] == '^') {
                    ex = i; ey = j; mp[i][j] = '.';
                }
            }
        }
        printf("%d\n",solve());
    }
    return 0;
}
