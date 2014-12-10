#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const double eps = 1e-9;

int getx2p(double a, double b, double c, double &x1, double &x2) {
    double delta = b * b - 4 * a * c;
    if(delta < 0) return 0;
    x1 = -b + sqrt(delta); x2 = -b - sqrt(delta);
    x1 /= 2 * a; x2 /= 2 * a;
    if(delta < eps) return 1;
    else return 2;
}

bool inrange(double n, double L, double R) {
    L -= eps; R += eps;
    return (n >= L && n <= R);
}

double f(double x, double a, double b, double c, double d) {
    return a * x * x * x + b * x * x + c * x + d;
}

int main() {
    double a, b, c, d, L, R;
    while(scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &L, &R) != EOF) {
        double p0, p1;
        int ret = getx2p(3 * a, 2 * b, c, p0, p1);
        double ans = -1e30;
		if(a == 0 && b == 0) {
            ans = max(abs(f(L, a, b, c, d)), abs(f(R, a, b, c, d)));
		}
		else if(a == 0) {
            ans = max(abs(f(L, a, b, c, d)), abs(f(R, a, b, c, d)));
			double mid = -c / (2 * b);
			if(inrange(mid, L, R)) {
				ans = max(ans, f(mid, a, b, c, d));
			}
		}
		else if(ret == 0 || (!inrange(p0, L, R) && !inrange(p1, L, R))) {
            ans = max(abs(f(L, a, b, c, d)), abs(f(R, a, b, c, d)));
        }
        else {
            ans = max(abs(f(L, a, b, c, d)), abs(f(R, a, b, c, d)));
            if(inrange(p0, L , R)) ans = max(ans, abs(f(p0, a, b, c, d)));
            if(inrange(p1, L , R)) ans = max(ans, abs(f(p1, a, b, c, d)));
        }
        printf("%.2f\n", ans);
    }
    return 0;
}
