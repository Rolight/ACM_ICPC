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
const int INF = INT_MAX / 3;

void setfile() {
	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}

const int maxv = 10000 * 125;
const int maxn = 105;

void zero_one_pack(int c,int w,int v,int f[]) {
	for(int i = v;i >= c;i--) {
		f[i] = min(f[i - c] + w,f[i]);
	}
}

void complete_pack(int c,int w,int v,int f[]) {
	for(int i = c;i <= v;i++) {
		f[i] = min(f[i - c] + w,f[i]);
	}
}

void multi_pack(int c,int w,int v,int m,int f[]) {
	if(c * m >= v) complete_pack(c,w,v,f);
	else {
		int k = 1;
		while(k < m) {
			zero_one_pack(c * k,w * k,v,f);
			m -= k;
			k <<= 1;
		}
		zero_one_pack(c * m,w * m,v,f);
	}
}

int famer[maxv],store[maxv];

struct cent {
	int c,a;
	bool operator < (const cent &x) const {
		return c < x.c;
	}
};

cent cc[maxn];

int main() {
	int n,v;	
	while(~scanf("%d%d",&n,&v)) {
		int sum = 0;
		for(int i = 0;i < n;i++) scanf("%d",&cc[i].c);
		for(int i = 0;i < n;i++) scanf("%d",&cc[i].a);
		sort(cc,cc + n);
		for(int i = 0;i < cc[n-1].c;i++) {
			sum += cc[i].c * cc[i].a;
		}
		sum = max(v,sum);
		sum = min(sum,100000);
		for(int i = 0;i <= sum;i++) famer[i] = store[i] = INF;
		famer[0] = store[0] = 0;
		for(int i = 0;i < n;i++) {
			multi_pack(cc[i].c,1,sum,cc[i].a,famer);
			complete_pack(cc[i].c,1,sum,store);
		}
		int ans = famer[v];
		for(int i = v + 1;i <= sum;i++) {
			ans = min(ans,famer[i] + store[i - v]);
		}
		if(ans < INF) printf("%d\n",ans);
		else puts("-1");
	}
	return 0;
}


