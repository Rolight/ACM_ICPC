#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Point {
	int x,y,h;
	bool operator< (const Point &tt) const {
		return h < tt.h;
	}
};

const int maxn = 105;
Point p[maxn * maxn];
int dx[4] = {-1,1,0,0},dy[4] = {0,0,-1,1};
int h[maxn][maxn],v[maxn][maxn];

int main() {
	int n,m,k;
	while(scanf("%d%d",&n,&k), n != -1) {
		if(n * k == 0) {
			printf("0\n"); continue;
		}
		memset(h,-1,sizeof(h));
		m = 0;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++) {
				scanf("%d",&h[i][j]);
				p[m].x = i; p[m].y = j; p[m].h = h[i][j];
				v[i][j] = -1000000000;
				m++;
			}
		}
		v[1][1] = p[0].h;
		sort(p,p + m);
		int ans = v[1][1];
		for(int i = 0;i < m;i++) {
			if(p[i].h <= v[1][1]) continue;
			int x = p[i].x,y = p[i].y,maxv = -1000000000;
			for(int j = 0;j < 4;j++) {
				for(int kk = 1;kk <= k;kk++) {
					int nx = x + kk * dx[j],ny = y + kk * dy[j];
					if(!(nx >= 1 && nx <= n && ny >= 1 && ny <= n)) continue;
					if(h[nx][ny] < p[i].h && v[nx][ny] >= 0) {
						maxv = max(maxv,v[nx][ny]);
					}
				}
			}
			v[x][y] = p[i].h + maxv;
			ans = max(ans,v[x][y]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
