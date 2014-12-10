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
const int maxn = 200000 + 5;
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r

void setfile() {
	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}

int N,val[maxn],sum[maxn<<2],pos[maxn],v[maxn];

void build(int rt,int l,int r) {
	int mid = (l + r) >> 1;
	if(l == r) sum[rt] = 1;
	else {
		build(lson); build(rson);
		sum[rt] = sum[rt<<1] + sum[rt<<1|1];
	}
}

void update(int rt,int l,int r,int tar,int x) {
	if(l == r) sum[rt] = x;
	else {
		int mid = (l + r) >> 1;
		if(tar <= mid) update(lson,tar,x);
		else update(rson,tar,x);
		sum[rt] = sum[rt<<1] + sum[rt<<1|1];
	}
}

int query(int rt,int l,int r,int val) {
	if(l == r) return l;
	else {
		int mid = (l + r) >> 1;
		if(val <= sum[rt<<1]) return query(lson,val);
		else return query(rson,val - sum[rt<<1]);
	}
}

int main() {
	while(scanf("%d",&N) != EOF) {
		build(1,1,N);
		memset(val,-1,sizeof(val));
		for(int i = 1;i <= N;i++) {
			scanf("%d%d",pos + i,v + i);
		}
		for(int i = N;i >= 1;i--) {
			int ret = query(1,1,N,pos[i] + 1);
			val[ret] = v[i];
			update(1,1,N,ret,0);
		}
		for(int i = 1;i <= N;i++) {
			if(val[i] != -1) {
				if(i > 1) putchar(' ');
				printf("%d",val[i]);
			}
		}
		putchar('\n');
	}
	return 0;
}


