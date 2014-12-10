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

struct pp {
	int hx,hy,cx,cy,dis;
	bool operator < (const pp &x) const {
		if(dis != x.dis) return dis < x.dis;
		if(hx != x.hx) return hx < x.hx;
		if(hy != x.hy) return hy < x.hy;
		if(cx != x.cx) return cx < x.cx;
		else return cy < x.cy;
	}
};

struct point {
	int x,y;
	point(int x = 0,int y = 0):x(x),y(y){}
};

int n,m;
vector<point> h,c;
vector<pp> allpp;

inline int abs(int x) {
	if(x < 0) return -x;
	else return x;
}

int getdis(int x1,int y1,int x2,int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

void get(point h,point c) {
	allpp.push_back((pp){h.x,h.y,c.x,c.y,getdis(h.x,h.y,c.x,c.y)});
	//printf("%d %d %d %d %d\n",h.x,h.y,c.x,c.y,getdis(h.x,h.y,c.x,c.y));
}

int main() {
	char tmp;
	while(scanf("%d%d",&n,&m),n || m) {
		h.clear(); c.clear(); allpp.clear();
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < m;j++) {
				scanf(" %c",&tmp);
				if(tmp == 'C') c.push_back(point(i,j));
				if(tmp == 'H') h.push_back(point(i,j));
			}
		}
		for(int i = 0;i < c.size();i++) {
			for(int j = 0;j < h.size();j++) {
				get(h[j],c[i]);
			}
		}
		sort(allpp.begin(),allpp.end());
		pp ans = *allpp.begin();
		printf("%d %d %d %d\n",ans.hx,ans.hy,ans.cx,ans.cy);
	}
	return 0;
}


