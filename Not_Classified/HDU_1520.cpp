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
const int maxn = 6000 + 5;
int fa[maxn],n,c[maxn];
vector<int> ch[maxn];
int f[maxn][2];

int dfs(int now,bool prev) {
    int m  = ch[now].size(),ret;
    if(m == 0) return prev ? 0 : c[now];
    int &note = f[now][prev];
    if(note != -1) return note;
    int ret1 = c[now],ret2 = 0;
    for(int i = 0;i < m;i++) {
        int id = ch[now][i];
        ret1 += dfs(id,1); 
        ret2 += dfs(id,0);
    }
    if(prev) ret =  ret2;
    else ret =  max(ret1,ret2);
    return note = ret;
}

int main() {
    while(scanf("%d",&n) != EOF) {
        memset(f,-1,sizeof(f));
        memset(fa,0,sizeof(fa));
        for(int i = 1;i <= n;i++) scanf("%d",&c[i]);
        for(int i = 1;i <= n;i++) ch[i].clear();
        int a,b;
        while(scanf("%d%d",&a,&b), a) {
            fa[a] = b;
            ch[b].push_back(a);
        }
        int root; 
        for(int i = 1;i <= n;i++) if(fa[i] == 0) root = i;
        int ret = dfs(root,0);
        printf("%d\n",ret);
    }
    return 0;
}
