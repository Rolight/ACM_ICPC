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
const int maxn = 1000 + 5;
int n,k,d;
int ans[maxn][maxn];

int tmp[maxn],cnt;
void dfs(int now) {
    if(now == d) {
        for(int i = 0;i < d;i++) ans[i][cnt] = tmp[i];
        cnt++;
        return;
    }
    for(int i = 1;i <= k;i++) {
        tmp[now] = i;
        dfs(now + 1);
        if(cnt == n) return;
    }
}

int main() {
    cin >> n >> k >> d;
    dfs(0);
    if(cnt < n) {
        puts("-1"); return 0;
    }
    for(int i = 0;i < d;i++) {
        for(int j = 0;j < n;j++) {
            if(j) putchar(' ');
            printf("%d",ans[i][j]);
        }
        puts("");
    }
    return 0;
}

