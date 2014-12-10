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

inline int lowbit(int x) {
	return x & (-x);
}

const int maxn = 5005;
int C[maxn],N,val[maxn];

void update(int a,int x) {
	while(a <= N) {
		C[a] += x;
		a += lowbit(a);
	}
}

int query(int r) {
	int ans = 0;
	while(r > 0) {
		ans += C[r];
		r -= lowbit(r);
	}
	return ans;
}

inline int getsum(int l,int r) {
	return query(r) - query(l - 1);
}

int main() {
	while(~scanf("%d",&N)) {
		int ori = 0,ans = INF;
		memset(C,0,sizeof(C));
		for(int i = 0;i < N;i++) {
			scanf("%d",&val[i]);
			val[i]++;
			update(val[i],1);
			ori += getsum(val[i] + 1,N);
		}
		ans = ori;
		for(int i = 0;i < N;i++) {
			ori = ori + getsum(val[i] + 1,N) - getsum(1,val[i] - 1);
			ans = min(ori,ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}


