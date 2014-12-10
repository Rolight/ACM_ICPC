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

int main() {
    int n;
    while(cin >> n) {
        LL ans = 0;
        for(LL i = 0;(1LL << i) <= n;i++) {
            ans += (n + (1 << i)) / (1 << (i + 1)) * (1 << i);
        }
        cout << ans << endl;
    }
    return 0;
}
