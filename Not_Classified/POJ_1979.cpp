#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <string>


using namespace std;

const int maxn = 30;
char mp[maxn][maxn];
int cnt;

void dfs(int x,int y) {
    if(mp[x][y] != '.') return;
    mp[x][y] = '@';
    dfs(x + 1,y);
    dfs(x - 1,y);
    dfs(x,y + 1);
    dfs(x,y - 1);
}

int main() {
    int n,m;
    while(scanf("%d%d",&m,&n),n) {
        memset(mp,0,sizeof(mp));
        int sx,sy;
        cnt = 0;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                scanf(" %c",&mp[i][j]);
                if(mp[i][j] == '@') {
                    sx = i; sy = j;
                }
            }
        }
        mp[sx][sy] = '.';
        dfs(sx,sy);
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                if(mp[i][j] == '@') cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
