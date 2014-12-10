#include <cstdio>
#include <cstring>
#include <queue>
#include <set>

#define WALL -1
#define EMPTY 0

using namespace std;

const int maxn = 17;

int time[maxn][maxn];
int dx[] = {-1,1,0,0},dy[] = {0,0,-1,1};
int sx,sy,ex,ey,n,m,len;

struct board {
	int d[maxn][maxn],x,y;
	board() {
		memset(d,WALL,sizeof(d));
	}
	bool operator < (const board &_n) const {
		if(_n.x != x) return x < _n.x;
		if(_n.y != y) return y < _n.y;
		for(int i = 1;i <= n;i++) {
			for(int j = 1;i <= m;j++) {
				if(d[i][j] != _n.d[i][j]) return d[i][j] < _n.d[i][j];
			}
		}
		return false;
	}
};

board str;

void print_b(board &s) {
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			printf("%3d",s.d[i][j]);
		}
		putchar('\n');
	}
}

void next(board &now,int x,int y,int nx,int ny,int i) {
	int d,tx,ty;
	for(d = 0;d < 4;d++) {
		tx = x + dx[d],ty = y + dy[d];
		if(now.d[tx][ty] == i + 1) break;
	}
	if(d != 4) {
		next(now,tx,ty,x,y,i + 1);
	}
	now.d[nx][ny] = i;
}

int bfs() {
	queue<board> q; set<board> table;
	q.push(str); table.insert(str);
	memset(time,-1,sizeof(time));
	time[str.x][str.y] = 0;
	while(!q.empty()) {
		board now = q.front();
		q.pop();
		int x = now.x,y = now.y;
		if(x == ex && y == ey) return time[ex][ey];
		for(int i = 0;i < 4;i++) {
			int nx = x + dx[i],ny = y + dy[i];
			if((now.d[nx][ny] == EMPTY || now.d[nx][ny] == len)) {
				board tmp = now;
				next(tmp,tmp.x,tmp.y,nx,ny,1);
				tmp.x = nx; tmp.y = ny;
				if(!table.count(tmp)) {
					q.push(tmp); table.insert(tmp); time[nx][ny] = time[x][y] + 1;
				}
			}
		}
	}
	return time[ex][ey];
}

int main() {
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			char tmp; scanf(" %c",&tmp);
			int &val = str.d[i][j];
			if(tmp == '.') val = EMPTY;
			else if(tmp == '#') val = WALL;
			else if(tmp == '@') {
				val = EMPTY; ex = i; ey = j;
			} else if(tmp >= '1' && tmp <= '9') {
				val = tmp - '0';
				if(tmp == '1') {
					sx = i; sy = j;
				}
				if(val > len) len = val;
			}
		}
	}
	str.x = sx; str.y = sy;
	printf("%d\n",bfs());
	return 0;
}
