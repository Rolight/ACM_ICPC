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
}

const int maxn = 500000 + 5;

#define lson rt<<1,l,mid
#define rson rt<<1|1,mid + 1,r

int sum[maxn << 2];

void build(int rt,int l,int r) {
	if(l == r) sum[rt] = 1;
	else {
		int mid = (l + r) >> 1;
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

int query(int rt,int l,int r,int v) {
	if(l == r) return l;
	else {
		int mid = (l + r) >> 1,lc = rt<<1;
		if(sum[lc] >= v) return query(lson,v);
		else return query(rson,v - sum[lc]);
	}
}

const int maxlen = 10;
const int maxtimes = 25;
char name[maxn][maxlen];
int num[maxn],maxcnt;
int prime[10] = {2,3,5,7,11,13,17,23,29,31};
int times[10];
vector<int> maxv;

void getmaxv(int curnum,int curcnt,int nowt,int lim) {
	if(curcnt > maxcnt) {
		maxv.clear();
		maxcnt = curcnt;
	}
	if(curcnt == maxcnt) {
		maxv.push_back(curnum);
	}
	for(int i = 1;i <= maxtimes;i++) {
		if(nowt == 0 || i <= times[nowt - 1]) {
			curnum *= prime[nowt];
			if(curnum > lim) break;
			curcnt = curcnt / i * (i + 1);
			times[nowt] = i;
			getmaxv(curnum,curcnt,nowt + 1,lim);
		}
	}
}

int main() {
	int N,K;
	setfile();
	while(scanf("%d%d",&N,&K) != EOF) {
		int ansid = INF,nowid = K % N;
		for(int i = 1;i <= N;i++) {
			scanf("%s%d",name[i],&num[i]);
		}
		maxcnt = 0;
		maxv.clear();
		memset(times,0,sizeof(times));
		getmaxv(1,1,0,N);
		build(1,1,N);
		for(int i = 1;i <= N;i++) {
			int realid = query(1,1,N,nowid),next = num[realid];
			update(1,1,N,realid,0);
			if(find(maxv.begin(),maxv.end(),i) != maxv.end() && i < ansid) {
				ansid = realid;
			}
			if(i < N) {
				if(next > 0) nowid = ((nowid - 2 + next) % (N - i) + (N - i)) % (N - i) + 1;
				else nowid = ((nowid - 1 + next) % (N - i) + N - i) % (N - i) + 1;
			}
		}
		printf("%s %d\n",name[ansid],maxcnt);
	}
	return 0;
}


