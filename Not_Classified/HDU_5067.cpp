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
#include <cmath>

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
const int maxn = 60;
int n, m, mat[maxn][maxn];
int pcnt, px[maxn], py[maxn], maxs;
int f[20][(1 << 11)];

int dist(int i, int j) {
    return abs(px[i] - px[j]) + abs(py[i] - py[j]);
}

int dfs(int now, int state) {
    if(state == maxs) return dist(now, 0);
    if(f[now][state] != -1) return f[now][state];
    int ret = INF;
    for(int i = 0; i < pcnt; i++) if(!((1 << i) & state)) {
        ret = min(ret, dfs(i, state | (1 << i)) + dist(now, i)); 
    }
    return f[now][state] = ret;
}

int main() {
    while(scanf("%d%d", &n ,&m) != EOF) {
        px[0] = py[0] = 1; pcnt = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                scanf("%d", &mat[i][j]);
                if(mat[i][j] != 0 && (i != 1 || j != 1)) {
                    px[pcnt] = i; py[pcnt] = j; pcnt++;
                }
            } 
        }
        memset(f, -1, sizeof(f));
        maxs = (1 << pcnt) - 1;
        int ret = dfs(0, 1);
        printf("%d\n", ret);
    }
    return 0;
}
