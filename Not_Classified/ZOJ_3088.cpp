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
const int maxn = 1005;
const int INF = INT_MAX / 2;
int d[maxn],n,m,k,ansa,ansb,d1[maxn];
int pre[maxn],pre1[maxn];
double ansval;
bool vis[maxn];

struct Edge {
    int u,v,w;
    Edge(int u,int v,int w):u(u),v(v),w(w) {}
};

vector<Edge> ed[maxn],eup[maxn];

void spfa(vector<Edge> e[],int *d,int *pre,int str,char mod) {
    memset(vis,0,sizeof(vis));
    if(mod == 's') for(int i = 1;i <= n;i++) d[i] = INF;
    else for(int i = 1;i <= n;i++) d[i] = -INF;
    d[str] = 0;
    pre[str] = 0;
    queue<int> q;
    q.push(str);
    vis[str] = true;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        vis[x] = false;
        for(int i = 0;i < e[x].size();i++) {
            bool add = false;
            Edge &now = e[x][i];
            if(mod == 's') {
                if(d[now.v] > d[x] + now.w) add = true;
            } else {
                if(d[now.v] < d[x] + now.w) add = true;
            }
            if(add) {
                d[now.v] = d[x] + now.w;
                pre[now.v] = x;
                if(vis[now.v] == false) {
                    q.push(now.v);
                    vis[now.v] = true;
                }
            }

        }
    }
}

void print_up(int now) {
    if(now != ansa) putchar(' ');
    printf("%d",now);
    if(now != ansb) print_up(pre[now]);
}

void print_down(int now) {
    if(now != ansb) {
        print_down(pre1[now]);
        printf(" %d",now);
    }
}

void solve() {
    ansval = -1;
    for(int j = 1;j <= n;j++) if(eup[j].size()) {
        spfa(eup,d,pre,j,'s');
        spfa(ed,d1,pre1,j,'l');
        for(int i = 1;i <= n;i++) if(d[i] != 0 && d[i] < INF) {
            if(d1[i] != 0 && d1[i] < INF) {
                if((double)d1[i] / d[i] > ansval) {
                    ansval = (double)d1[i] / d[i];
                    ansa = i;
                    ansb = j;
                }
            }
        }
    }
    spfa(eup,d,pre,ansb,'s');
    spfa(ed,d1,pre1,ansb,'l');
    print_up(ansa);
    print_down(ansa);
    printf("\n%.3lf\n",ansval);
}

int main() {
    int T; scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&n,&m,&k);
        for(int i = 1;i <= n;i++) {
            ed[i].clear();
            eup[i].clear();
        }
        for(int i = 1;i <= m;i++) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            ed[a].push_back(Edge(a,b,c));
        }
        for(int i = 1;i <= k;i++) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            eup[b].push_back(Edge(b,a,c));
        }
        solve();
    }
    return 0;
}
