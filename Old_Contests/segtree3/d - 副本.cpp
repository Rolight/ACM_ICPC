#include <cstdio>

using namespace std;

#define M (((L)+(R))>>1)
#define lson rt<<1,L,M
#define rson rt<<1|1,M+1,R
#define len(a,b) ((b)-(a)+1)
#define undes 0
#define des 1

const int maxn = 50001,sizen = 50001 << 2;

int lmax[sizen],rmax[sizen],val[maxn],q[maxn],tar,v;

void setfile() {
	freopen("in.txt","r",stdin);
	freopen("out1.txt","w",stdout);
}

void build(int rt,int L,int R) {
	if(L == R) {
		lmax[rt] = rmax[rt] = 1;
		val[L] = undes;
	}
	else {
		int l = rt<<1,r = rt<<1|1;
		build(lson); build(rson);
		lmax[rt] = rmax[rt] = lmax[l] + lmax[r];
	}
}

void update(int rt,int L,int R) {
	if(L == R) val[tar] = v;
	else {
		if(tar <= M) update(lson);
		else update(rson);
		int l = rt<<1,r = rt<<1|1;
		lmax[rt] = lmax[l]; rmax[rt] = rmax[r];
		if(val[M] == val[M + 1] && val[M] == undes) {
			if(lmax[l] == len(L,M)) lmax[rt] += lmax[r];
			if(rmax[r] == len(M + 1,R)) rmax[rt] += rmax[l];
		}
	}
}

int query(int t,int N) {
	int L = 1,R = N,rt = 1,left = 0,right = 0;
	if(val[t] == des) return 0;
	while(L <= R) {
		int l = rt<<1,r = rt<<1|1;
		if(L == R) return left + right + 1;
		if(t <= M) {
			if(val[M] == val[M + 1] && val[M] == undes) {
				if(right == 0 || lmax[r] == len(M + 1,R)) right += lmax[r];
				else right = lmax[r];
			}
			else right = 0;
			R = M; rt = rt<<1;
		} else {
			if(val[M] == val[M + 1] && val[M] == undes) {
				if(left == 0 || rmax[l] == len(L,M)) left += rmax[l];
				else left = rmax[l];
			}
			else left = 0;
			L = M + 1; rt = rt<<1|1;
		}
	}
}

void dis(int n) {
	for(int i = 1;i <= n;i++) {
		printf("%s",val[i] == des?"X":"O");
	}
	printf("\n");
}

int main() {
//	setfile();
	int n,m,cq;
	char cmd;
	while(~scanf("%d%d",&n,&m)) {
		build(1,1,n);
		cq = 0;
		for(int i = 0;i < m;i++) {
			//dis(n);
			scanf(" %c",&cmd);
			if(cmd == 'R') {
				while(cq && val[q[cq - 1]] == undes) cq--;
				tar = q[--cq]; v = undes; update(1,1,n);
			} else {
				scanf("%d",&tar);
				if(cmd == 'D') {
					q[cq++] = tar; v = des; update(1,1,n);
				} else printf("%d\n",query(tar,n));
			}
		}
	}
	return 0;
}
