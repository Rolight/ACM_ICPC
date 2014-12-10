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
int e[sz][sz],incnt[sz],appsz;
int path[sz];
char buf[1024];
bool vis[sz],app[sz];

int ch(char c) {
    return c - 'a';
}

void dfs(int cnt) {
    if(cnt == appsz) {
        for(int i = 0;i < appsz;i++) {
            printf("%c",path[i] + 'a');
        }
        puts("");
        return;
    }
    for(int i = 0;i < sz;i++) if(app[i] && !vis[i] && incnt[i] == 0) {
        int tmp[sz]; memcpy(tmp,incnt,sizeof(tmp));
        vis[i] = true;
        path[cnt] = i;
        for(int j = 0;j < sz;j++) if(e[i][j]) incnt[j]--;
        dfs(cnt + 1);
        vis[i] = false;
        memcpy(incnt,tmp,sizeof(tmp));
    }
}

int main() {
    while(gets(buf)) {
        memset(vis,0,sizeof(vis));
        memset(incnt,0,sizeof(incnt));
        memset(e,0,sizeof(e));
        memset(app,0,sizeof(app));
        int len = strlen(buf),nc = 0;
        appsz = 0;
        for(int i = 0;i < len;i++) if(buf[i] != ' ') {
            app[ch(buf[i])] = true;
        }
        for(int i = 0;i < sz;i++) appsz += app[i];
        gets(buf);
        len = strlen(buf);
        int a,b;
        for(int i = 0;i < len;i++) if(buf[i] != ' ') {
            if(nc == 0) a = ch(buf[i]),nc = 1;
            else {
                b = ch(buf[i]); nc = 0;
                if(e[a][b] == false) incnt[b]++;
                e[a][b]  = true;
            }
        }
        dfs(0);
        puts("");
    }
    return 0;
}
