#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue> 

using namespace std;

const int maxn = 1005;

struct Point {
	int x,y;
};

int n,m;
bool vis[maxn][maxn],maze[maxn][maxn];
bool vis1[maxn][maxn];
int dx[4] = {0,0,1,-1},dy[4] = {1,-1,0,0};
int szc,sx,sy;

bool canre(int x,int y,int id,int tar) {
//	printf("judging %d %d\n",x,y);
	queue<Point> q;
	q.push((Point){x,y});
	memset(vis1,0,sizeof(vis1));
	while(q.size()) {
		Point now = q.front();
		x = now.x; y = now.y;
		vis1[x][y] = 1;
		if(id == 0 && tar == x || id == 1 && tar == y) return true; 
		for(int i = 0;i < 4;i++) {
			int nx = x + dx[i],ny = y + dy[i];
			if(maze[nx][ny] && !vis1[nx][ny]) {
				q.push((Point){nx,ny});
			}
		}
		q.pop();
	}
	return false;
}

void bfs0(int x,int y) {
//	printf("expand %d %d\n",x,y);
	int count = 0;
	queue<Point> q;
	q.push((Point){x,y});
	while(q.size()) {
		Point now = q.front();
		x = now.x; y = now.y;
		vis[x][y] = 1;
		if(x == sx && y == sy) return;
		if(x == 1 || x == n || y == 1 || y == m) {
			int nx,ny;
			if(x == 1) nx = n; else nx = 1;
			if(y == 1) ny = m; else ny = 1;
			if(x == 1 || x == n) {
				if(maze[nx][y] && !vis[nx][y]) q.push((Point){nx,y});
				if(y == 1 || y == m && maze[nx][ny] && !vis[nx][ny]) q.push((Point){nx,ny});
			}
			if(y == 1 || y == n && !vis[x][ny] && maze[x][ny]) q.push((Point){x,ny});
		}
		for(int i = 0;i < 4;i++) {
			int nx = x + dx[i],ny = y + dy[i];
			if(maze[nx][ny] && !vis[nx][ny]) {
				q.push((Point){nx,ny});
			}
		}
		q.pop();
	}
}

bool solve(int x,int y) {
	memset(vis,0,sizeof(vis));
	szc = 0;
	//up
	for(int i = 1;i <= m;i++) if(maze[1][i] && !vis[1][i]) {
		bool ret = canre(1,i,0,n);
		if(ret) bfs0(1,i);
	}
	//down
	for(int i = 1;i <= m;i++) if(maze[n][i] && !vis[n][i]) {
		bool ret = canre(n,i,0,1);
		if(ret) bfs0(n,i);
	}
	//left
	for(int i = 1;i <= n;i++) if(maze[i][1] && !vis[i][1]) {
		bool ret = canre(i,1,1,m);
		if(ret) bfs0(i,1);
	}
	//right
	for(int i = 1;i <= n;i++) if(maze[i][m] && !vis[i][m]) {
		bool ret = canre(i,m,1,1);
		if(ret) bfs0(i,m);
	}
	return vis[x][y];
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
