#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>

#define getp(nx,y) have.insert(Point(nx,y)); count++; continue;

using namespace std;

const int maxn = 1004;

struct Point {
	int x,y;
	bool operator<(const Point &r) const {
		if(x == r.x) return y < r.y;
		return x < r.x;
	}
	
	Point(int a,int b): x(a),y(b) {
	}
};

int n,m,qx[maxn * maxn],qy[maxn * maxn];
int dx[4] = {0,0,1,-1},dy[4] = {1,-1,0,0};
char maze[maxn][maxn],vis[maxn][maxn];

bool solve(int x,int y) {
	
	memset(vis,0,sizeof(vis));
	int front = 0,rear = 1,count = 0;
	set<Point> out,have;
	qx[0] = x; qy[0] = y; vis[x][y] = 1;
	while(front < rear) {
		x = qx[front]; y = qy[front];
		if(x == 1 || x == n || y == 1 || y == m) {
			out.insert(Point(x,y));
		}
		vis[x][y] = 1;
		for(int i = 0;i < 4;i++) {
			int nx = x + dx[i],ny = y + dy[i];
			if(maze[nx][ny] && !vis[nx][ny]) {
				qx[rear] = nx; qy[rear] = ny;
				rear++;
			}
		}
		front++;
	}
	for(set<Point>::iterator pos = out.begin();pos != out.end() && !count;++pos) {
		x = pos->x; y = pos->y;
		if(have.count(Point(x,y))) continue;
		int nx,ny;
		if(x == 1) nx = n;
		if(x == n) nx = 1;
		if(y == 1) ny = m;
		if(y == m) ny = 1;
		if(x == 1 || x == n) {
			if(out.count(Point(nx,y))) {
				getp(nx,y);
			} else if((y == 1 || y == m) && out.count(Point(nx,ny))) {
				getp(nx,ny);
			}
		}
		if(y == 1 || y == m) {
			if(out.count(Point(x,ny))) {
				getp(x,ny);
			} else if((x == 1 || x == n) && out.count(Point(nx,ny))) {
				getp(nx,ny);
			}
		}
	}
	return count;
}

int main() {
	int T; scanf("%d",&T);
	while(T--) {
		int sx,sy;
		scanf("%d%d",&n,&m);
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				scanf(" %c",&maze[i][j]);
				if(maze[i][j] == 'S') {
					sx = i; sy = j;
				}
				if(maze[i][j] == '#') maze[i][j] = 0;
				else maze[i][j] = 1;
			}
		}
		if(solve(sx,sy)) puts("YES");
		else puts("NO");
	}
	return 0;
}
