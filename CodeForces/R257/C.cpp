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
LL n,m,k;

bool ok(LL val) {
    
}

int main() {
    cin >> n >> m >> k;
    LL l = 1,r = k;
    while(l < r) {
        LL mid = (l + r + 1) >> 1;
        if(ok(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}
