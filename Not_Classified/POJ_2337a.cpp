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
const int maxn = 26;
const int maxlen = 25;
struct Edge {
    char str[maxlen];
    int u,v;
    Edge(int u,int v,char *ss):u(u),v(v) {
        strcpy(str,ss);
    }
    bool operator < (const Edge &x) const {
        return strcmp(str,x.str) < 0;
    }
};
vector<Edge> e[maxn];
vector<bool> vis[maxn];
char buf[maxlen];
int n,incnt[maxn],outcnt[maxn],fa[maxn];
stack<pair<int,int> > ans;

void dfs(int now) {
    for(int i = 0;i < e[now].size();i++) if(!vis[now][i]) {
        vis[now][i] = true;
        dfs(e[now][i].v);
        ans.push(make_pair(now,i));
    }
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i = 0;i < 26;i++) {
            e[i].clear();
            vis[i].clear();
            incnt[i] = outcnt[i] = 0;
        }
        for(int i = 0;i < n;i++) {
            scanf("%s",buf);
            int len = strlen(buf);
            char u = buf[0],v = buf[len - 1];
            e[u - 'a'].push_back(Edge(u - 'a',v - 'a',buf));
            vis[u - 'a'].push_back(false);
            incnt[v - 'a']++;
            outcnt[u - 'a']++;
        }
        int str = INT_MAX,one = 0,rone = 0;
        for(int i = 0;i < 26;i++)  {
            sort(e[i].begin(),e[i].end());
            if(outcnt[i] - incnt[i] == 1) {
                one++; str = min(str,i);
            }
            if(outcnt[i] - incnt[i] == -1) {
                rone++;
            }
            //printf("%d %d\n",outcnt[i],incnt[i]);
        }
        if(!((one == 0 && rone == 0) || (one == 1 && rone == 1))) {
            puts("***");
            continue;
        }
        dfs(str);
        if(ans.size() < n) {
            puts("***");
            continue;
        }
        bool first = true;
        while(!ans.empty()) {
            if(first) first = false;
            else putchar('.');
            pair<int,int> now = ans.top();
            printf("%s",e[now.first][now.second].str);
            ans.pop();
        }
        puts("");
    }
    return 0;
}
