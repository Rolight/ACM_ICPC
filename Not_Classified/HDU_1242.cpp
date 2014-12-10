#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 205;

int n,m,dis[maxn][maxn],ex,ey;
char mp[maxn][maxn];
int dx[4] = {
    0,0,-1,1
};
int dy[4] = {
    1,-1,0,0
};

int bfs(int x,int y) {
    queue<int> qx,qy;
    qx.push(x);
    qy.push(y);
    dis[x][y] = 0;
    while(!qx.empty()) {
        x = qx.front();
        y = qy.front();
        qx.pop();
        qy.pop();
        for(int i = 0;i < 4;i++) {
            int nx = x + dx[i],ny = y + dy[i];
            if((mp[nx][ny] == 'x' || mp[nx][ny] == '.' || mp[nx][ny] == 'r')) {
                int ndis;
                if(mp[nx][ny] == 'x') ndis = dis[x][y] + 2;
                else ndis = dis[x][y] + 1;
                if(dis[nx][ny] == -1 || dis[nx][ny] > ndis) {
                    qx.push(nx); qy.push(ny); dis[nx][ny] = ndis;
                }
            }
        }
    }
    return dis[ex][ey];
}

int main() {
    while(scanf("%d%d",&n,&m) != EOF) {
        memset(dis,-1,sizeof(dis));
        int sx,sy;
        for(int i = 0;i <= n + 1;i++) {
            for(int j = 0;j <= m + 1;j++) {
                mp[i][j] = '#';
            }
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                scanf(" %c",&mp[i][j]);
                if(mp[i][j] == 'a') {
                    sx = i; sy = j;
                }
                if(mp[i][j] == 'r') {
                    ex = i; ey = j;
                }
            }
        }
        int ret = bfs(sx,sy);
        if(ret == -1) puts("Poor ANGEL has to stay in the prison all his life.");
        else printf("%d\n",ret);
    }
    return 0;
}

