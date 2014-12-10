#include <iostream>
#include <cstdio>

#define l(o) ((o)<<1)
#define r(o) (l(o)|1)
#define dv(o) ((o)>>1)

using namespace std;

const int maxn = 100001;

long long sumv[maxn << 2],addv[maxn << 2];
int ql,qr,v,N,a[maxn];

void build(int o,int L,int R) {
	if(L == R) sumv[o] = a[L];
	else {
		int M = dv(L + R);
		build(l(o),L,M); build(r(o),M + 1,R);
		sumv[o] = sumv[l(o)] + sumv[r(o)];
	}
}

void update(int o,int L,int R) {
	if(ql <= L && qr >= R) {
		addv[o] += v;
		sumv[o] += v * (R - L + 1);
	} else {
		int lc = l(o),rc = r(o),M = (R + L) / 2;
		if(addv[o]) {
			addv[lc] += addv[o]; addv[rc] += addv[o];
			sumv[lc] += addv[o] * (M - L + 1);
			sumv[rc] += addv[o] * (R - M);
			addv[o] = 0;
		}
		if(ql <= M) update(lc,L,M);
		if(qr > M) update(rc,M + 1,R);
		sumv[o] = sumv[lc] + sumv[rc];
	}
}

long long query(int o,int L,int R) {
	if(ql <= L && qr >= R) return sumv[o];
	int M = dv(L + R),lc = l(o),rc = r(o);
	long long sum = 0;
	if(addv[o]) {
		addv[lc] += addv[o]; addv[rc] += addv[o];
		sumv[lc] += addv[o] * (M - L + 1);
		sumv[rc] += addv[o] * (R - M);
		addv[o] = 0;
	}
	if(ql <= M) sum += query(lc,L,M);
	if(qr > M) sum += query(rc,M + 1,R);
	return sum;
}
int main() {
	char cmd;
	int Q;
	scanf("%d%d",&N,&Q);
	for(int i = 1;i <= N;i++) scanf("%d",a + i);
	build(1,1,N);
	for(int i = 0;i < Q;i++) {
		scanf(" %c%d%d",&cmd,&ql,&qr);
		if(cmd == 'Q') {
			printf("%I64d\n",query(1,1,N));
		} else {
			scanf("%d",&v);
			update(1,1,N);
		}
	}
	return 0;
}
