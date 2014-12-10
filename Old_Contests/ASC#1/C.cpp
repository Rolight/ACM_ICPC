#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 5e5 + 10;
int head[maxn], nxt[maxn << 1], v[maxn << 1], ecnt;
int n, f[maxn][3];
vector<int> ans;

int adde(int uu, int vv) {
    v[ecnt] = vv; nxt[ecnt] = head[uu]; head[uu] = ecnt++;
}

void init() {
    memset(head, -1, sizeof(head));
    ecnt = 0; ans.clear();
}

void dfs(int now) {
    if(head[now] == -1) {
        f[now][0] = 0; f[now][1] = 1; return;
    }
    f[now][0] = 0; f[now][1] = 1;
    int tmp = 0;
    for(int i = head[now]; ~i; i = nxt[i]) {
        dfs(v[i]);
        f[now][1] += f[v[i]][0];
        tmp += f[v[i]][0];
    }
    for(int i = head[now]; ~i; i = nxt[i]) {
        f[now][0] = max(f[now][0], f[v[i]][1] + tmp - f[v[i]][0]);
    }
    f[now][0] = max(f[now][0], tmp);
}

void dfs1(int now, int p) {
    if(p == 1) ans.push_back(now);
    int tmp = 0;
    for(int i = head[now]; ~i; i = nxt[i]) {
        dfs1(v[i], 0);
        tmp += f[v[i]][0];
    }
    if(p == 0 && f[now][p] != tmp) {
        for(int i = head[now]; ~i; i = nxt[i]) {
            if(f[now][p] == f[v[i]][1] + tmp - f[v[i]][0]) {
                dfs1(v[i], 1); break;
            }
        }
    }
}

int main() {
    int T; scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++) {
        if(kase > 1) puts("");
        scanf("%d", &n);
        init();
        for(int i = 2; i <= n; i++) {
            int nowfa; scanf("%d", &nowfa);
            adde(nowfa, i);
        }
        dfs(1);
        int pp = f[1][0];
        dfs1(1, 0);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        printf("%d\n", pp * 1000);
        for(int i = 0; i < ans.size(); i++) {
            if(i) putchar(' ');
            printf("%d", ans[i]);
        }
        puts("");
    }
    return 0;
}
