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

const int maxn = 500000 + 5;
int sum1[maxn << 2],sum2[maxn << 2],sum3[maxn << 2];
int lazyadd[maxn<<2],lazymul[maxn<<2],lazycov[maxn<<2];

#define MOD 10007
#define lson rt<<1,l,m
#define rson rt<<1|1,m+1,r
#define sq(x) (((x)%MOD*(x)%MOD)%MOD)
#define tq(x) ((sq(x)*(x)%MOD)%MOD)
#define ADD 1
#define MUL 2
#define COV 3

void pushdown(int rt,int l,int r);

inline void pushup(int rt,int l,int r) {
	pushdown(rt,l,r);
	l =rt<<1,r = rt<<1|1;
	sum1[rt] = sum1[l] + sum1[r];
	sum2[rt] = sum2[l] + sum2[r];
	sum3[rt] = sum3[l] + sum3[r];
	sum1[rt] %= MOD; sum2[rt] %= MOD; sum3[rt] %= MOD;
}

void pushdown(int rt,int l,int r) {
	int n = (r - l + 1),m = (l + r) >> 1;
	n %= MOD;
	l = rt<<1,r = rt<<1|1;
	if(lazycov[rt] != 0) {
		//覆盖标记
		sum1[rt] = lazycov[rt] * n;
		sum2[rt] = sq(lazycov[rt]) * n;
		sum3[rt] = tq(lazycov[rt]) * n;
		lazycov[l] = lazycov[r]  = lazycov[rt] % MOD;
		lazycov[rt] = 0;
	}
	if(lazymul[rt] != 0) {
		//乘标记
		sum1[rt] *= lazymul[rt];
		sum2[rt] *= sq(lazymul[rt]);
		sum3[rt] *= tq(lazymul[rt]);
		lazymul[l]  *= lazymul[rt] % MOD;
		lazymul[r] *= lazymul[rt] % MOD;
		lazymul[l] %= MOD; lazymul[r] %= MOD;
		lazymul[rt] = 0;
	}
	if(lazyadd[rt] != 0) {
		//增加标记
		int s1 = sum1[rt],s2 = sum2[rt];
		s1 %= MOD; s2 %= MOD;
		sum1[rt] = sum1[rt] + lazyadd[rt] * n;
		sum2[rt] = sum2[rt] + lazyadd[rt] * 2 * s1 + n * sq(lazyadd[rt]);
		sum3[rt] = sum3[rt] + lazyadd[rt] * 3 * s2 + 3 * sq(lazyadd[rt]) * s1 + n * tq(lazyadd[rt]);
		lazyadd[l] += lazyadd[rt];
		lazyadd[r] += lazyadd[rt];
		lazyadd[l] %= MOD;
		lazyadd[r] %= MOD;
		lazyadd[rt] = 0;
	}
	sum1[rt] %= MOD; sum2[rt] %= MOD; sum3[rt] %= MOD;
}

void build(int rt,int l,int r) {
	if(l == r) {
		sum1[rt] = sum2[rt] = sum3[rt] = 0;
		lazyadd[rt] = lazymul[rt] = lazycov[rt] = 0;
		lazymul[rt] = 0;
	} else {
		int m = (l + r) >> 1;
		build(lson); build(rson);
		lazyadd[rt] = lazymul[rt] = lazycov[rt] = 0;
		lazymul[rt] = 0;
		pushup(rt,l,r);
	}
}

int query(int rt,int l,int r,int ql,int qr,int p) {
	if(ql <= l && r <= qr) {
		pushdown(rt,l,r);
		if(p == 1) return sum1[rt];
		if(p == 2) return sum2[rt];
		if(p == 3) return sum3[rt];
	} else {
		pushdown(rt,l,r);
		int m = (l + r) >> 1;
		int ret = 0;
		if(ql <= m) ret += query(lson,ql,qr,p);
		if(qr > m) ret += query(rson,ql,qr,p);
		return ret % MOD;
	}
}

void update(int rt,int l,int r,int ql,int qr,int type,int c) {
	if(ql <= l && r <= qr) {
		pushdown(rt,l,r);
		if(type == COV) {
			lazyadd[rt] = lazymul[rt] = 0;
			lazycov[rt] = c % MOD;
		} 
		if(type == ADD) {
			lazyadd[rt] = c;
			lazyadd[rt] %= MOD;
		}
		if(type == MUL) {
			lazymul[rt] = c;
			lazymul[rt] %= MOD;
		}
	} else {
		pushdown(rt,l,r);
		int m = (l + r) >> 1;
		if(ql <= m) update(lson,ql,qr,type,c);
		if(qr > m) update(rson,ql,qr,type,c);
		pushup(rt,l,r);
	}
}

int main() {
	int n,m;
	while(scanf("%d%d",&n,&m),n+m) {
		build(1,1,n);
		for(int i = 0;i < m;i++) {
			int cmd,x,y,c;
			scanf("%d%d%d%d",&cmd,&x,&y,&c);
			c %= MOD;
			y = min(y,n);
			if(cmd == 4) {
				int ret = query(1,1,n,x,y,c);
				printf("%d\n",ret);
			} else update(1,1,n,x,y,cmd,c);
			for(int j = 1;j <= 5;j++) {
				printf("%d %d %d\n",query(1,1,n,j,j,1),query(1,1,n,j,j,2),query(1,1,n,j,j,3));
			}
		}
	}
	return 0;
}


