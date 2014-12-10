/*
ID: flsnnx1
LANG: C++
TASK: maze1
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int maxn = 400;
char buf[maxn][maxn];
int dist[maxn][maxn],d1[maxn][maxn],d2[maxn][maxn];
int n,m;
int sx[2],sy[2],scnt;

void findstr() {
    //找行上的起点
    for(int j = 1;j <= m;j++) {
        if(buf[1][j] == ' ') {
            sx[scnt] = 0; sy[scnt] = j; scnt++;
        }
        if(buf[n][j] == ' ') {
            sx[scnt] = n + 1; sy[scnt] = j; scnt++;
        }
    }
    //找列上面的起点
    for(int i = 1;i <= n;i++) {
        if(buf[i][1] == ' ') {
            sx[scnt] = i; sy[scnt] = 0; scnt++;
        }
        if(buf[i][m] == ' ') {
            sx[scnt] = i; sy[scnt] = m + 1; scnt++;
        }
    }
}

int dx[4] = {-2,2,0,0},dy[4] = {0,0,-2,2};
void bfs(int x,int y,int dd[maxn][maxn]) {
    queue<int> qx,qy;
    qx.push(x);
    qy.push(y);
    while(!qx.empty()) {
        x = qx.front(); qx.pop();
        y = qy.front(); qy.pop();
        //printf("now is %d %d\n",x,y);
        for(int i = 0;i < 4;i++) {
            int nx = x + dx[i],ny = y + dy[i];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !dd[nx][ny]) {
                if(buf[x + dx[i] / 2][y + dy[i] / 2] != ' ') continue;
                dd[nx][ny] = dd[x][y] + 1;
                qx.push(nx);
                qy.push(ny);
            }
        }
    }
}

void solve() {
    int ans = 0;
    findstr();
    //printf("find %d str\n",scnt);
    for(int i = 0;i < scnt;i++) {
        bfs(sx[i],sy[i],i == 0 ? d1 : d2);
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            //printf("%d %d\n",d1[i][j],d2[i][j]);
            ans = max(ans,min(d1[i][j],d2[i][j]));
        }
    }
    printf("%d\n",ans);
}

int main() {
    freopen("maze1.in","r",stdin);
    freopen("maze1.out","w",stdout);
    scanf("%d%d",&m,&n);
    n = 2 * n + 1;
    m = 2 * m + 1;
    getchar();
    for(int i = 1;i <= n;i++) {
        gets(buf[i] + 1);
    }
    solve();
    return 0;
}
