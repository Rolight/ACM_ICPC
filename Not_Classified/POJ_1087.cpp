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
const int maxn = 505;
const int INF = INT_MAX / 5;
int level[maxn],cap[maxn][maxn];
int n,m,k,s,t,cnt;
map<string,int> tb;
string receptacle,device;

int id(string &s) {
    if(tb.count(s) == 0) {
        tb[s] = ++cnt;
    } 
    return tb[s];
}

int q[maxn + maxn],qs,qe;
bool bfs() {
    qs = qe = 0;
    q[qe++] = s;
    memset(level,0,sizeof(level));
    level[s] = 1;
    while(qs < qe) {
        int v = q[qs++];
        for(int i = s;i <= cnt;i++) if(level[i] == 0 && cap[v][i]) {
            q[qe++] = i; level[i] = level[v] + 1;
        }
    }
    return level[t];
}

int dinic(int now,int alpha) {
    if(now == t) return alpha;
    int sum = 0;
    for(int i = s;i <= cnt;i++) if(level[i] == level[now] + 1) {
        if(alpha && cap[now][i]) {
            int ret = dinic(i,min(alpha,cap[now][i]));
            sum += ret;
            cap[now][i] -= ret;
            cap[i][now] += ret;
            alpha -= ret;
        }
    }
    return sum;
}

void solve() {
    int ans = 0;
    while(bfs()) ans += dinic(s,INF);
    printf("%d\n",m - ans);
}

int main() {
    while(cin >> n) {
        memset(cap,0,sizeof(cap));
        tb.clear();
        s = 0; t = n + 1;
        for(int i = 1;i <= n;i++) {
            cin >> receptacle;
            tb[receptacle] = i;
            cap[i][t]++;
        }
        cnt = n + 1;
        cin >> m;
        for(int i = 1;i <= m;i++) {
            cin >> device >> receptacle;
            int v = id(receptacle);
            cap[s][v]++;
        }
        cin >> k;
        for(int i = 1;i <= k;i++) {
            string a,b;
            cin >> a >> b;
            cap[id(a)][id(b)] = INF;
        }
        solve();
    }
    return 0;
}
