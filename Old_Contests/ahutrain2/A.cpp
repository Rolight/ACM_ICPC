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

const int maxn = 3500;
const int maxm = 12885;

int f[maxm];

int main() {
	int n,m;
	while(~scanf("%d%d",&n,&m)) {
		memset(f,0,sizeof(int) * (m + 3));
		for(int i = 0;i < n;i++) {
			int c,w; scanf("%d%d",&c,&w);
			for(int j = m;j >= c;j--) {
				f[j] = max(f[j - c] + w,f[j]);
			}
		}
		printf("%d\n",f[m]);
	}
	return 0;
}


