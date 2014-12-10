#include <iostream>
#include <climits>
#include <cstdio>

#define maxn 1001
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define INF INT_MAX

using namespace std;

int maxv[maxn << 2],minv[maxn << 2],sumv[maxn << 2],addv[maxn << 2],a[maxn],N;
int _sum,_min,_max,yl,yr,v;

void build(int o,int L,int R) {
	if(L == R) 
		maxv[o] = minv[o] = sumv[o] = a[L];
	else {
		int M = (L + R) / 2,l = o * 2,r = o * 2 + 1;
		build(l,L,M); build(r,M + 1,R);
		maxv[o] = max(maxv[l],maxv[r]);
		minv[o] = min(minv[l],minv[r]);
		sumv[o] = sumv[l] + sumv[r];
	}
}

void maintain(int o,int L,int R) {
	int l = o * 2,r = o * 2 + 1,M = (L + R) / 2;
	maxv[o] = minv[o] = sumv[o] = 0;
	if(R > L) {
		sumv[o] = sumv[l] + sumv[r];
		minv[o] = min(minv[l],minv[r]);
		maxv[o] = max(maxv[l],maxv[r]);
	}
	minv[o] += addv[o]; maxv[o] += addv[o]; sumv[o] += addv[o] *(R - L + 1);
}

void query(int o,int L,int R,int add) {
	if(yl <= L && yr >= R) {
		_sum += sumv[o] + add * (R - L + 1);
		_min = min(_min,minv[o] + add);
		_max = max(_max,maxv[o] + add);
	} else {
		int M = (L + R) / 2;
		if(yl <= M) query(o * 2,L,M,add + addv[o]);
		if(yr > M) query(o * 2 + 1,M + 1,R,add + addv[o]);
	}
}

void update(int o,int L,int R) {
	int l = o * 2,r = o * 2 + 1,M = (L + R) / 2;
	if(yl <= L && yr >= R) addv[o] += v;
	else {
		int M = (L + R) / 2;
		if(yl <= M) update(l,L,M);
		if(yr > M) update(r,M + 1,R);
	}
	maintain(o,L,R);
}

int main() {
	scanf("%d",&N);
	for(int i = 1;i <= N;i++)
		scanf("%d",a + i);
	for(int i = 1;i <= N;i++) printf("%d ",a[i]);
	printf("\n");
	build(1,1,N);
	char cmd;
	while(scanf(" %c",&cmd),cmd != 'E') {
		if(cmd == 'Q') {
			scanf("%d%d",&yl,&yr);
			_min = INF;
			_max = -INF;
			_sum = 0;
			query(1,1,N,0);
			printf("min = %d,max = %d,sum = %d\n",_min,_max,_sum);
		}
		if(cmd == 'A') {
			scanf("%d%d%d",&yl,&yr,&v);
			update(1,1,N);
		}
		for(int i = 1;i <= N;i++) {
			_sum = 0;
			yl = yr = i;
			query(1,1,N,0);
			printf("%d ",_sum);
		}
		printf("\n");
	}
	return 0;
}
