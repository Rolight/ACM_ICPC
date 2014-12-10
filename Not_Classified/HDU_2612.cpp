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
const int maxn = 205;
const int dirx[] = {0,0,1,-1};
const int diry[] = {1,-1,0,0};
char mp[maxn][maxn];
int dy[maxn][maxn],dm[maxn][maxn];
int n,m,yx,yy,mx,my;

void bfs(int x,int y,int d[maxn][maxn]) {
    queue<pair<int,int> > q;
    q.push(MP(x,y));
    d[x][y] = 0;
    while(!q.empty()) {
        pii now = q.front(); q.pop();
        x = now.first; y = now.second;
        for(int i = 0;i < 4;i++) {
            int nx = x + dirx[i], ny = y + diry[i];
            if(mp[nx][ny] != '#' && d[nx][ny] == -1) {
                d[nx][ny] = d[x][y] + 1;
                q.push(MP(nx,ny));
            }
        }
    }
}

int main() {
    while(scanf("%d%d",&n,&m) != EOF) {
        memset(mp,'#',sizeof(mp));
        memset(dy,-1,sizeof(dy));
        memset(dm,-1,sizeof(dm));
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                scanf(" %c",&mp[i][j]);
                if(mp[i][j] == 'Y') {
                    yx = i; yy = j;
                }
                if(mp[i][j] == 'M') {
                    mx = i; my = j;
                } 
            }
        }

        bfs(yx,yy,dy);
        bfs(mx,my,dm);
        int ans = INF;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) if(mp[i][j] == '@' && ~dy[i][j] && ~dm[i][j]) {
                ans = min(ans,dy[i][j] + dm[i][j]);
            }
        }
        printf("%d\n",ans * 11);
    }
    return 0;
}
