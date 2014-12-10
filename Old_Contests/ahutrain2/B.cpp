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

const int maxv = 100000 + 10;
bool vis[maxv];
int rest[maxv];

int main() {
	int v,n;
	while(~scanf("%d",&v)) {
		int ans = 0;
		scanf("%d",&n);
		memset(vis,0,sizeof(bool) * (v + 5));
		vis[0] = true;
		for(int i = 0;i < n;i++) {
			int amount,val;
			scanf("%d%d",&amount,&val);
			memset(rest,0,sizeof(int) * (v + 5));
			for(int j = val;j <= v;j++) {
				if(vis[j - val] && rest[j - val] < amount && !vis[j]) {
					vis[j] = true;
					rest[j] = rest[j - val] + 1;
				}
			}
		}
		for(int j = v;j >= 0;j--) {
			if(vis[j]) {
				ans = j; break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}


