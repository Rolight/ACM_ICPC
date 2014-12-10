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

const int maxn = 1005;
int a[maxn];

int main() {
	int N;
	while(~scanf("%d",&N)) {
		int maxv = 0,str,end;
		for(int i = 1;i <= N;i++) {
			scanf("%d",&a[i]);
			maxv = max(maxv,a[i]);
		}
		str = a[1]; 
		end = a[N];
		int ans = INF;
		for(int i = 1;i <= maxv;i++) {
			for(int j = 2;j <= N;j++) {
				if(a[j] <= 0 && a[j - 1] <= 0) {
					ans = i - 1; break;
				}
			}
			for(int j = 1;j <= N;j++) a[j]--;
			if(ans != INF) break;
		}
		ans = min(ans,str);
		ans = min(ans,end);
		printf("%d\n",ans);
	}
	return 0;
}


