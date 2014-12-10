#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 200;
int mat[maxn][maxn];
long long cc[maxn][maxn];
bool vis[maxn][maxn];
int T,n,m;

long long dfs(int x,int y) {
    if(x == n && y == m) return 1;
    if(vis[x][y]) return cc[x][y];
    for(int i = x;i <= n;i++) {
        for(int j = y;j <= m;j++) {
            int dis = abs(i - x) + abs(j - y);
            if(dis == 0) continue;
            if(mat[i][j] == -1) continue;
            if(dis <= mat[x][y]) cc[x][y] += dfs(i,j) % 10000;
            else break;
        }
    }
    vis[x][y] = true;
    cc[x][y] %= 10000;
    return cc[x][y];
}

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        memset(mat,-1,sizeof(mat));
        memset(vis,false,sizeof(vis));
        memset(cc,0,sizeof(cc));
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                scanf("%d",&mat[i][j]);
            }
        }
        cout << dfs(1,1) % 10000LL << endl;
    }
    return 0;
}

