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
const int MOD = 1000000007;
long long f[maxn][2];
int p[maxn];

int main() {
	int n; scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",&p[i]);
	for(int i = 1;i <= n;i++) {
		f[i][1] = (f[i - 1][0] + 1) % MOD;
		f[i][0] = (((f[i][1] - f[p[i] - 1][0] + MOD) * 2) % MOD + f[p[i] - 1][0] % MOD) % MOD;
	}
	printf("%I64d\n",f[n][0] % 1000000007);
	return 0;
}


