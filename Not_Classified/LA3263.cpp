#include <cstdio>
#include <algorithm>
#include <cmath>

#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"

using namespace std;

typedef long long LL;
const int maxn = 400;
const double eps = 1e-10;

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
Point v[maxn * maxn];	//顶点
Point p[maxn];

Vector operator - (Point a,Point b) {
	return Vector(a.x - b.x,a.y - b.y);
}

Vector operator * (Vector a,double p) {
	return Vector(a.x * p,a.y * p);
}

Vector operator + (Vector a,Vector b) {
	return Vector(a.x + b.x,a.y + b.y);
}

double dot(Vector a,Vector b) {
	return a.x * b.x + a.y * b.y;
}

int dcmp(double x) {
	if(fabs(x) < eps) return 0;
	return x < 0 ? -1 : 1;
}

bool operator < (Point a,Point b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

double cross(Vector a,Vector b) {
	return a.x * b.y - a.y * b.x;
}

bool have_intersection(Point a1,Point a2,Point b1,Point b2) {
	double c1 = cross(a2 - a1,b1 - a1),c2 = cross(a2 - a1,b2 - a1);
	double c3 = cross(b2 - b1,a1 - b1),c4 = cross(b2 - b1,a2 - b1);
	bool ret = (dcmp(c1) * dcmp(c2) < 0) && (dcmp(c3) * dcmp(c4) < 0);
	return ret;
}

bool on_segment(Point p,Point a,Point b) {
	return dcmp(cross(p - a,p - b)) == 0 && dcmp(dot(a - p,b - p)) < 0;
}

Point get_intersection(Point a1,Point a2,Point b1,Point b2) {
	Vector v = a2 - a1,w = b2 - b1,u = a1 - b1;
	double t = cross(w,u) / cross(v,w);
	return a1 + v * t;
}

bool operator == (Point a,Point b) {
	return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

int main() {
	int n,kase = 1;
	while(scanf("%d",&n),n) {
		for(int i = 0;i < n;i++) {
			scanf("%lf%lf",&v[i].x,&v[i].y);
			p[i] = v[i];
		}
		int cnt_v = n - 1,cnt_f = 0,cnt_e = n - 1;	
		n--;		
		//判断一下给定的线段是否有交点
		for(int i = 0;i < n;i++) {
			for(int j = i + 1;j < n;j++) {
				if(have_intersection(p[i],p[i + 1],p[j],p[j + 1])) {
					//找到交点了就添加到点集里面
					v[cnt_v++] = get_intersection(p[i],p[i + 1],p[j],p[j + 1]);
				}
			}
		}
		//特判三点共线的时候的状态
		sort(v,v + cnt_v);
		cnt_v = unique(v,v + cnt_v) - v;
		//处理因为线段交点而新生成的线段
		for(int i = 0;i < cnt_v;i++) {
			for(int j = 0;j < n;j++) {
				if(on_segment(v[i],p[j],p[j + 1])) {
					cnt_e++;
				}
			}
		}
		printf("Case %d: There are %d pieces.\n",kase++,2 + cnt_e - cnt_v);
	}
	return 0;
}


