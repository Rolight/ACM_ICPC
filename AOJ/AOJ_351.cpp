#include <cstdio>

using namespace std;

#define M ((L+R)>>1)
#define lson rt<<1,L,M
#define rson rt<<1|1,M+1,R
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX 0
#define MIN 1

const int maxn = 100001;

int a[maxn],maxv[maxn << 2],minv[maxn << 2],ql,qr,flag = 0;

void build(int rt,int L,int R) {
	if(L == R) maxv[rt] = minv[rt] = a[L];
	else {
		build(lson); build(rson);
		maxv[rt] = max(maxv[rt<<1],maxv[rt<<1|1]);
		minv[rt] = min(minv[rt<<1],minv[rt<<1|1]);
	}
}

int query(int rt,int L,int R) {
	if(ql <= L && qr >= R) {
		if(flag == MAX) return maxv[rt];
		else return minv[rt];
	}
	int ans,left,right;
	if(flag == MAX) {
		left = right = -1;
		if(ql <= M) left = query(lson);
		if(qr > M) right = query(rson);
		return max(left,right);
	} else {
		left = right = 1<<31 - 1;
		if(ql <= M) left = query(lson);
		if(qr > M) right = query(rson);
		return min(left,right);
	}
}

int main() {
	int m,N;
	while(~scanf("%d%d",&N,&m)) {
		for(int i = 1;i <= N;i++) scanf("%d",a + i);
		build(1,1,N);
		for(int i = 0;i < m;i++) {
			scanf("%d%d",&ql,&qr);
			flag = MAX;
			int _max = query(1,1,N),_min;
			flag = MIN;
			_min = query(1,1,N);
			printf("%d\n",_max - _min);
		}
	}
	return 0;
}
