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

const int maxn = 100005;
int sum[maxn],val[maxn << 2],len[maxn << 2];

int main() {
	int n,w,l;
	while(scanf("%d", &n) == 1) {
		memset(sum,0,sizeof(sum));
		for(int i = 1; i <= n; i++) {
			scanf("%d%d",&w,&l);
			val[i] = val[i + n] = w - l;
		}
		int ans = 0,str = 0,end = 0,nowsum = 0;
		for(int i = 1; i <= 2 * n; i++) {
			if(sum[i - 1] + val[i] >= 0) {
				sum[i] = sum[i - 1] + val[i];
				len[i] = len[i - 1] + 1;
			} else {
				if(val[i] < 0) {
					len[i] = sum[i] = 0;
				} else {
					sum[i] = val[i];
					len[i] = 1;
				}
			}
			ans = max(ans,len[i]);
			if(len[i] == n) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}


