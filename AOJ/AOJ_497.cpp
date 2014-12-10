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

const int maxn = 5005;
int f[maxn][2],v[maxn];

int main() {
	int n;
	while(scanf("%d",&n),n) {
		for(int i = 1;i <= n;i++) scanf("%d",&v[i]);
		memset(f,0,sizeof(f));
		int ans = -1;
		for(int i = 1;i <= n;i++) {
			f[i][0] = f[i][1] = 1;
			for(int j = i - 1;j >= 1;j--) {
				if(v[j] > v[i]) f[i][0] = max(f[i][0],f[j][1] + 1);
				if(v[j] < v[i]) f[i][1] = max(f[i][1],f[j][0] + 1);
			}
			ans = max(ans,f[i][0]);
			ans = max(ans,f[i][1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}


