#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int abs(int x) {
	return x < 0 ? -x : x;
}

struct Point {
	int x,y;
	Point(int xx,int yy) {
		x = xx; y = yy;
	}
	Point(){
	}
	bool operator == (const Point &xx) const {
		return (x == xx.x && y == xx.y);
	}
	bool operator < (const Point &xx) const {
		if(x == xx.x) return y < xx.y;
		return x < xx.x;
	}
};

Point operator - (Point a,Point b) {
	return Point(a.x-b.x,a.y-b.y);
}

struct Line {
	Point str,vec;
	bool operator < (const Line &x) const {
		if(vec == x.vec) return str < x.str;
		return vec < x.vec;
	}
	Line() {
	}
	Line(Point ss,Point vv) {
		str = ss; vec = vv;
	}
};

Line l[5];
Point p[9];
map<Point,int> table;

bool para(Line a,Line b) {
	if(a.vec == b.vec && !(a.str == b.str)) {
		return true;
	} else return false;
}

void swap(Point &a,Point &b) {
	Point tmp = a;a = b;b= tmp;
}

int main() {
	for(int i = 0;i < 4;i++) {
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int p1 = i * 2,p2 = i * 2 + 1;
		p[p1] = Point(x1,y1);
		p[p2] = Point(x2,y2);
		if(p[p1] < p[p2]) swap(p[p1],p[p2]);
		l[i] = Line(p[p2],p[p1] - p[p2]);
	}	
	
	sort(l,l + 4);
	bool ok = true;
	
	for(int i = 0;i < 4;i++) {
		ok &= !(l[i].vec.x * l[i].vec.y);
		ok &= !(l[i].vec == Point(0,0));
	}
	
	if(para(l[0],l[1]) && para(l[2],l[3]) && ok) {
		for(int i = 0;i < 8;i++) {
			table[p[i]]++;
		}
		bool flag = true;
		for(map<Point,int>::iterator iter = table.begin();
			iter != table.end();++iter) {
				flag &= (iter->second == 2);
			}
		if(flag) puts("YES");
		else puts("NO");
	} else {
		puts("NO");
	}
	return 0;
}
