#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
	double x, y;
	Point(double x, double y) :x(x), y(y) {}
	Point() {};
};

Point operator - (Point a, Point b) {
	return Point(a.x - b.x, a.y - b.y);
}

double dist(Point a) {
	return sqrt(a.x*a.x + a.y*a.y);
}

double ag(Point a, Point b) {
	return fabs(a.x*b.x + a.y*b.y);
}

const double eps = 1e-7;
Point p[10];
int id[10];

bool equ(double a, double b) {
	if (fabs(a - b) < eps) return true;
	return false;
}

bool isSquare(Point a1, Point a2, Point a3, Point a4) {
	Point p1 = a1 - a2, p2 = a2 - a3, p3 = a3 - a4, p4 = a4 - a1;
	double app = ag(p1, p2) + ag(p2, p3) + ag(p3, p4) + ag(p4, p1);
	if (fabs(app) > eps) return false;
	if (equ(dist(p1), dist(p2)) && equ(dist(p1), dist(p3)) && equ(dist(p1), dist(p4)))
		return true;
	return false;
}

bool isR(Point a1, Point a2, Point a3, Point a4) {
	Point p1 = a1 - a2, p2 = a2 - a3, p3 = a3 - a4, p4 = a4 - a1;
	double app = ag(p1, p2) + ag(p2, p3) + ag(p3, p4) + ag(p4, p1);
	if (fabs(app) > eps) return false;
	return true;
}

int main() {
	for (int i = 1; i <= 8; i++) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
		id[i] = i;
	}
	do {
		bool r1 = isSquare(p[id[1]], p[id[2]], p[id[3]], p[id[4]]);
		bool r2 = isR(p[id[5]], p[id[6]], p[id[7]], p[id[8]]);
		if (r1 && r2) {
			puts("YES");
			printf("%d %d %d %d\n", id[1], id[2], id[3], id[4]);
			printf("%d %d %d %d\n", id[5], id[6], id[7], id[8]);
			return 0;
		}
	} while (next_permutation(id + 1, id + 1 + 8));
	puts("NO");
	return 0;
}
