#include <cstdio>

#define maxn 200001

using namespace std;

int pos[maxn],v[maxn],ans[maxn],seg[maxn << 2],N;

void build(int o,int L,int R) {
	if(L == R) seg[o] = 1;
	else {
		build(o * 2,L,(L + R) / 2);
		build(o * 2 + 1,(L + R) / 2 + 1,R);
		seg[o] = seg[o * 2] + seg[o * 2 + 1];
	}
}

void update(int o,int tar,int val,int L,int R) {
	if(L == R) seg[o] = val;
	else {
		int M = (L + R) / 2;
		if(tar <= M) update(o * 2,tar,val,L,M);
		else update(o * 2 + 1,tar,val,M + 1,R);
		seg[o] = seg[o * 2] + seg[o * 2 + 1];
	}
}

void insert(int o,int L,int R,int i,int p) {
	if(L == R) {
		ans[L] = v[i];
		update(1,L,0,1,N);
		return;
	}
	int left = o * 2,right = o * 2 + 1,M = (L + R) / 2;
	if(seg[left] >= p) insert(left,L,M,i,p);
	else insert(right,M + 1,R,i,p - seg[left]);
}

int main() {
	while(~scanf("%d",&N)) {
		for(int i = 1;i <= N;i++) scanf("%d%d",pos + i,v + i);
		build(1,1,N);
		for(int i = N;i >= 1;i--) insert(1,1,N,i,pos[i] + 1);
		for(int i = 1;i <= N;i++) printf("%d ",ans[i]);
		putchar('\n');
	}
	return 0;
}
