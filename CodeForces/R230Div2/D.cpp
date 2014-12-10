#include <cstdio>
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
#include <iostream>

using namespace std;

typedef long long LL;
const int maxn = 55;
int dist[maxn][maxn],n;
LL f[maxn][maxn][maxn];

LL hano(int n,int a,int b) {
    LL &note = f[n][a][b];
    if(n == 0) return 0;
    if(~note) return note;
    int c = 6 - a - b;
    LL ret1 = hano(n - 1,a,c) + dist[a][b] + hano(n - 1,c,b);
//    LL ret2 = hano(n - 1,a,b)  + dist[a][c] + hano(n - 1,b,a) + dist[c][b] + hano(n - 1,a,b);
    return note = ret1;
}

int main() {
    memset(f,-1,sizeof(f));
    for(int i = 1;i <= 3;i++) {
        for(int j = 1;j <= 3;j++) {
            cin >> dist[i][j];
        }
    }
    for(int k = 1;k <= 3;k++) {
        for(int i = 1;i <= 3;i++) {
            for(int j = 1;j <= 3;j++) {
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    int n; cin >> n;
    cout << hano(n,1,3) << endl;
    return 0;
}


