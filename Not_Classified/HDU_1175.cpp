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
const int maxn = 1005;
const int mod = maxn * 200;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int mp[maxn][maxn];
int dk[maxn][maxn];
int n,m,q;

void bfs(int x1,int y1) {
    queue<int> qx,qy;
    qx.push(x1); qy.push(y1);
    dk[x1][y1] = 0;
    bool first = true;
    while(!qx.empty()) {
        int x = qx.front(), y = qy.front();
        qx.pop(); qy.pop();
        first = false;
        for(int i = 0;i < 4;i++) {
            int nx = x + dx[i], ny = y + dy[i];
            while(mp[nx][ny] == 0  && dk[x][y] < 3 && dk[nx][ny] >= dk[x][y] + 1) {
                dk[nx][ny] = dk[x][y] + 1;
                qx.push(nx); qy.push(ny);
                if(mp[nx][ny] == mp[x1][y1]) break;
                nx += dx[i]; ny += dy[i];
            }
            if(mp[nx][ny] == mp[x1][y1]) {
                dk[nx][ny] = min(dk[nx][ny],dk[x][y] + 1);
            }
        }
    }
}

int main() {
    while(scanf("%d%d",&n,&m), n) {
        memset(mp,-1,sizeof(mp));
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                scanf("%d",&mp[i][j]);
            }
        }
        scanf("%d",&q);
        for(int i = 0;i < q;i++) {
            int x1,y1,x2,y2;
            bool pok = false;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(mp[x1][y1] != mp[x2][y2]  || mp[x1][y1] == 0) {
                puts("NO"); continue;
            }
            memset(dk,0x3f,sizeof(dk));
            int inf = dk[0][0];
            bfs(x1,y1);
            if(dk[x2][y2] <= 3) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
