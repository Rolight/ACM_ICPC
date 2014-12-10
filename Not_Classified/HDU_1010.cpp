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

const int maxn = 15;

char mp[maxn][maxn];
bool vis[maxn][maxn];
int dx[4] = {-1,1,0,0},dy[4] = {0,0,-1,1};
int T,ex,ey;

int abs(int x) {
    if(x < 0) return -x;
    else return x;
}

bool dfs(int x,int y,int t) {
    if(mp[x][y] == 'D' && t == T) return true;
    if(t >= T) return false;
    vis[x][y] = true;
    bool ret = false;
    int dis = abs(x - ex) + abs(y - ey);
    if(dis % 2 != (T - t) % 2) return false;
    for(int d = 0;d < 4;d++) {
        int nx = x + dx[d],ny = y + dy[d];
        if(mp[nx][ny] != 'X' && !vis[nx][ny]) {
            ret |= dfs(nx,ny,t + 1);
        }
        if(ret) return true;
    }
    vis[x][y] = false;
    return false;
}

int main() {
//    freopen("in.txt","r",stdin);
    int n,m,t,sx,sy,cnt_p;
    while(scanf("%d%d%d",&n,&m,&t),n) {
        cnt_p = 0;
        memset(vis,0,sizeof(vis));
        T = t;
        for(int i = 0;i <= n + 1;i++) {
            for(int j = 0;j <= m + 1;j++) {
                mp[i][j] = 'X';
            }
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                scanf(" %c",&mp[i][j]);
                if(mp[i][j] == 'S') {
                    sx = i; sy = j;
                }
                else if(mp[i][j] == '.') cnt_p++;
                else if(mp[i][j] == 'D'){
                    ex = i; ey = j;
                }
            }
        }
        if(t <= cnt_p + 1&& dfs(sx,sy,0)) {
            puts("YES");
        } else puts("NO");
    }
    return 0;
}
