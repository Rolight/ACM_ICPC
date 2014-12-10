#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

typedef long long LL;
const int maxn = 1e5 + 10;
int ori[maxn],dist[maxn],n;
vector<int> ch[maxn];
bool chg[maxn];

int dfs(int now,int fa,int dep,bool odd,bool even) {
    int ret = 0;
    bool ns = false;
    if(dep & 1) {
        if(odd) ori[now] ^= 1;
        if(ori[now] != dist[now]) {
            odd = !odd; ori[now] ^= 1; chg[now] = true; ret = 1;
        }
    }
    else {
        if(even) ori[now] ^= 1;
        if(ori[now] != dist[now]) {
            even = !even; ori[now] ^= 1; chg[now] = true; ret = 1;
        }
    }
    for(int i = 0;i < ch[now].size();i++) if(ch[now][i] != fa) {
        ret += dfs(ch[now][i],now,dep + 1,odd,even);
    }
    return ret;
}

int main() {
    scanf("%d",&n);
    for(int i = 1;i < n;i++) {
        int u,v; scanf("%d%d",&u,&v);
        ch[u].push_back(v); 
        ch[v].push_back(u);
    }
    for(int i = 1;i <= n;i++) scanf("%d",&ori[i]);
    for(int i = 1;i <= n;i++) scanf("%d",&dist[i]);
    printf("%d\n",dfs(1,-1,1,false,false));
    for(int i = 1;i <= n;i++) if(chg[i]) printf("%d\n",i);
    return 0;
}


