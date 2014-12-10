#include <cstdio>
#include <cstring>

using namespace std;

struct Point {
	int x,y;
	Point(int xx,int yy) {
		x = xx,y = yy;
	}
	Point() {}
};

typedef Point Vector;

Vector operator- (Vector a,Vector b) {
	return Point(a.x - b.x,a.y - b.y);
}

int dot(Vector a,Vector b) {
	return a.x * b.x + a.y * b.y;
}

bool zero(Vector a) {
	return (a.x == 0 && a.y == 0);
}

int px[4],py[4];
int dx[4] = {0,0,1,-1},dy[4] = {1,-1,0,0};

bool ok(Point a,Point b,Point c) {
	Vector v1 = a - b,v2 = b - c,v3 = c - a;
	if(!zero(v1) && !zero(v2) && !dot(v1,v2)) return true;
	if(!zero(v3) && !zero(v2) && !dot(v3,v2)) return true;
	if(!zero(v1) && !zero(v3) && !dot(v1,v3)) return true;
	return false;
}

Point ori[3];

int main() {
	for(int i = 0;i < 3;i++) {
		int xx,yy; scanf("%d%d",&xx,&yy);
		ori[i] = Point(xx,yy);
	}
	if(ok(ori[0],ori[1],ori[2])) puts("RIGHT");
	else {
		for(int i = 0;i < 3;i++) {
			for(int d = 0;d < 4;d++) {
				Point np(ori[i].x + dx[d],ori[i].y + dy[d]);
				if(ok(np,ori[(i + 1) % 3],ori[(i + 2) % 3])) {
					puts("ALMOST"); return 0;
				}
			}
		}
		puts("NEITHER");
	}
	return 0;
}
