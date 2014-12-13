#include <cstdio>
#include <cmath>

using namespace std;

const double g = 9.8;
const double pi = acos(-1);

inline double sq(double x) {
    return x * x;
}

inline double f(double v, double h, double ag) {
    double sinv = sin(ag), cosv = cos(ag);
    return (sqrt(v * v * sinv * sinv / g / g + 2 * h / g) + v * sinv / g) * v * cosv;
}

inline double gao(double v, double h) {
    double l = 0, r = pi / 2;
    while(fabs(r - l) > 1e-9) {
        double ll = (2 * l + r) / 3,
                rr = (l + 2 * r) / 3;
        double ans1 = f(v, h, ll),
            ans2 = f(v, h, rr);
        if(ans1 <= ans2) l = ll;
        else r = rr;
    }
    return f(v, h, l);
}

int main() {
    int T;
    double v0, h;
    scanf("%d", &T);
    while(T--) {
        scanf("%lf%lf", &h, &v0);
        printf("%.2f\n", gao(v0, h));
    }
    return 0;
}
