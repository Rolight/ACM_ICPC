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

const int maxn = 15;
int limit[maxn];
int f[maxn][2];



int dfs(int now,bool bound) {
	if(now == 1) return 1;
	int m = bound ? limit[now - 1] : 1;
	int ret = 0;
	for(int i = 0;i <= m;i++) {
		if(i != 0 && i != 1) continue;
		ret += dfs(now - 1,bound && i == limit[now - 1]);
	}
	return ret;
}

int count(int x) {
	int len = 0;
	while(x) {
		limit[++len] = x % 10;
		x /= 10;
	}
	return dfs(len + 1,true);
}

int main() {
	int n; scanf("%d",&n);
	printf("%d\n",count(n) - 1);
	return 0;
}
