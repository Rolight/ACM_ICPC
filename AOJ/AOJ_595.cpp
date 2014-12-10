#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>

using namespace std;

const int maxn = 1004;
int m,n,sx,sy;
int maze[maxn][maxn];
char sma[maxn][maxn];
int dx[4] = {-1,1,0,0},dy[4] = {0,0,1,-1};
bool vis[maxn][maxn];
int gx[maxn][maxn],gy[maxn][maxn];


int r(int t, int w) {
	return ((t % w) + w) % w;
}


bool solve(int x,int y) {
    memset(vis,0,sizeof(vis));
    queue<int> qx,qy;
    qx.push(x); qy.push(y);
	gx[x][y] = x; gy[x][y] = y;
	vis[x][y] = 1;
    while(!qx.empty()) {
        x = qx.front(); y = qy.front();
        for(int i = 0;i < 4;i++) {
            int nx = x + dx[i],ny = y + dy[i];
			int nrx = r(nx, n), nry = r(ny, m);
			if(maze[nrx][nry]   && !vis[nrx][nry]) {
                qx.push(nx); qy.push(ny);
				vis[nrx][nry] = 1;
				gx[nrx][nry] = nx; gy[nrx][nry] = ny;
			}
			else if (vis[nrx][nry] && (nx != gx[nrx][nry] || ny != gy[nrx][nry])) return true;
        }
        qx.pop(); qy.pop();
    }
	return false;
}

int main() {
	int T; scanf("%d",&T);
	char tmp;
	while(T--) {
		scanf("%d%d",&n,&m);
		for(int i = 0;i < n;i++) {
			scanf("%s", sma[i]);
			for(int j = 0;j < m;j++) {
				if(sma[i][j] == 'S') {
					sx = i; sy = j;
				}
				if (sma[i][j] == '#') maze[i][j] = 0;
				else maze[i][j] = 1;
				
			}
		}
		if (n * m == 0) {
			puts("error"); continue;
		}
		if(solve(sx,sy)) puts("YES");
		else puts("NO");
	}
	return 0;
}
