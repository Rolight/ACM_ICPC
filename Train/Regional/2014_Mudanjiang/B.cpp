#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <iostream>
#include <string>

using namespace std;
 
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;
const int maxn = 2e5 + 10;

int head[maxn], nxt[maxn << 1], u[maxn << 1], v[maxn << 1], ecnt;
int n, dist[maxn], pre[maxn], path[maxn], id[maxn];
bool vis[maxn], del[maxn << 1];

void adde(int uu, int vv) {
    u[ecnt] = uu; v[ecnt] = vv; nxt[ecnt] = head[uu]; head[uu] = ecnt++;
}

//bfs 参数为起点， 返回终点（离起点最远的一个点）
int bfs(int str, int col) {
    memset(vis, 0, sizeof(vis));
    vis[str] = true;
    dist[str] = 0; pre[str] = -1;
    queue<int> q; q.push(str);
    int now = 0;
    while(!q.empty()) {
        now = q.front(); q.pop();
        id[now] = col;
        for(int i = head[now]; ~i; i = nxt[i]) if(!del[i]) {
            if(!vis[v[i]]) {
                pre[v[i]] = now;
                dist[v[i]] = dist[now] + 1;
                q.push(v[i]); vis[v[i]] = true;
            }
        }
    }
    return now;
}

void solve() {
    //第一遍， 求树的直径
    int s, t, len = 0, du, dv;
    s = bfs(1, -1); t = bfs(s, -1);
    for(int i = t; ~i; i = pre[i]) {
        path[len++] = i;
    }
    //删除最中间的边
    for(int i = t, j = 0; ~i; i = pre[i], j++) {
        if((j + 1) == len / 2) {
            du = i; dv = pre[i]; break;
        }
    }
    for(int i = 0; i < ecnt; i++) {
        if((u[i] == du && v[i] == dv) || (u[i] == dv && v[i] == du)) {
            del[i] = true;
        }
    }
    //对两边的子树分别求直径
    int maxlen = 0, p[2], pcnt = 0;
    for(int i = 1; i <= n; i++) if(id[i] == -1) {
        s = bfs(i, pcnt); t = bfs(s, pcnt);
        len = 0;
        for(int j = t; ~j; j = pre[j]) path[len++] = j;
        for(int j = t, k = 0; ~j; j = pre[j], k++) if((k + 1) == (len + 1) / 2) {
            p[pcnt++] = j; break;
        }
        maxlen = max(maxlen, len / 2);
    }
    printf("%d %d %d\n", maxlen, p[0], p[1]);
}

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        ecnt = 0;
        scanf("%d", &n);
        memset(head, -1, sizeof(head));
        memset(del, 0, sizeof(del));
        for(int i = 0; i < n - 1; i++) {
            int a, b; scanf("%d%d", &a, &b);
            adde(a, b); adde(b, a);
        }
        solve();
    }
    return 0;
}
