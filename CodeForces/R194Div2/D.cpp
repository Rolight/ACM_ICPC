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
const int maxn = 1000 + 5;
int ok[maxn][maxn];

int main() {
    int n,m; cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int x,y; scanf("%d%d",&x,&y);
        ok[x][1] = ok[x][n] = ok[1][y] = ok[n][y] = -1;
    }
    ok[1][1] = ok[1][n] = ok[n][1] = ok[n][n] = -1;
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        if(ok[1][i] != -1) ans++;
        if(ok[i][1] != -1) ans++;
    }
    if(n % 2 == 1 && ok[(n + 1) / 2][1] != -1 && ok[1][(n + 1) / 2] != -1) ans--;
    cout << ans << endl;
    return 0;
}
