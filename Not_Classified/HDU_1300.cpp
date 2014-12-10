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

const int maxn = 105;
int amount[maxn], val[maxn], cost[maxn];

int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i = 1;i <= n;i++) {
			scanf("%d%d",&amount[i],&val[i]);
			cost[i] = INF;
			int cnt = 0;
			for(int j = i;j >= 1;j--) {
				cnt += amount[j];
				cost[i] = min(cost[i],cost[j - 1] + (cnt + 10) * val[i]);
			}
		}
		printf("%d\n",cost[n]);
	}
}


