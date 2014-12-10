#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>

#define cannot 0
#define can 1
#define teacher 2

using namespace std;

struct pos {
	int x,y,t;
};

bool eq(pos a,pos b) {
	return (a.x == b.x && a.y == b.y);
}

int n,m,map[102][102],time[102][102];
pos spos,epos,tpos;
int dx[] = {-1,1,0,0,-1,-1,1,1,0},dy[] = {0,0,-1,1,-1,1,-1,1,0};

int main() {
	while(~scanf("%d%d",&n,&m)) {
		memset(map,cannot,sizeof(map));
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				char tmp; scanf(" %c",&tmp);
				if(tmp == 'A') spos.x = i,spos.y = j;
				if(tmp == 'B') epos.x = i,epos.y = j;
				if(tmp == 'T') {
					for(int k = 0;k < 9;k++) {
						map[i + dx[k]][j + dy[k]] = teacher;
					}
				}
				if(tmp != '#' && map[i][j] != teacher) map[i][j] = can;
				time[i][j] = INT_MAX;
			}
		}
		queue<pos> q;
		spos.t = 0; epos.t = INT_MAX;
		q.push(spos);
		while(!q.empty()) {
			pos &now = q.front();
			for(int i = 0;i < 4;i++) {
				if(map[now.x + dx[i]][now.y + dy[i]] == can && now.t + 1 < time[now.x + dx[i]][now.y + dy[i]]) {
					time[now.x + dx[i]][now.y + dy[i]] = now.t + 1;
					pos newpos = now;
					newpos.x += dx[i]; newpos.y += dy[i]; newpos.t++;
					q.push(newpos);
				}
			}
			q.pop();
		}
		if(time[epos.x][epos.y] == INT_MAX) printf("-1\n");
		else printf("%d\n",time[epos.x][epos.y]);
	}
	return 0;
}