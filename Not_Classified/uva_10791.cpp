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
const int maxn = 10000;
LL n;

LL solve(LL n) {
    if(n == 1) return 2;
    LL lim = sqrt(n + 1);
    LL ans = 0,cnt = 0;
    for(int i = 2;i <= lim;i++) if(n % i == 0) {
        LL t = 1,tmp = n / i;
        while(n % i == 0) {
            t *= i; n /= i;
        }
        cnt++;
        ans += t;
    }
    if(n != 1) {
        cnt++; ans += n;
    }
    if(cnt == 1) return ans + 1;
    return ans;
}

int main() {
    int kase = 1;
    while(cin >> n,n) cout << "Case " << kase++ << ": "  << solve(n) << endl;
    return 0;
}
