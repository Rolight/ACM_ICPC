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

int n,m,x,y,a,b;

bool ok(LL mid) {
    LL x1 = a * mid,y1 = b * mid;
    if(x1 > n || y1 > m) return false;
    return true;
}

LL gcd(LL a,LL b) {
    return b == 0 ? a : gcd(b,a % b);
}

int main() {
    cin >> n >> m >> x >> y >> a >> b;
    LL pp = gcd(a,b); a /= pp; b /= pp;
    LL l = 1,r = 1e9,ans = -1;
    while(l <= r) {
        LL mid = (l + r) / 2;
        if(ok(mid)) {
            ans = mid; l = mid + 1;
        } else r = mid - 1;
    }
    
    return 0;
}
