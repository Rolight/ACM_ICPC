#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>


using namespace std;

const int maxn = 105;
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,-1,1,-1,1};
int n,m;
char mp[maxn][maxn];
bool vis[maxn][maxn];

void bfs(int x,int y) {
    queue<int> qx,qy;
    qx.push(x);
    qy.push(y);
    while(!qx.empty()) {
        x = qx.front(); qx.pop();
        y = qy.front(); qy.pop();
        vis[x][y] = true;
        for(int i = 0;i < 8;i++) {
            int nx = x + dx[i],ny = y + dy[i];
            if(mp[nx][ny] == '@' && !vis[nx][ny]) {
                qx.push(nx); qy.push(ny);
            }
        }
    }
}

int main() {
    while(scanf("%d%d",&n,&m),n) {
        memset(mp,0,sizeof(mp));
        memset(vis,0,sizeof(vis));
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                scanf(" %c",&mp[i][j]);
            }
        }
        int cnt = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                if(mp[i][j] == '@' && !vis[i][j]) {
                    bfs(i,j);
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
