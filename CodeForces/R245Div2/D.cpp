#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

typedef long long LL;
const int maxn = 1005;
LL f1[maxn][maxn],f2[maxn][maxn];
LL g1[maxn][maxn],g2[maxn][maxn];
LL v[maxn][maxn],n,m;

int main() {
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> v[i][j];
        }
    }

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            f1[i][j] = max(f1[i - 1][j],f1[i][j - 1]) + v[i][j];
        }
    }

    for(int i = n;i >= 1;i--) {
        for(int j = m;j >= 1;j--) {
            f2[i][j] = max(f2[i + 1][j],f2[i][j + 1]) + v[i][j];
        }
    }

    for(int i = n;i >= 1;i--) {
        for(int j = 1;j <= m;j++) {
            g1[i][j] = max(g1[i + 1][j],g1[i][j - 1]) + v[i][j];
        }
    }

    for(int i = 1;i <= n;i++) {
        for(int j = m;j >= 1;j--) {
            g2[i][j] = max(g2[i - 1][j],g2[i][j + 1]) + v[i][j];
        }
    }

    LL ans = 0;
    for(int i = 2;i < n;i++) {
        for(int j = 2;j < m;j++) {
            LL v1 = f1[i - 1][j] + g1[i][j - 1] + g2[i][j + 1] + f2[i + 1][j];
            LL v2 = f1[i][j - 1] + g1[i + 1][j] + f2[i][j + 1] + g2[i - 1][j];
            ans = max(max(v2,v1),ans);
        }
    }

    cout << ans << endl;
    return 0;
}


