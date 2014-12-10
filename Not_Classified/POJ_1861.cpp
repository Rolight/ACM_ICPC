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
const int maxn = 1500 + 20;
const int maxk = 15000 + 20;
int u[maxk],v[maxk],w[maxk],fa[maxn],r[maxk];
int n,m,maxlen,maxsum;
vector< pair<int,int> > ans;

bool cmp(int a,int b) {
    return w[a] < w[b];
}

int findp(int n) {
    return fa[n] == n ? n : fa[n] = findp(fa[n]);
}

int main() {
    bool first = true;
    while(~scanf("%d%d",&n,&m)) {
        ans.clear();
        for(int i = 0;i < m;i++) scanf("%d%d%d",&u[i],&v[i],&w[i]),r[i] = i;
        for(int i = 1;i <= n;i++) fa[i] = i;
        maxlen = maxsum = 0;
        sort(r,r + m,cmp);
        for(int i = 0;i < m;i++) {
            int x = r[i],pa = findp(u[x]),pb = findp(v[x]);
            if(pa == pb) continue;
            fa[pa] = pb;
            maxlen = max(maxlen,w[x]);
            ans.push_back(make_pair(u[x],v[x]));
        }
        maxsum = ans.size();
        sort(ans.begin(),ans.end());
        printf("%d\n%d\n",maxlen,maxsum);
        for(int i = 0;i < ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return 0;
}
