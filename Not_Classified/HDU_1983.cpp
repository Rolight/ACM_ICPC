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
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int n,m,maxt,sx,sy,ex,ey;
char mp[maxn][maxn];
int ds[maxn][maxn], de[maxn][maxn];

void bfs(int x,int y,int d[maxn][maxn]) {
    
    /*
    printf("now mp:\n");
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            printf("%c",mp[i][j]);
        }
        puts("");
    }
    */

    queue<pii> q;
    q.push(MP(x,y));
    d[x][y] = 0;
    while(!q.empty()) {
        pii now = q.front(); q.pop();
        x = now.first; y = now.second;
        for(int i = 0;i < 4;i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(mp[nx][ny] != '#' && d[nx][ny] == -1) {
                d[nx][ny] = d[x][y] + 1;
                q.push(MP(nx,ny));
            }
        }
    }
}

bool ok() {
    memset(ds,-1,sizeof(ds));
    memset(de,-1,sizeof(de));
    bfs(sx,sy,ds); bfs(ex,ey,de);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) if(mp[i][j] == 'J' && ~ds[i][j] && ~de[i][j]) {
            if(ds[i][j] + de[i][j] <= maxt) {
                return false;
            }
        }
    }
    return true;
}

bool dfs(int now) {
    if(now == 0) return ok();
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) if(mp[i][j] == '.' || mp[i][j] == 'J') {
            char tmp = mp[i][j];
            mp[i][j] = '#';
            bool ret = dfs(now - 1);
            mp[i][j] = tmp;
            if(ret) return ret;
        }
    }
    return false;
}

void solve() {
    if(ok()) puts("0");
    else if(dfs(1)) puts("1");
    else if(dfs(2)) puts("2");
    else if(dfs(3)) puts("3");
    else puts("4");
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&n,&m,&maxt);
        memset(mp,'#',sizeof(mp));
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                scanf(" %c",&mp[i][j]);
                if(mp[i][j] == 'S') {
                    sx = i; sy = j; mp[i][j] = '.';
                }
                if(mp[i][j] == 'E') {
                    ex = i; ey = j; mp[i][j] = '.';
                }
            }
        }

        solve();
    }
    return 0;
}
