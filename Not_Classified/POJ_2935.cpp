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

//up 0 down 1 left 2 right 3
const int UP = 1,DOWN = 2,LEFT = 4,RIGHT = 8;
const int dx[4] = {-1,1,0,0},dy[4] = {0,0,-1,1};
const int N = 6;
const int M = 6;
int mp[8][8],sx,sy,ex,ey;
int pre[8][8];

void print_path(int x,int y) {
	int px = pre[x][y] / 10,py = pre[x][y] % 10;
	if(x == sx && y == sy) return;
	print_path(px,py);
	if(px == x) {
		if(py == y + 1) putchar('N');
		else putchar('S');
	} 
	else if(px == x + 1) putchar('W');
	else putchar('E');
}


int main() {
	while(scanf("%d%d",&sx,&sy),sx) {
		scanf("%d%d",&ex,&ey);
		memset(mp,-1,sizeof(mp));
		memset(pre,-1,sizeof(pre));
		for(int i = 1;i <= 6;i++)
			for(int j = 1;j <= 6;j++)
				mp[i][j] = 0;
		for(int i = 1;i <= 3;i++) {
			int bsx,bsy,bex,bey;
			scanf("%d%d%d%d",&bsx,&bsy,&bex,&bey);
			if(bsx == bex) {
				for(int j = bsy + 1;j <= bey;j++) {
					mp[bsx][j] |= DOWN;
					mp[bsx + 1][j] |= UP;
				}
			} else {
				for(int j = bsx + 1;j <= bex;j++) {
					mp[j][bsy] |= RIGHT;
					mp[j][bsy + 1] |= LEFT;
				}
			}
		}
		queue<int> qx,qy;
		qx.push(sx);
		qy.push(sy);
		while(!qx.empty()) {
			int x = qx.front(),y = qy.front();
			qx.pop();
			qy.pop();
			if(x == ex && y == ey) break;
			for(int i = 0;i < 4;i++) {
				int nx = x + dx[i],ny = y + dy[i];
				if(mp[nx][ny] != -1 && pre[nx][ny] == -1 && 
						!(mp[x][y] & (1 << i))) {
					qx.push(nx);
					qy.push(ny);
					pre[nx][ny] = x * 10 + y;
				}
			}
		}
		print_path(ex,ey);
		putchar('\n');
	}
	return 0;
}


