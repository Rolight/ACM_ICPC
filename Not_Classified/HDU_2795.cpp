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
#define lson rc<<1,l,m
#define rson rc<<1|1,m+1,r

using namespace std;

typedef long long LL;
const int INF = INT_MAX / 2;

void setfile() {
	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}

const int maxn = 200000 + 5;
int h,w,n;
int maxv[maxn << 2],val[maxn];

void build(int rc,int l,int r) {
	if(l == r) maxv[rc] = val[l];
	else {
		int m = (l + r) >> 1;
		build(lson); build(rson);
		maxv[rc] = max(maxv[rc<<1],maxv[rc<<1|1]);
	}
}

int work(int rc,int l,int r,int qv) {
	if(l == r) {
		if(maxv[rc] >= qv) {
			maxv[rc] -= qv;
			return l;
		 } else {
			return -1;
		 }
	} else {
		int m = (l + r) >> 1,ret;
		if(maxv[rc<<1] >= qv) ret = work(lson,qv);
		else ret = work(rson,qv);
		maxv[rc] = max(maxv[rc<<1],maxv[rc<<1|1]);
		return ret;
	}
}


int main() {
	while(~scanf("%d%d%d",&h,&w,&n)) {
		int m = min(n,h);
		for(int i = 1;i <= m;i++) val[i] = w;
		build(1,1,m);
		for(int i = 1;i <= n;i++) {
			int wid; scanf("%d",&wid);
			printf("%d\n",work(1,1,m,wid));
		}
	}
	return 0;
}


