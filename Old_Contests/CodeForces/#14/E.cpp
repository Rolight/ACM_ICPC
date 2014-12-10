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

int n,t;
int path[50];
int f[21][5][11][11][5];

int dfs(int x,int y,int up,int down,int prev) {
	//path[x] = y;
	int ret = 0;
	if(x == n) {
		if(up == t && down == t - 1) {
			//for(int i = 1;i <= x;i++) printf("%d ",path[i]);
			//putchar('\n');
			return 1;
		}
		else return 0;
	}
	int &note = f[x][y][up][down][prev];
	if(note != -1) return note;
	for(int i = 1;i <= 4;i++) if(y != i) {
		if(x == 1) ret += dfs(x + 1,i,up,down,y);
		else if(i < y && prev < y) {
			ret += dfs(x + 1,i,up + 1,down,y);
		}
		else if(i > y && prev > y) {
			ret += dfs(x + 1,i,up,down + 1,y);
		}
		else {
			ret += dfs(x + 1,i,up,down,y);
		}
	}
	return note = ret;
}
int main() {
	while(~scanf("%d%d",&n,&t)) {
		memset(f,-1,sizeof(f));
		int ans = 0;
		for(int i = 1;i < 4;i++) ans += dfs(1,i,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
