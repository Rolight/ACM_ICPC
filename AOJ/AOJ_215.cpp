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
const int maxn = 105;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int fa[maxn * maxn];

int findset(int x) {
    return x == fa[x] ? x : fa[x] = findset(fa[x]);
}

struct Edge {
    int u, v, w1, w2;
    Edge(int u = 0, int v = 0, int w1 = 0, int w2 = 0): u(u), v(v), w1(w1), w2(w2) {}
};

vector<Edge> ve;
vector<int> num;
int val[maxn][maxn], n, s, t;

bool ok(int delta) {
    int numsize = num.size();
    for(int i = 0; i < numsize; i++) {
        int l = num[i], r = num[i] + delta;
        int esize = ve.size();
        for(int j = 0; j < maxn * maxn; j++) fa[j] = j;
        for(int j = 0; j < esize; j++) {
            if(ve[j].w1 < l || ve[j].w1 > r) continue;
            if(ve[j].w2 < l || ve[j].w2 > r) continue;
            int px = findset(ve[j].u), py = findset(ve[j].v);
            if(px != py) fa[px] = py;
        }
        if(findset(s) == findset(t)) return true;
    }
    return false;
}

int main() {
    while(scanf("%d", &n) != EOF) {
        num.clear(); ve.clear();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &val[i][j]);
                num.push_back(val[i][j]);
            }
        }

        sort(num.begin(), num.end());
        num.erase(unique(num.begin(), num.end()), num.end());
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int u = i * n + j;
                for(int d = 0; d < 4; d++) {
                    int nx = i + dx[d], ny = j + dy[d];
                    if(nx >= n || ny >= n || nx < 0 || ny < 0) continue;
                    int v = nx * n + ny;
                    ve.push_back(Edge(u, v, val[nx][ny], val[i][j]));
                }
            }
        }

        s = 0; t = (n - 1) * n + n - 1;
        //sort(ve.begin(), ve.end());
        int l = 0, r = 300, ans = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(ok(mid)) {
                r = mid - 1; ans = mid;
            }
            else l = mid + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
