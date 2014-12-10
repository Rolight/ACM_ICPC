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

int abs(int a) {
	return a < 0 ? -a : a;
}

int f[1005][1005],p[1005][1005];
int cc[1005],dd[1005],N;

int main() {
	int T; scanf("%d",&T);
	while(T--) {
		memset(f,0,sizeof(f));
		scanf("%d",&N);
		N++;
		cc[1] = dd[1]  = 0;
		for(int i = 2;i <= N;i++) {
			scanf("%d%d",&cc[i],&dd[i]);
		}
		for(int i = 1;i <= N;i++) {
			for(int j = 1;j <= N;j++) {
				p[i][j] = abs(cc[i]-cc[j]) * 400 + min(abs(dd[i]-dd[j]),360-abs(dd[i]-dd[j]));
			}
		}
		f[1][2] = p[1][2];
		for(int j = 3;j <= N;j++) {
			for(int i = 1;i <= j - 2;i++) {
				f[i][j] = f[i][j - 1] + p[j - 1][j];
			}
			f[j - 1][j] = INF;
			for(int k = 1;k <= j - 2;k++) {
				f[j - 1][j] = min(f[k][j-1]+p[k][j],f[j-1][j]);
			}
		}
		f[N][N] = f[N - 1][N] + p[N - 1][N];
		printf("%d\n",f[N][N] + N * 10 - 10);
	}
	return 0;
}


