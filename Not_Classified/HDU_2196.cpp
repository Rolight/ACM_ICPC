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
const int maxn = 10000 + 5;
int ch[maxn],nxt[maxn],v[maxn],w[maxn];
int mdep[maxn],sdep[maxn],f[maxn],mfrom[maxn];
int ecnt,n;

inline void addedge(int uu,int vv,int ww) {
    v[ecnt] = vv; w[ecnt] = ww; nxt[ecnt] = ch[uu]; ch[uu] = ecnt++;
}

//dfs求解从子节点过来的最大值和次大值
int dfs(int now) {
    mdep[now] = sdep[now] = 0;
    if(ch[now] == -1) return 0;
    for(int i = ch[now];~i;i = nxt[i]) {
        int ret = dfs(v[i]) + w[i];
        if(ret > mdep[now]) {
            sdep[now] = mdep[now]; mdep[now] = ret;
            mfrom[now] = v[i];
        }
        else if(ret > sdep[now]) sdep[now] = ret;
    }
    return mdep[now];
}

//dfs1求出答案
void dfs1(int now) {
    //如果当前节点是叶子节点，最大值必定是从父亲节点更新过来的
    if(ch[now] == -1) return;
    //否则往下更新
    for(int i = ch[now];~i;i = nxt[i]) {
        if(mfrom[now] == v[i]) {
            //如果当前儿子这边有最大深度
            f[v[i]] = max(f[now],sdep[now]) + w[i];
        }
        else f[v[i]] = max(f[now],mdep[now]) + w[i];
        dfs1(v[i]);
    }
    //最大距离来自儿子
    f[now] = max(f[now],mdep[now]);
}

int main() {
    while(scanf("%d",&n) != EOF) {
        memset(ch,-1,sizeof(ch));
        memset(f,0,sizeof(f));
        memset(mfrom,-1,sizeof(mfrom));
        ecnt = 0;
        for(int i = 2;i <= n;i++) {
            int a,b; scanf("%d%d",&a,&b);
            addedge(a,i,b);
        }
        dfs(1); 
        dfs1(1);
        for(int i = 1;i <= n;i++) printf("%d\n",f[i]);
    }
    return 0;
}
