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
const int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
char mp[maxn][maxn];
int dist[maxn][maxn], pre[maxn][maxn];
int n,m;

void bfs() {
    queue<int> qx,qy;
    memset(dist,-1,sizeof(dist));
    qx.push(1); qy.push(1);
    dist[1][1] = 0;
    while(!qx.empty()) {
        int x = qx.front(), y = qy.front();
        qx.pop(); qy.pop();
        for(int i = 0;i < 4;i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(mp[nx][ny] == 'X') continue;
            int nt = dist[x][y] + (mp[nx][ny] == '.' ? 1 : mp[nx][ny] - '0' + 1);
            if((dist[nx][ny] == -1 || nt < dist[nx][ny])) {
                dist[nx][ny] = nt;
                pre[nx][ny] = (x - 1) * m + y - 1;
                qx.push(nx); qy.push(ny);
            }
        }
    }
}

void print_path(int x,int y) {
    int px = pre[x][y] / m + 1, py = pre[x][y] % m + 1;
    if(pre[x][y] != 0) print_path(px, py);
    int pt = dist[px][py], nt = dist[x][y];
    printf("%ds:(%d,%d)->(%d,%d)\n", pt + 1, px - 1, py - 1, x - 1, y - 1);
    if(mp[x][y] != '.') {
        for(int i = 1;i <= mp[x][y] - '0';i++) {
            printf("%ds:FIGHT AT (%d,%d)\n",
                    pt + 1 + i, x - 1, y - 1);
        }
    }
}

int main() {
    while(scanf("%d%d",&n,&m) != EOF) {
        memset(mp,'X',sizeof(mp));
        for(int i = 1;i <= n;i++) {
            scanf("%s",mp[i] + 1);
            mp[i][m + 1] = 'X';
        }
        bfs();
        if(dist[n][m] == -1) puts("God please help our poor hero.");
        else {
            printf("It takes %d seconds to reach the target position, let me show you the way.\n",dist[n][m]);
            print_path(n,m);
        }
        puts("FINISH");
    }
    return 0;
}
