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
const int maxn = 10;
int d[maxn],t[maxn];
int v;
int f[1000000 + 5],g[1000000 + 5];

void solve() {
    for(int i = 1;i <= v;i++) {
        for(int j = 9;j >= 1;j--) {
            if(i - d[j] >= 0) {
                if(f[i] < f[i - d[j]] + 1) {
                    f[i] = f[i - d[j]] + 1;
                    g[i] = j;
                }
            }
        }
    }
    while(v > 0) {
        if(g[v] == 0) break;
        printf("%d",g[v]);
        v -= d[g[v]];
    }
    puts("");
}

int main() {
    scanf("%d",&v);
    int maxt = -1,maxnum = 0;
    for(int i = 1;i <= 9;i++) scanf("%d",&d[i]);
    for(int i = 9;i >= 1;i--) {
        t[i] = v / d[i];
        if(t[i] > maxt) {
            maxt = t[i];
            maxnum = i;
        }
    }
    if(maxt == 0) {
        puts("-1");
    } else {
        solve();
    }
    return 0;
}
