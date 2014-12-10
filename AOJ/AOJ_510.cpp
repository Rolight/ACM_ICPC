#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>

#define swap(t,a,b) (t=a,a=b,b=t)
#define maxh 200

using namespace std;

int b[maxh][maxh],dx[8] = {-2,-2,-1,-1,1,1,2,2},dy[8] = {-1,1,-2,2,-2,2,-1,1};

int bfs(int sx,int sy,int ex,int ey) {
	queue<int> qx,qy;
	qx.push(sx); qy.push(sy);
	memset(b,0,sizeof(b));
	b[sx][sy] = 1;
	while(!qx.empty()) {
		int nowx = qx.front(),nowy = qy.front();
		if(nowx == ex && nowy == ey) return b[nowx][nowy];
		for(int i = 0;i < 8;i++) {
			int newx = nowx + dx[i],newy = nowy + dy[i];
			if(b[newx][newy] == 0 && newx > 0 && newx < maxh && newy > 0 && newy < maxh) {
				b[newx][newy] = b[nowx][nowy] + 1;
				qx.push(newx); qy.push(newy);
			}
		}
		qx.pop(); qy.pop();
	}
}

int main() {
	int sx,sy,ex,ey,t;
	while(~scanf("%d%d%d%d",&sx,&sy,&ex,&ey)) {
		int ans = 0;
		//printf("%d\n",bfs(sx,sy,ex,ey) - 1);
		if(ex < sx) swap(t,ex,sx);
		if(ey < sy) swap(t,ey,sy);
		ex = ex - sx + 10; ey = ey - sy + 10;
		sx = sy = 10;
		while(ey + ex - sy - sx >= 50) {
			if(ex < sx) swap(t,ex,sx);
			if(ey < sy) swap(t,ey,sy);
			ex = ex - sx + 10; ey = ey - sy + 10;
			sx = sy = 10;
			if(ey - sy > ex - sx) {
				ey -= 2,ex -= 1;
			}
			else ex -= 2,ey -=1;
			ans++;
		}
		printf("%d\n",ans + bfs(sx,sy,ex,ey) - 1);
	}
	return 0;
}
