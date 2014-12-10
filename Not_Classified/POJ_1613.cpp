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
#include <sstream>

using namespace std;

typedef long long LL;
const int INF = INT_MAX / 4;
const int maxn = 10100;
const int maxm = 505 * 2;

struct Edge {
    int u,v,w,lctime,lstime;
    vector<int> st,et;
};

int n,m,s,t,cnt;
int d[maxn],inq[maxn],first[maxn],nxt[maxm];
Edge e[maxm];
bool vis[maxn];
string buf;

void swap(int &a,int &b) {
    int tmp = a; a = b; b = tmp;
}

int gettime(int id,int stime) {
    Edge &ne = e[id];
    if(ne.lstime != -1 && stime >= ne.lstime) return stime;
    if(ne.lctime != -1 && stime >= ne.lctime) return -1;
    int mm = min(ne.st.size(),ne.et.size());
    for(int i = 0;i < mm;i++) {
        if(stime >= ne.st[i] && ne.et[i] - stime >= ne.w) return stime;
        if(ne.st[i] >= stime && ne.et[i] - ne.st[i] >= ne.w) return ne.st[i];
    }
    return -1;
}


void solve() {
    queue<int> q;
    q.push(s);
    for(int i = 1;i <= n;i++) {
        d[i] = INF;
        vis[i] = false;
    }
    d[s] = 0;
    vis[s] = true;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        vis[x] = false;
        for(int i = first[x];i;i = nxt[i]) {
            int gotime = gettime(i,d[x]);
            if(gotime != -1 &&  d[e[i].v] > gotime + e[i].w) {
                d[e[i].v] = gotime + e[i].w;
                if(!vis[e[i].v]) {
                    q.push(e[i].v);
                    vis[e[i].v] = true;
                }
            }
        }
    }
    if(d[t] >= INF) puts("*");
    else printf("%d\n",d[t]);
}

int main() {
    while(scanf("%d",&n),n) {
        getchar();
        memset(first,0,sizeof(first));
        memset(nxt,0,sizeof(nxt));
        for(int i = 1;i <= maxm;i++) {
            e[i].st.clear();
            e[i].et.clear();
            e[i].lctime = -1;
            e[i].lstime = -1;
        }
        scanf("%d%d%d",&m,&s,&t);
        getchar();
        for(int i = 1;i <= m;i++) {
            int st,et;
            getline(cin,buf);
            istringstream sin(buf);
            sin >> e[i].u >> e[i].v >> e[i].w;
            e[i].st.push_back(0);
            while(1) {
                if(sin >> et) e[i].et.push_back(et);
                else break;
                if(sin >> st) e[i].st.push_back(st);
                else break;
            }
            if(e[i].st.size() > e[i].et.size()) {
                e[i].lstime = e[i].st.back();
            } 
            else e[i].lctime = e[i].et.back();
            nxt[i] = first[e[i].u];
            first[e[i].u] = i;
        }
        for(int i = m + 1;i <= m * 2;i++) {
            e[i] = e[i - m];
            swap(e[i].u,e[i].v);
            nxt[i] = first[e[i].u];
            first[e[i].u] = i;
        }
        solve();
    }
    return 0;
}
