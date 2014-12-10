#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;
const int maxn = 1e3 + 10;
const double eps = 1e-9;

int a, b, n;
double sx, sy, ex, ey;
double dist[maxn][maxn];
double posx1[maxn], posx2[maxn], posy1[maxn], posy2[maxn];
bool vis[maxn];

bool equ(double a, double b) {
	return fabs(a - b) < eps;
}

struct Point {
	double x, y;
	Point (double x = 0, double y = 0):
		x(x), y(y) {}
	bool operator == (const Point &p) const {
		return equ(p.x, x) && equ(p.y, y);
	}
};

typedef Point Vector;

double sq(double x) {
	return x * x;
}

Point operator - (Point a, Point b) {
	return Point(a.x - b.x, a.y - b.y);
} 

double getdist(Vector v) {
	return sqrt(v.x * v.x + v.y * v.y);
}

double dot(Vector a, Vector b) {
	return a.x * b.x + a.y * b.y;
}

double Cross(Vector a, Vector b) {
	return a.x * b.y - a.y * b.x;
}

double getdist(Point p, Point a, Point b) {
	if(a == b) return getdist(p - a);
	Vector v1 = b - a, v2 = p - a, v3 = p - b;
	if(dot(v1, v2) < 0) return getdist(v2);
	else if(dot(v1, v3) > 0) return getdist(v3);
	else return fabs(Cross(v1, v2)) / getdist(v1);
}

double getdist(int i, int j) {
	//判断两条线段的距离
	double x1 = posx1[i], x2 = posx2[i], y1 = posy1[i], y2 = posy2[i];
	double x3 = posx1[j], x4 = posx2[j], y3 = posy1[j], y4 = posy2[j];
	Point p1(x1, y1), p2(x2, y2), p3(x3, y3), p4(x4, y4);
	double ret = min(getdist(p1, p3, p4), getdist(p2, p3, p4));
	ret = min(ret, min(getdist(p3, p1, p2), getdist(p4, p1, p2)));
	return ret;
}

struct Node {
	int id; double cost;
	Node(int id = 0, double cost = 0):
		id(id), cost(cost) {}
	bool operator < (const Node &x) const {
		return cost > x.cost;
	}
};

int main() {
	scanf("%d%d", &a, &b);
	scanf("%lf%lf%lf%lf", &sx, &sy, &ex, &ey);
	scanf("%d", &n);
	posx1[0] = posx2[0] = sx;
	posy1[0] = posy2[0] = sy;
	posx1[n + 1] = posx2[n + 1] = ex;
	posy1[n + 1] = posy2[n + 1] = ey;
	for(int i = 1; i <= n; i++) {
		scanf("%lf%lf%lf%lf", &posx1[i], &posy1[i], &posx2[i], &posy2[i]);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			dist[i][j] = getdist(i, j);
		}
	}
	//BFS
	double pse = getdist(Point(sx, sy) -  Point(ex, ey));
	double ans = pse <= a ? pse : 1e12;
	priority_queue<Node> q;
	for(int i = 1; i <= n; i++) {
		double ret = getdist(0, i);
		if(ret <= a) {
			q.push(Node(i, a + b));
		}
	}
	while(!q.empty()) {
		Node tt = q.top(); q.pop();
		int now = tt.id;
		double nowcost = tt.cost;
		//printf("%d %.3f\n", now, nowcost);
		if(getdist(now, n + 1) <= a) {
			ans = min(ans, nowcost + getdist(now, n + 1));
		}
		for(int i = 1; i <= n; i++) if(dist[now][i] <= a + eps && !vis[i]) {
			q.push(Node(i, nowcost + a + b));
			vis[i] = true;
		}
	}
	if(ans > 1e10) puts("-1");
	else printf("%.10f\n", ans);
	return 0;
}
