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
#include <cmath>

using namespace std;

typedef unsigned long long LL;
const int maxn = 4e7 + 5;
bool cnt[maxn];

int main() {
    LL ans = 0,n; cin >> n;
    if(n == 0) {
        printf("%d\n",1);
        return 0;
    }
    for(LL i = 0;i < n;i++) {
        LL y = sqrt(n * n - i * i);
        LL x = sqrt(n * n - y * y);
        if(x <= i) cnt[i] = true;
        ans++;
    }
    for(int i = 0;i < n;i++) if(!cnt[i]) {
        ans++;
    }
    cout << ans * 4 << endl;
    return 0;
}


