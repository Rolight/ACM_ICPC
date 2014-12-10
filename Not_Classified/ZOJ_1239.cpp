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

const int maxn = 55;
const int maxv = 5000;
bool vis[maxv];
int ans[maxn];


bool issq(int v) {
	int ret = (int)sqrt((double)v);
	return ret * ret == v;
}

int work(int n) {
	int ret = 0;
	memset(vis,0,sizeof(vis));
	for(int i = 1;i <= n;i++) {
		if(!vis[i]) {
			vis[i] = true;
			int nowv = i;
			for(int j = i + 1;j <= n;j++)  {
				if(!vis[j] && issq(nowv + j)) {
					nowv = j; vis[j] = true;
				}
			}
			ret++;
		}
	}
	return ret;
}

int main() {
	for(int i = 1;i <= 1300;i++) {
		int ret = work(i);
		if(ret <= 50) ans[ret] = i;
	}
	int T; scanf("%d",&T);
	while(T--) {
		int n; scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
	return 0;
}



