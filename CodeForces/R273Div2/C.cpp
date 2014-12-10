#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <iostream>
#include <string>

using namespace std;
 
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int INF = INT_MAX / 3;
const double eps = 1e-8;
const LL LINF = 1e17;
const double DINF = 1e60;

int main() {
    LL a[3], ans = 0;
    cin >> a[0] >> a[1] >> a[2];
    while(1) {
        sort(a, a + 3);
        printf("%lld %lld %lld\n", a[0], a[1], a[2]);
        LL tt = min(a[2] / 2, a[1]);
        if(tt == 0) break;
        ans += tt; a[1] -= tt; a[2] -= tt * 2;
    }
    ans += a[0];
    cout << ans << endl;
    return 0;
}
