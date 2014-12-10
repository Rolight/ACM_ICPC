#include <cstdio>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <cctype>
#include <ctime>
#include <set>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <string>
#include <list>

#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"

using namespace std;

typedef long long LL;
const int INF = INT_MAX / 2;

void setfile() {
	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}

struct Point {
	double x,y;
	Point(double x = 0,double y = 0):x(x),y(y) {
	}
};

typedef Point Vector;

Vector operator - (Point a,Point b) {
	return Vector(a.x - b.x,a.y - b.y);
}

double Cross(Vector a,Vector b) {
	return a.x * b.y - a.y * b.x;
}

const double eps = 1e-10;

int dcmp(double x) {
	if(fabs(x) < eps) return 0;
	return x < 0 ? -1 : 1;
}

bool Intersecion(Point a,Point b,Point sa,Point sb) {
	double c1 = Cross(sb - sa,a - sa),c2 = Cross(sb - sa,b - sa);
	return dcmp(c1) * dcmp(c2) < 0;
}

int main() {
	int t,n;
	scanf("%d",&t);
	while(t--) {
		int ans = 0;
		scanf("%d",&n);
		Point s,t;
		scanf("%lf%lf%lf%lf",&s.x,&s.y,&t.x,&t.y);
		for(int i = 1;i <= n;i++) {
			Point a,b;
			scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
			if(Intersecion(s,t,a,b)) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}


