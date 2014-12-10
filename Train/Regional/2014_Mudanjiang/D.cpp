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
const int maxn = 60;
double f[maxn][maxn][maxn * maxn];
bool vis[maxn][maxn][maxn * maxn];
int n, m;

double dfs(int i, int j, int k) {
    int pi = n - i, pj = m - j;
    if(i < 0 || j < 0 || k > pi * pj) return 0;
    if(i == 0 && j == 0) return k;
    if(i == n && j == m) return dfs(i - 1, j - 1, k + 1);
    if(vis[i][j][k]) return f[i][j][k];
    double rest = n * m - k;
    double ret = dfs(i - 1, j - 1, k + 1) * i * j / rest
        + dfs(i, j, k + 1) * (pi * pj - k) / rest
        + dfs(i - 1, j, k + 1) * pj * i / rest
        + dfs(i, j - 1, k + 1) * pi * j / rest;
    vis[i][j][k] = true;
    return f[i][j][k] = ret;
}

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        memset(vis, 0, sizeof(vis));
        printf("%.13f\n", dfs(n, m, 0));
    }
    return 0;
}
