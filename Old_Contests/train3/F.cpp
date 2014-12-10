#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

int rmax,cmax;

struct point {
	int x,y;
	point(int x = 0,int y = 0):x(x),y(y) {}
	bool operator < (const point &xx) const {
		if(x == xx.x) return y < xx.y;
		else return x < xx.x;
	}
};

const int maxn = 1005;
point p[maxn];
set<point> table;

int main() {
	int n;
	while(scanf("%d",&n),n) {
		rmax = cmax = 0;
		table.clear();
		for(int i = 0;i < n;i++) {
			scanf("%d%d",&p[i].y,&p[i].x);
			rmax = max(rmax,p[i].x);
			cmax = max(cmax,p[i].y);
			table.insert(p[i]);
		}
		sort(p,p + n);
		int ans = 0;
		for(int i = 0;i < n;i++) {
			for(int j = i + 1;j < n && p[j].x == p[i].x;j++) {
				int gx1 = p[j].y - p[i].y + p[i].x;
				int gy1 = p[i].y;
				int gx2 = gx1,gy2 = p[j].y;
				if(table.count(point(gx1,gy1)) && table.count(point(gx2,gy2))) {
					ans++;
				}
			}
		}
		for(int i = 0;i < n;i++) {
			for(int j = i + 1;j < n;j++) {
				if(p[j].x > p[i].x && p[j].y < p[i].y) {
					int dx = p[j].x - p[i].x;
					int dy = p[i].y - p[j].y;
					int gx1 = p[i].x + dy,gy1 = p[i].y + dx;
					int gx2 = gx1 + dx,gy2 = gy1 - dy;
					if(table.count(point(gx1,gy1)) && table.count(point(gx2,gy2))) {
						ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
