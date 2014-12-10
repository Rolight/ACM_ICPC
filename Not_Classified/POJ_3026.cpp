#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <iostream>
#include <map>
#include <cstdlib>
#include <list>
#include <set>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
const int maxn = 200;
int lowcost[maxn],dist[maxn][maxn],posx[maxn],posy[maxn],cnt,tmpd[maxn][maxn];
int dx[4] = {1,-1,0,0},dy[4] = {0,0,1,-1},n,m;
bool vis[maxn];
char mp[maxn][maxn];

void bfs(int x,int y,int id) {
    queue<int> qx,qy;
    memset(tmpd,-1,sizeof(tmpd));
    tmpd[x][y] = 0;
    qx.push(x); qy.push(y);
    while(!qx.empty()) {
        x = qx.front(); y = qy.front();
        qx.pop(); qy.pop();
        for(int i = 0;i < 4;i++) {
            int nx = x + dx[i],ny = y + dy[i];
            if(mp[nx][ny] != '#' && tmpd[nx][ny] == -1) {
                qx.push(nx); qy.push(ny);
                tmpd[nx][ny] = tmpd[x][y] + 1;
            } 
        }
    }
    for(int i = 0;i < cnt;i++) {
        dist[id][i] = tmpd[posx[i]][posy[i]];
    }
} 
char buf[1024];

int main() {
    gets(buf);
    int T; sscanf(buf,"%d",&T);
    while(T--) {
        gets(buf);
        sscanf(buf,"%d%d",&m,&n);
        cnt = 0;
        for(int i = 1;i <= n;i++) {
            gets(mp[i] + 1);
            for(int j = 1;j <= m;j++) {
                if(mp[i][j] == 'A' || mp[i][j] == 'S')  {
                    posx[cnt] = i; posy[cnt] = j;
                    cnt++;
                }
            }
        }
        for(int i = 0;i < cnt;i++) bfs(posx[i],posy[i],i);
        for(int i = 0;i < cnt;i++) lowcost[i] = dist[0][i];
        memset(vis,0,sizeof(vis));
        vis[0] = true;
        int ans = 0;
        for(int i = 1;i < cnt;i++) {
            int minv = INT_MAX,x;
            for(int j = 0;j < cnt;j++) if(!vis[j]) {
                if(lowcost[j] < minv) {
                    minv = lowcost[j]; x = j;
                }
            }
            vis[x] = true;
            ans += lowcost[x];
            for(int j = 0;j < cnt;j++) if(!vis[j]) {
                lowcost[j] = min(lowcost[j],dist[x][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
