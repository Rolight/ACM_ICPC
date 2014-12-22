
/*
ID: flsnnx1
LANG: C++
TASK: concom
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
const int maxn = 105;
const int maxm = maxn * maxn;
int first[maxn],nxt[maxm],v[maxm],w[maxm];
int pp[maxn],m,ecnt;
bool vis[maxn];
vector<pair<int,int> > ans;

 
void adde(int uu,int vv,int ww) {
    v[ecnt] = vv; w[ecnt] = ww;
    nxt[ecnt] = first[uu];
    first[uu] = ecnt++;
}

void dfs(int str,int now) {
    if(pp[now] > 50) {
        ans.push_back(make_pair(str,now));
    }
    vis[now] = true;
    for(int i = first[now];~i;i = nxt[i]) {
        pp[v[i]] += w[i];
        if(pp[v[i]] > 50 && !vis[v[i]]) dfs(str,v[i]);
    }
}

int main() {
    freopen("concom.in","r",stdin);
    freopen("concom.out","w",stdout);
    memset(first,-1,sizeof first);
    scanf("%d",&m);
    for(int i = 0;i < m;i++) {
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        adde(a,b,c);
    }
    for(int i = 1;i <= 100;i++) if(~first[i]) {
        memset(pp,0,sizeof(pp));
        memset(vis,0,sizeof(vis));
        dfs(i,i);
    }
    sort(ans.begin(),ans.end());
    for(int i = 0;i < ans.size();i++) {
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return 0;
}
