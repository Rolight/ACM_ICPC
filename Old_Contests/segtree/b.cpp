#include <iostream>
#include <cstdio>
#include <climits>
#include <string>

using namespace std;

#define maxn 200001
#define d(n) ((n)<<1)
#define dv(n) ((n)>>1)

int grade[maxn],maxv[maxn << 2],M,N;

int max(int a,int b) {
	return (a > b) ? a : b;
}

int build(int o,int L,int R) {
	int M = dv(L + R);
	if(L == R) return maxv[o] = grade[L];
	maxv[o] = max(build(d(o),L,M),build(d(o) + 1,M + 1,R));
	return maxv[o];
}

int query(int o,int L,int R,int ql,int qr){
	int ans = -INT_MAX,M = dv(L + R);
	if(ql <= L && qr >= R) return maxv[o];
	if(ql <= M) ans = max(ans,query(d(o),L,M,ql,qr));
	if(qr > M) ans = max(ans,query(d(o) + 1,M + 1,R,ql,qr));
	return ans;
}

void update(int o,int tar,int val,int L,int R) {
	if(L == R) maxv[o] = val;
	else {
		if(tar <= dv(L + R)) 
			update(d(o),tar,val,L,dv(L + R));
		else update(d(o) + 1,tar,val,dv(L + R) + 1,R);
		maxv[o] = max(maxv[d(o)],maxv[d(o) + 1]);
	}
}

int main(){
	char cmd[3];
	int a,b;
	while(scanf("%d%d",&N,&M) == 2) {
		for(int i = 1;i <= N;i++) scanf("%d",grade + i);
		build(1,1,N);
		for(int i = 0;i < M;i++) {
			scanf("%s%d%d",cmd,&a,&b);
			if(cmd[0] == 'Q') 
				cout << query(1,1,N,a,b) << endl;
			else update(1,a,b,1,N);
		}
	}
	return 0;
}
