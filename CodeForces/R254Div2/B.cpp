#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 60;

struct Obj {
    int cnt,id;
    bool e[maxn];
    bool operator < (const Obj &x) const {
        return cnt > x.cnt;
    }
};

Obj med[maxn];
bool vis[maxn];
int n,m,len[maxn];

int dfs(int now) {
    vis[now] = true;
    int ret = 1;
    for(int i = 1;i <= n;i++) {
        if(med[now].e[i] && !vis[i]) {
            ret += dfs(i);
        }
    }
    return ret;
}

void ccc(int now,int col) {
    vis[now] = true;
    med[now].id = col;
    for(int i = 1;i <= n;i++) {
        if(med[now].e[i] && !vis[i]) {
            ccc(i,col);
        }
    }
}

int main() {
    scanf("%d%d",&n,&m);
    memset(med,0,sizeof(med));
    for(int i = 1;i <= n;i++) med[i].id = -1;
    for(int i = 1;i <= m;i++) {
        int a,b; scanf("%d%d",&a,&b);
        if(!med[a].e[b]) med[a].cnt++;
        if(!med[b].e[a]) med[b].cnt++;
        med[a].e[b] = true;
        med[b].e[a] = true;
    }
    int t = 0,cnt = 0;
    for(int i = 1;i <= n;i++) {
        if(med[i].id == -1) {
            ccc(i,cnt++);
        }
    }
    for(int i = 1;i <= n;i++) {
        memset(vis,0,sizeof(vis));
        int ret = dfs(i) - 1;
        len[med[i].id] = max(len[med[i].id],ret);
    }
    for(int i = 0;i < cnt;i++) {
        t += len[i];
    }
    cout << (1ll << t) << endl;
    return 0;
}
