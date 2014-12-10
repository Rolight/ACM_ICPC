#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int maxn = 15;
const int dx[] = { 0, 0, 1, -1, 0, 0 };
const int dy[] = { 1, -1, 0, 0, 0, 0 };
const int dz[] = { 0, 0, 0, 0, 1, -1 };
char mp[maxn][maxn][maxn];
int dist[maxn][maxn][maxn];
char start[maxn];
int sx, sy, sz, ex, ey, ez, n;

void bfs() {
	memset(dist, -1, sizeof(dist));
	dist[sx][sy][sz] = 0;
	queue<int> qx, qy, qz;
	qx.push(sx); qy.push(sy); qz.push(sz);
	while (!qx.empty()) {
		int x = qx.front(), y = qy.front(), z = qz.front();
		qx.pop(); qy.pop(); qz.pop();
		if (x == ex && y == ey && z == ez) return;
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
			if (mp[nx][ny][nz] == 'O' && dist[nx][ny][nz] == -1) {
				dist[nx][ny][nz] = dist[x][y][z] + 1;
				qx.push(nx); qy.push(ny); qz.push(nz);
			}
		}
	}
}

int main() {
	while (scanf("%s%d", start, &n) != EOF) {
		memset(mp, 'X', sizeof(mp));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					scanf(" %c", &mp[j][k][i]);
				}
			}
		}
		scanf("%d%d%d%d%d%d", &sx, &sy, &sz, &ex, &ey, &ez);
		scanf("%s", start);
		sx++; sy++; sz++; ex++; ey++; ez++;
		bfs();
		if (dist[ex][ey][ez] == -1) puts("NO ROUTE");
		else printf("%d %d\n", n, dist[ex][ey][ez]);
	}
	return 0;
}
