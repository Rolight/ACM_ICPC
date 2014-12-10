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
int n,k;

void solve() {
    if(k == 1 || k * 3 > n) {
        puts("-1"); return;
    } 
    int cnt = 0;
    for(int i = 1;i <= k;i++) {
        for(int j = 1;j <= (n - k) / k;j++) {
            if(cnt != 0) putchar(' ');
            printf("%d",i);
            cnt++;
        }
    }
    for(int i = cnt + 1;i <= n - k;i++) printf(" %d",k);
    for(int i = 1;i <= k;i++) printf(" %d",i);
    putchar('\n');
}

int main() {
    scanf("%d%d",&n,&k);
    solve();
    return 0;
}
