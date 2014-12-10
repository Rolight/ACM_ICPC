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

int n,sum[maxn],k[maxn];
int main() {
	scanf("%d",&n);
	for(int i = 0;i < n;i++) scanf("%d",&k[i]);
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < k[i];j++) {
			int tmp; scanf("%d",&tmp);
			sum[i] += tmp * 5 + 15;
		}
	}
	sort(sum,sum + n);
	printf("%d\n",sum[0]);
	return 0;
}




