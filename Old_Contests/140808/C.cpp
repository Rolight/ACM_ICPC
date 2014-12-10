#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <bitset>
#include <list>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <ctime>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-9;
const LL LINF = 1e17;
const double DINF = 1e60;
const double g = 9.8;
const double pi = acos(-1);
double v;

double mysin(double x) {
    return sin(x / 180 * pi);
}

double f(double x) {
    return v * mysin(2 * x) * v / g;
}

bool equal(double a,double b) {
    return fabs(a - b) < eps;
}

int main() {
    int T; cin >> T;
    for(int kase = 1;kase <= T;kase++) {
        double x;
        cin >> v >> x;
        double l = 0,r = 45,ans = 0;
        if(equal(f(45),x)) ans = 45;
        else {
            while(fabs(r - l) >= eps) {
                double mid = (l + r) / 2;
                if(f(mid) > x) {
                    ans = mid; r = mid - eps;
                }
                else l = mid + eps;
            }
        }
        printf("Case #%d: %.7f\n",kase,ans);
    }
    return 0;
}
