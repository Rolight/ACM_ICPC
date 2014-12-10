#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <iostream>
#include <string>
#include <cmath>

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
char buf[128];
int n;

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d %s", &n, buf);
        double ans = 0;
        for(int i = 0; i < n; i++) {
            double tmp; scanf("%lf", &tmp);
            if(tmp < 1e-10) continue;
            tmp /= 100;
            if(buf[0] == 'b') ans += tmp * log(tmp) / log(2.0);
            else if(buf[0] == 'n' ) ans += tmp * log(tmp);
            else ans += tmp * log(tmp) / log(10);
        }
        printf("%.13f\n", -ans);
    }
    return 0;
}
