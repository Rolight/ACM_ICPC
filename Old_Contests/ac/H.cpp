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
#include <stack>
#include <sstream>
#include <numeric>
#include <fstream>
#include <functional>

using namespace std;

#define MP make_pair
#define PB push_back
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> pii;
const int INF = INT_MAX / 3;
const double eps = 1e-10;
const LL LINF = 1e17;
const double DINF = 1e60;
const double pi = acos(-1);
double a,b,c,d;

double calc(double a,double b,double deg) {
    return sqrt(a * a + b * b - 2 * a * b * cos(deg));
}

int main() {
    while(scanf("%lf%lf%lf%lf",&a,&b,&c,&d) != EOF) {
        if(a < eps) {
            puts("0.00");
            continue;
        }
        if(b < eps) {
            printf("%.2f\n",c);
            continue;
        }
        if(c < eps) {
            puts("0.00");
            continue;
        }
        a = a / 180 * pi; b = b / 180 * pi; c = c / 180 * pi; 
        d = d / 180 * pi;
        a = max(a,eps), b = max(b,eps), c = max(c,eps), d = max(d,eps);
        double ab = 1,
               db = ab * sin(a + b) / sin(pi - a - b - c),
               pb = ab * sin(b) / sin(pi - b - c),
               dp = db - pb,
               ac = ab * sin(c + d) / sin(pi - a - b - c - d),
               bc = ab * sin(a + b) / sin(pi - a - b - c - d),
               ad = ab * sin(c) / sin(pi - a - b - c),
               cd = ac - ad,
               be = ab * sin(b) / sin(pi - b - c - d),
               ce = bc - be,
               de = calc(cd,ce,pi - a - b - c - d),
               ae = ab * sin(c + d) / sin(pi - b - c - d),
               ap = ab * sin(c) / sin(pi - b - c),
               pe = ae - ap,
               cosp = (de * de + pe * pe - dp * dp) / (2 * de * pe),
               ans = acos(cosp);
        printf("%.2f\n",ans / pi * 180);
    }
    return 0;
}
