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

const int maxn = 100;
char buf[maxn][maxn];
char vv[maxn][maxn];
int n,m,cntj;

bool one() {
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(buf[i][j] == '#' && buf[i-1][j] == buf[i][j] && buf[i+1][j] == buf[i][j] && buf[i][j-1] == buf[i][j] && buf[i][j+1] == buf[i][j]) {
				if(buf[i-1][j-1] == '.' && buf[i+1][j-1] == '.' && buf[i+1][j+1] == '.' && buf[i-1][j+1] == '.') return true;
			}
		}
	}
	return false;
}


int main() {
	while(~scanf("%d%d",&n,&m)) {
		cntj = 0;
		int cntp = 0;
		for(int i = 0;i <= n+5;i++) {
			for(int j = 0;j <= m+5;j++) {
				buf[i][j] = '.';
			}
		}
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				scanf(" %c",&buf[i][j]);
				if(buf[i][j] == '#') cntp++;
				else cntj++;
			}
		}
		if(cntp == 0 || cntp == 1) puts("-1");
		else {
			int maxv = INF;
			for(int i = 1;i <= n;i++) {
				for(int j = 1;j <= m;j++) if(buf[i][j] == '#') {
					int nowv = 0;
					if(buf[i-1][j] == '#') nowv++;
					if(buf[i+1][j] == '#') nowv++;
					if(buf[i][j+1] == '#') nowv++;
					if(buf[i][j-1] == '#') nowv++;
					maxv = min(maxv,nowv);
				}
			}
			int ans = maxv;
			if(check()) printf("%d\n",maxv);
			if(ans != 0 && cntp - 1 == 1) puts("-1") ;
			else if(ans < 2) printf("%d\n",ans);
			else {
				if(one()) puts("1");
				else printf("%d\n",ans);
			}
		}
	}
	return 0;
}


