#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string.h>
using namespace std;
#define LL double
#define eps 1e-11

int dcmp(double a, double b)
{
	if (a < b - eps) return -1;
	else if (a > b + eps) return 1;
	else return 0;
}

struct Point
{
	LL x, y;
	Point(LL x = 0, LL y = 0)
		:x(x), y(y) { }
	bool operator<(const Point&p) const
	{
		return dcmp(x,p.x)<0 || (dcmp(x,p.x)==0 && y < p.y);
	}
	bool operator==(const Point&p) const
	{
		return dcmp(x,p.x)==0 && dcmp(y,p.y)==0;
	}
};
typedef Point Vector;

Vector operator+(const Point&a, const Point&b) { return Vector(a.x + b.x, a.y + b.y); }
Vector operator-(const Point&a, const Point&b) { return Vector(a.x - b.x, a.y - b.y); }

LL Dot(const Vector&a, const Vector&b)
{
	return a.x*b.x + a.y*b.y;
}

LL Cross(const Vector&a, const Vector&b)
{
	return a.x*b.y - a.y*b.x;
}

int Convexhull(Point *p, int n, Point*ch)
{
	sort(p, p + n);
	n = unique(p, p + n) - p;
	int m = 0;
	for (int i = 0; i<n; ++i) {
		while (m>1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) --m;
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; --i) {
		while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) --m;
		ch[m++] = p[i];
	}
	if (n > 1) --m;
	return m;
}

double Distance(const Point&a, const Point&b)
{
	return sqrt((double)Dot(a - b, a - b));
}

pair<double, double> RotateCalipers(Point * p, int n)
{
	p[n] = p[0];
	int t = 1, l = 1, r = 1;
	double ansC = 1e15, ansA = 1e15;
	for (int b = 0; b<n; ++b) {
		while (Cross(p[b + 1] - p[b], p[t + 1] - p[t])> eps) t = (t + 1) % n;
		while (Dot(p[b + 1] - p[b], p[r + 1] - p[r]) > eps) r = (r + 1) % n;
		if (b == 0) l = (r + 1) % n;
		while (Dot(p[b + 1] - p[b], p[l + 1] - p[l]) < -eps) l = (l + 1) % n;
		double d = Distance(p[b + 1], p[b]);
		double h = (double)Cross(p[b + 1] - p[b], p[t] - p[b]) / d;
		double w = (double)(Dot(p[r] - p[b], p[b + 1] - p[b]) - Dot(p[b + 1] - p[b], p[l] - p[b])) / d;
		ansC = min(ansC, 2 * (h + w));
		ansA = min(ansA, h*w);
	}
	return make_pair(ansA, ansC);
}

const int maxn = 100000 + 5;
int n;
Point pt[maxn];
Point hull[maxn];

void input()
{
	for (int i = 0; i < n; ++i) scanf("%lf%lf", &pt[i].x, &pt[i].y);
}

void solve()
{
	int m = Convexhull(pt, n, hull);
	pair<double, double> ans = RotateCalipers(hull, m);
	printf("%.0lf\n", ans.first);
}

int main()
{
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase) {
		scanf("%d", &n); n *= 4;
		input();
		printf("Case #%d:\n", kase);
		solve();
	}
	return 0;
}


