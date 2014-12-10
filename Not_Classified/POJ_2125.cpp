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
const int maxn = 400;
const int maxm = maxn * maxn;
const int INF = INT_MAX / 4;
int cap[maxm],first[maxn],nxt[maxm],v[maxm];
int level[maxn],q[maxn],qs,qe;
int n,m,s,t,ecnt;

void adde(int uu,int vv,int ww) {
    //printf("add %d %d %d\n",uu,vv,ww);
    v[ecnt] = vv; cap[ecnt] = ww; nxt[ecnt] = first[uu]; first[uu] = ecnt++;
    v[ecnt] = uu; cap[ecnt] = 0; nxt[ecnt] = first[vv]; first[vv] = ecnt++;
}

bool bfs() {
    memset(level,0,sizeof(level));
    level[s] = 1;
    qs = qe = 0;
    q[qe++] = s;
    while(qs < qe) {
        int now = q[qs++];
        for(int i = first[now];~i;i = nxt[i]) {
            if(cap[i] && !level[v[i]]) {
                level[v[i]] = level[now] + 1;
                q[qe++] = v[i];
            }
        }
    }
    //printf("level %d\n",level[t]);
    return level[t];
}

int dfs(int now,int alpha) {
    if(now == t) return alpha;
    int sum = 0;
    for(int i = first[now];~i && alpha;i = nxt[i]) {
        if(cap[i] && level[v[i]] == level[now] + 1) {
            int ret = dfs(v[i],min(alpha,cap[i]));
            sum += ret; alpha -= ret;
            cap[i] -= ret; cap[i ^ 1] += ret;
        }
    }
    if(!sum) level[now] = -1;
    return sum;
}

bool vis[maxn];
vector<pair<int,char> > path;
void dfs1(int now) {
    vis[now] = true;
    for(int i = first[now];~i;i = nxt[i]) {
        if(!vis[v[i]] && cap[i]) dfs1(v[i]);
    }
}
void solve() {
    int ans = 0,cnt = 0;
    while(bfs()) ans += dfs(s,INF);
    printf("%d\n",ans);
    memset(vis,0,sizeof(vis));
    path.clear();
    dfs1(s);
    for(int i = first[s];~i;i = nxt[i]) if(!vis[v[i]])  
        path.push_back(make_pair(v[i],'-'));
    for(int i = first[t];~i;i = nxt[i]) if(vis[v[i]]) 
        path.push_back(make_pair(v[i] - n,'+'));
    int mm = path.size();
    printf("%d\n",mm);
    for(int i = 0;i < mm;i++) printf("%d %c\n",path[i].first,path[i].second);
}

int main() {
    while(scanf("%d%d",&n,&m) != EOF) {
        ecnt = 0;
        memset(first,-1,sizeof(first));
        //printf("s:%d t:%d\n",s,t);
        s = 0; t = 2 * n + 1;
        for(int i = 1;i <= n;i++) {
            int noww; scanf("%d",&noww); adde(i + n,t,noww);
        }
        for(int i = 1;i <= n;i++) {
            int noww; scanf("%d",&noww); adde(s,i,noww);
        }
        for(int i = 0;i < m;i++) {
            int a,b; scanf("%d%d",&a,&b);
            adde(a,b + n,INF);
        }
        solve();
    }
    return 0;
}
