#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

const int maxn = 10000 + 5;

vector<int> edge[maxn];
bool vis[maxn];
int maxv[maxn];

void bfs(int u) {
    queue<int> q; q.push(u);
    queue<int> dq; dq.push(1);
    memset(vis,0,sizeof(vis));
    vis[u] = true;
    while(!q.empty()) {
        int dis = dq.front(); dq.pop();
        u = q.front(); q.pop();
        maxv[u] = max(maxv[u],dis);
        int m = edge[u].size();
        for(int i = 0;i < m;i++) {
            if(!vis[edge[u][i]]) {
                q.push(edge[u][i]);
                dq.push(dis + 1);
                vis[edge[u][i]] = true;
            }
        }
    }
}

int main() {
    int T; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++) {
        int nz,nr; scanf("%d%d",&nz,&nr);
        memset(maxv,0,sizeof(maxv));
        for(int i = 0;i < maxn;i++) edge[i].clear();
        for(int i = 0;i < nz;i++) {
            int mz,mr; scanf("%d%d",&mz,&mr);
            for(int j = 0;j < mr;j++) {
                int tmp; scanf("%d",&tmp);
                edge[mz].push_back(tmp);
                edge[tmp].push_back(mz);
            }
        }
        for(int i = 0;i < nr;i++) {
            int mr; scanf("%d",&mr);
            for(int j = 0;j < mr;j++) {
                int tmp; scanf("%d",&tmp);
                bfs(tmp);
            }
        }
        int ans = 20000000,ansi = ans;
        for(int i = 0;i < maxn;i++) if(edge[i].size()) {
            if(maxv[i] < ans) {
                ans = maxv[i]; ansi = i;
            }
        }
        printf("%d %d\n",ans,ansi);
    }
    return 0;
}

