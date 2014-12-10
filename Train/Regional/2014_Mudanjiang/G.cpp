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
const double eps = 1e-10;
const LL LINF = 1e17;
const double DINF = 1e60;
int X0, Y0, X1, Y1, X2, Y2, R, S;
LL ans;

double sq(double x) {
    return x * x;
}

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(sq(x1 - x2) + sq(y1 - y2));
}

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool eql(double a, double b) {
    return fabs(a - b) < eps;
}

bool isC(double x) {
    printf("isC %lf\n", x);
    return fabs(x - (int)x) < eps;
}

void addp(double x1, double y1, double x2, double y2, double k, double b) {
    if(eql(x1, x2)) {
        ans += 
    }
}

void calc(double k, double b) {
    double A = 1 + sq(k), B = 2 * k * b, C = sq(b) - sq(R);
    double delta = sq(B) - 4 * A * C;
    if(delta < 0) return;
    double px1 = -B + sqrt(delta), px2 = -B - sqrt(delta);
    px1 /= 2 * A; px2 /= 2 * A;
    double py1 = k * px1 + b, py2 = k * px2 + b;
    addp(px1, py1, px2, py2, k, b);
    return;
}

void solve() {
    double k = (double)(Y2 - Y1) / (X2 - X1), b = -k * X1 + Y1;
    double dx = S / dist(X1, Y1, X2, Y2), b1 = dx * sqrt(1 + sq(k)), b2 = -b1;
    ans = 0;
    calc(k, b + b1); calc(k, b + b2);
    cout << ans << endl;
}

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        ans = 0;
        double x1, y1, x2, y2, k, b;
        k = (y2 - y1) / (x2 - x1);
        b = -k * x1 + y1;
        cin >> x1 >> y1 >> x2 >> y2;
        addp(x1, y1, x2, y2, k, b);
        cout << ans << endl;
    }
    while(T--) {
        scanf("%d%d%d%d%d%d%d%d", &S, &X0, &Y0, &R, &X1, &Y1, &X2, &Y2);
        X1 -= X0; X2 -= X0; Y1 -= Y0; Y2 -= Y0;
        if(X0 == X1) {
            swap(X0, Y0); swap(X1, Y1);
        }
        solve();
    }
    return 0;
}
