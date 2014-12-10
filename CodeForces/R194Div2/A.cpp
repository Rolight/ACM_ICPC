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
const int maxn = 105;
int ans[maxn][maxn];
int sum[maxn][maxn];

int main() {
    int n; cin >> n;
    int now = 1;
    for(int i = 1;i <= n;i++) {
        int cnt = 1,pos = i;
        while(cnt <= n) {
            ans[pos][i] = now++;
            pos = pos + 1;
            if(pos == n + 1) pos = 1;
            cnt++;
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(j > 1) putchar(' ');
            printf("%d",ans[i][j]);
        }
        puts("");
    }
    return 0;
}
