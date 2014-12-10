#include <cstdio>
#include <cstring>
#include <climits>
#include <queue>

#define wall -1
#define door 1

using namespace std;

const int maxn = 205;
int maze[maxn * 2][maxn * 2],maxx,maxy;
int dx[4] = {-2,2,0,0},dy[4] = {0,0,-2,2},ept;

void setval(int x,int y,int d,int len,int val) {
	x *= 2; y *= 2;	//将坐标扩大两倍
	for(int i = 1;i <= len;i++) {
		if(d) {
			maze[x][y + 1] = val; y += 2; 
			if(y > maxy) maxy = y;
		} else {
			maze[x + 1][y] = val; x += 2;
			if(x > maxx) maxx = x;
		}
	} 
}

int main() {
	int cwall,cdoor,tx,ty,sx,sy,len,dir;
	double ex,ey;
	while(scanf("%d%d",&cwall,&cdoor)) {
		if(cwall == -1 && cdoor == -1) break;
		memset(maze,120,sizeof(maze));
		ept = maze[0][0];
		maxx = maxy = 0;
		for(int i = 0;i < cwall;i++) {
			scanf("%d%d%d%d",&sx,&sy,&dir,&len);
			setval(sx,sy,dir,len,wall);
		}
		for(int i = 0;i < cdoor;i++) {
			scanf("%d%d%d",&sx,&sy,&dir);
			setval(sx,sy,dir,1,door);
		}
		maxx += 2; maxy += 2;
		scanf("%lf%lf",&ex,&ey);
		if(ex < 0 || ex > 199 || ey < 0 || ey > 199 || (cdoor == 0 && cwall == 0)) {
			printf("0\n"); continue;
		}
		tx = (int)ex * 2 + 1;
		ty = (int)ey * 2 + 1;
		queue<int> qx,qy;
		qx.push(tx); qy.push(ty); maze[tx][ty] = 0;
		while(qx.size()) {
			int nowx = qx.front(),nowy = qy.front();
			for(int i = 0;i < 4;i++) {
				int newx = nowx + dx[i],newy = nowy + dy[i];
				int mid = maze[nowx + dx[i] / 2][nowy + dy[i] / 2];
				if(mid == wall) continue;
				if(mid == ept) mid = 0;
				if(newx > 0 && newx < maxx && newy > 0 && newy < maxy && 
					(maze[nowx][nowy] + mid < maze[newx][newy])) {
					qx.push(newx); qy.push(newy); maze[newx][newy] = maze[nowx][nowy] + mid;
				}
			}
			qx.pop(); qy.pop();
		}
		int ans = maze[1][1];
		if(ans == ept) printf("-1\n");
		else printf("%d\n",ans);
	}	
	return 0;
}
