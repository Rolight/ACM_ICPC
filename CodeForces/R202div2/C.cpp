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
const int maxn = 100000 + 5;
int n;
LL a[maxn],sum,mx;

bool ok(LL val) {
    bool ret =  (sum <= (n - 1) * val);
    return ret;
}

void solve() {
    LL l = mx,r = 2e10;
    LL ans;
    while(l <= r) {
        LL mid = (l + r) / 2;
        if(ok(mid)) ans = mid,r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << endl;
    
}

int main() {
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(a[i],mx);
    }
    solve();
    return 0;
}
