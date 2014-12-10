#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

#define d(o) ((o)<<1)
#define dv(o) ((o)>>1)

const int maxn = 50000;

using namespace std;

int yl,yr,N,v,src[maxn],tar[maxn];
bool vis[maxn];
short setv[maxn << 2];

void pushdown(int o) {
	int lc = d(o),rc = d(o) + 1;
	setv[lc] = setv[rc] = setv[o];
	setv[o] = 0;
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

int query(int p){
	int o = 1,L = 1,R = N;
	while(L <= R) {
		int M = dv(L + R);
		if(setv[o] || L == R) return setv[o];
		if(setv[o]) pushdown(o);
		if(p <= M) {
			R = M; o = d(o);
		}
		else {
			L = M + 1;
			o = d(o) + 1;
		}
	}
}	

int find(int p,int lim) {
	int L = 0,R = lim;
	while(L <= R) {
		int M = dv(L + R);
		if(src[M] == p) return M;
		if(src[M] > p) R = M - 1;
		else L = M + 1;
	}	
}

struct seg {
	int l,r;
} qseg[10001];


int main() {
	int n,m,max;
	scanf("%d",&n);
	for(int i = 0;i < n;i++) {
		int amount = 0,nn = 0;
		max = 0;
		memset(setv,0,sizeof(setv));
		memset(vis,0,sizeof(vis));
		scanf("%d",&m);
		for(int j = 0;j < m;j++) {
			scanf("%d%d",&qseg[j].l,&qseg[j].r);
			src[nn++] = qseg[j].l;
			src[nn++] = qseg[j].r;
		}
		sort(src,src + nn);
		for(int j = 0,now = 1;j < nn;j++) {
			if(j && src[j] == src[j - 1]) tar[j] = now - 1;
			else if(!j) tar[j] = now++;
			else if(src[j] - src[j - 1] > 1) {
				tar[j] = now + 1;
				now += 2;
			}
			else tar[j] = now++;
		}
		N = tar[nn - 1];
		for(int j = 0;j < m;j++) {
			int l = find(qseg[j].l,nn - 1),r = find(qseg[j].r,nn - 1);
			qseg[j].l = tar[l]; qseg[j].r = tar[r];
		}
		for(int j = 0;j < m;j++) {
			yl = qseg[j].l; yr = qseg[j].r; v = j + 1;
			update(1,1,N);
		}
		for(int j = 1;j <= N;j++) {
			int ans = query(j);
			if(!vis[ans] && ans != 0) {
				amount++;
				vis[ans] = true;
			}
		}
		printf("%d\n",amount);
	}
	return 0;
}
