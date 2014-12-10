#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const double eps = 1e-10;
double R, r;

double getVal(double Y, double &a, double &c) {
	c = sqrt(R * R - (R - Y) * (R - Y)) * 2;
	a = sqrt((2 * R - Y) * (2 * R - Y) + c * c * 0.25);
	double S = 0.5 * c * (2 * R - Y);
	double C = a + a + c;
	return 2 * S / C;
}

double xiaojj(double a, double c) {
	double h = a * a - c * c * 0.25;
	h = sqrt(h);
	double S = h * c * 0.5;
	double C = a + a + c;
	printf("ÄÚÇÐÔ²: %.8f\nÍâ½ÓÔ²: %.8f\n", 2 * S / C, a * a * c / (4 * S));
	return 1;
}

int main() {
	while (scanf("%lf%lf", &r, &R) != EOF) {
		double lb = R / 2, rb = 2 * R;
		double la, lc;
		double ans = -10;
		while (fabs(rb - lb) > eps) {
			double mid = (lb + rb) / 2;
			double ret = getVal(mid, la, lc);
			if (fabs(r - ret) < eps) ans = mid;
			if (ret >= r) lb = mid + eps;
			else rb = mid - eps;
		}
		if (ans < 0) printf("NO Solution!\n");
		else printf("%.9f %.9f %.9f\n", la, la, lc);
	}
}