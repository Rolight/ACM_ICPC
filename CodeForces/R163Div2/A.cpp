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
const int maxn = 55;

int main() {
    int n; scanf("%d",&n);
    char now,last = '0';
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        scanf(" %c",&now);
        if(now == last) ans++;
        last = now;
    }
    printf("%d\n",ans);
    return 0;
}
