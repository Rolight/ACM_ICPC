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
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const double DINF = 1e60;
const int maxn = 5005;
const LL mod = 1e9 + 7;
int n, a, b, k;
int f[maxn][maxn], sum[maxn][maxn];
int lbd[maxn], rbd[maxn];

int mabs(int x) {
    return x < 0 ? -x : x;
}

int main() {
    cin >> n >> a >> b >> k;
    for(int i = 1; i <= n; i++) {
        lbd[i] = INF; rbd[i] = -INF;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(mabs(j - i) < mabs(j - b)) {
                lbd[i] = min(lbd[i], j);
                rbd[i] = max(rbd[i], j);
            }
        }
    }
    lbd[b] = rbd[b] = b;
    f[0][a] = 1;
    for(int i = 1; i <= n; i++) sum[0][i] = sum[0][i - 1] + f[0][i];
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            int l = lbd[j], r = rbd[j];
            f[i][j] = (sum[i - 1][r] - sum[i - 1][l - 1] + mod) % mod;
            if(lbd[j] <= j && rbd[j] >= j) 
                f[i][j] = (f[i][j] - f[i - 1][j] + mod) % mod;
        }
        for(int j = 1; j <= n; j++) 
            sum[i][j] = (sum[i][j - 1] + f[i][j]) % mod;
    }
    cout << sum[k][n] << endl;
    return 0;
}
