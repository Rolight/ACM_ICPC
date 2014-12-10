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
char buf[1024][30];
struct Edge {
    int v,str,vis;
    Edge(int v,int str,int vis):v(v),str(str),vis(vis) {}
    bool operator < (const Edge &x) const {
        return strcmp(buf[str],buf[x.str]) < 0;
    }
};
vector<Edge> e[maxn];
int n,fa[maxn],incnt[maxn],outcnt[maxn],cnt_one,ext[maxn];
stack<int> ans;

int findp(int x) {
    return x == fa[x] ? x : fa[x] = findp(fa[x]);
}

void dfs(int now) {
    for(int i = 0;i < e[now].size();i++) {
        if(e[now][i].vis == 0) {
            e[now][i].vis = 1;
            dfs(e[now][i].v);
            ans.push(e[now][i].str);
        }
    }
}

bool ok() {
    int cnt_rone = 0,cnt_root = 0;
    for(int i = 0;i < 26;i++) if(ext[i]) {
        int now = outcnt[i] - incnt[i];
        if(now == 1) cnt_one++;
        else if(now == -1) cnt_rone++;
        else if(now != 0) return false;
        if(findp(i) == i) cnt_root++;
    }
    if(cnt_root != 1) return false;
    if(cnt_one == 0 && cnt_rone == 0) return true;
    if(cnt_one == 1 && cnt_rone == 1) return true;
    return false;
}

int main() {
    //freopen("in.txt","r",stdin);
    int T; scanf("%d",&T);
    for(int kase = 1;kase <= T;kase++) {
        scanf("%d",&n);
        cnt_one = 0;
        for(int i = 0;i < 26;i++) {
            fa[i] = i;
            e[i].clear();
            incnt[i] = outcnt[i] = ext[i] = 0;
            ext[i] = 0;
        }
        for(int i = 0;i < n;i++) {
            scanf("%s",buf[i]);
            int len = strlen(buf[i]),u = buf[i][0] - 'a',v = buf[i][len - 1] - 'a';
            int pa = findp(u),pb = findp(v);
            outcnt[u]++; incnt[v]++;
            if(pa != pb) fa[pa] = pb;
            e[u].push_back(Edge(v,i,0));
            ext[u] = ext[v] = 1;
        }
        for(int i = 0;i < 26;i++) sort(e[i].begin(),e[i].end());
        if(!ok()) {
            puts("***"); continue;
        }
        int str;
        for(int i = 0;i < 26;i++) if(e[i].size() != 0) {
            if(cnt_one == 1) {
                if(outcnt[i] - incnt[i] == 1) {
                    str = i; break;
                }
            } else {
                str = i; break;
            }
        }
        dfs(str);
        bool first = true;
        while(!ans.empty()) {
            if(first) first = false;
            else putchar('.');
            printf("%s",buf[ans.top()]);
            ans.pop();
        }
        puts("");
    }
    return 0;
}
