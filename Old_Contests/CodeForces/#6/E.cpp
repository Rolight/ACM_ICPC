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

const int maxn = 100000 + 5;
const int maxk = 1000000 + 5;

int minv[maxn << 2],maxv[maxn << 2];
int val[maxn];
int n,k;

void build(int o,int l,int r) {
	if(l == r) {
		minv[o] = maxv[o] = val[l];
	} else {
		int m = (l + r) >> 1;
		build(o << 1,l,m);
		build(o << 1 | 1,m + 1,r);
		minv[o] = min(minv[o << 1],minv[o << 1 | 1]);
		maxv[o] = max(maxv[o << 1],maxv[o << 1 | 1]);
	}
}

int ql,qr;

int querymin(int o,int l,int r) {
	if(ql <= l && qr >= r) {
		return minv[o];
	}
	int m = (l + r) >> 1;
	int ret = INF;
	if(ql <= m) ret = min(ret,querymin(o << 1,l,m));
	if(qr > m) ret = min(ret,querymin(o << 1 | 1,m + 1,r));
	return ret;
}


int querymax(int o,int l,int r) {
	if(ql <= l && qr >= r) {
		return maxv[o];
	}
	int m = (l + r) >> 1;
	int ret = -INF;
	if(ql <= m) ret = max(ret,querymax(o << 1,l,m));
	if(qr > m) ret = max(ret,querymax(o << 1 | 1,m + 1,r));
	return ret;
}

bool ok(int len) {
	bool ret = false;
	for(int i = 1;i + len - 1 <= n;i++) {
		ql = i, qr = i + len - 1;
		if(querymax(1,1,n) - querymin(1,1,n) <= k) ret |= true;
	}
	return ret;
}


int main() {
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++) scanf("%d",&val[i]);
	build(1,1,n);
	int l = 1,r = n;
	while(l < r) {
		int mid = (l + r + 1) / 2;
		if(ok(mid)) l = mid;
		else r = mid - 1;
	}
	int cnt = 0;
	for(int i = 1;i + l - 1 <= n;i++) {
		ql = i,qr = i + l - 1;
		if(querymax(1,1,n) - querymin(1,1,n) <= k) {
			cnt++;
		}
	}
	printf("%d %d\n",l,cnt);
	for(int i = 1;i + l - 1 <= n;i++) {
		ql = i,qr = i + l - 1;
		if(querymax(1,1,n) - querymin(1,1,n) <= k) {
			printf("%d %d\n",ql,qr);
		}
	}

	return 0;
}

