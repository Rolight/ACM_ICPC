#include <cstdio>
#include <cstring>
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
const int sz = 26;

char mp[100][100];
int n,m,sx[sz],sy[sz],ex[sz],ey[sz];;
int e[sz][sz],incnt[sz];
int path[sz],appsz;
bool vis[sz],app[sz];

void getpos(char c) {
    int strrow = -1,strcol = -1;
    int endrow,endcol;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(mp[i][j] == c) {
                if(strrow == -1) strrow = i;
                endrow = i;
            }
        }
    }
    for(int j = 1;j <= m;j++) {
        for(int i = 1;i <= n;i++) {
            if(mp[i][j] == c) {
                if(strcol == -1) strcol = j;
                endcol = j;
            }
        }
    }
    sx[c - 'A'] = strrow;
    sy[c - 'A'] = strcol;
    ex[c - 'A'] = endrow;
    ey[c - 'A'] = endcol;
}

void addedge(int sx,int sy,int ex,int ey,char c) {
    for(int i = sx;i <= ex;i++) {
        for(int j = sy;j <= ey;j++) {
            if(i == sx || i == ex || j == sy || j == ey) {
                if(mp[i][j] != c) {
                    int &now = e[c - 'A'][mp[i][j] - 'A'];
                    if(now == 0) incnt[mp[i][j] - 'A']++;
                    now = 1;
                }
            }
        }
    }
}

void dfs(int cnt) {
    if(cnt == appsz) {
        for(int i = 0;i < appsz;i++) {
            printf("%c",path[i] + 'A');
        }
        puts("");
        return;
    }
    for(int i = 0;i < sz;i++) if(app[i] && !vis[i] && incnt[i] == 0) {
        int tmp[sz]; memcpy(tmp,incnt,sizeof(tmp));
        path[cnt] = i;
        vis[i] = true;
        for(int j = 0;j < sz;j++) if(e[i][j]) incnt[j]--;
        dfs(cnt + 1);
        vis[i] = false;
        memcpy(incnt,tmp,sizeof(tmp));
    }
}

void solve() {
    memset(e,0,sizeof(e));
    memset(incnt,0,sizeof(incnt));
    memset(vis,0,sizeof(vis));
    for(int i = 0;i < sz;i++) if(app[i]) getpos('A' + i);
    for(int i = 0;i < sz;i++) if(app[i]) {
        addedge(sx[i],sy[i],ex[i],ey[i],'A' + i);
    }
    dfs(0);
}

int main() {
    while(scanf("%d%d",&n,&m) != EOF) {
        memset(mp,0,sizeof(mp));
        memset(app,0,sizeof(app));
        for(int i = 1;i <= n;i++) {
            scanf("%s",mp[i] + 1);
            for(int j = 1;j <= m;j++) app[mp[i][j] - 'A'] = true;
        }
        appsz = 0;
        for(int i = 0;i < sz;i++) appsz += app[i];
        solve();
    }
    return 0;
}
