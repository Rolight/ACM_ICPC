#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int maxn = 8001;
const int INF = INT_MAX;

#define d(o) ((o)<<1)
#define dv(o) ((o)>>1)

int setv[maxn << 2],v,yl,yr;
bool can[maxn][maxn];

struct line {
	int y1,y2,x;
} l[maxn];

void pushdown(int o) {
	if(setv[o]) {
		int lc = d(o),rc = d(o) + 1;
		setv[lc] = setv[rc] = setv[o];
		setv[o] = 0;
	}
}

void update(int o,int L,int R) {
	if(yl <= L && yr >= R) setv[o] = v;
	else {
		int lc = d(o),rc = d(o) + 1,M = dv(L + R);
		if(setv[o]) pushdown(o);
		if(yl <= M) update(lc,L,M);
		if(yr > M) update(rc,M + 1,R);
	}
}

void query(int o,int L,int R,int p) {
	if(setv[o]) can[p][setv[o] - 1] = true;
	else if(L == R) return;
	else {
		int M = dv(L + R);
		if(yl <= M) query(d(o),L,M,p);
		if(yr > M) query(d(o) + 1,M + 1,R,p);
	}
}

bool cmp(line a,line b) {
	return a.x < b.x;
}

int work(int n) {
	int ans = 0;
	for(int i = 0;i < n;i++) {
		for(int j = i - 1;j >= 0;j--) {
			if(can[i][j]) {
				for(int k = j - 1;k >= 0;k--) {
					if(can[i][k] && can[j][k]) {
						ans++;
					}
				}
			}
		}
	}
	return ans;
}

int main() {
	int d,n;
	scanf("%d",&d);
	while(d--) {
		int N = -INF;
		scanf("%d",&n);
		memset(setv,0,sizeof(setv));
		memset(can,0,sizeof(can));
		for(int i = 0;i < n;i++) {
			scanf("%d%d%d",&l[i].y1,&l[i].y2,&l[i].x);
			l[i].y1 = (l[i].y1 + 1) * 2;
			l[i].y2 = (l[i].y2 + 1) * 2;
			if(l[i].y2 > N) N = l[i].y2;
		}
		sort(l,l + n,cmp);
		for(int i = 0;i < n;i++) {
			yl = l[i].y1; yr = l[i].y2; v = i + 1;
			query(1,1,N,i);
			update(1,1,N);
		}
		printf("%d\n",work(n));
	}
	return 0;
}
