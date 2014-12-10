#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 20005;
const int maxv = 100005;
int N,C[maxv],val[maxn];
int low[maxn],high[maxn];

inline int lowbit(int x) {
	return x & (-x);
}

inline void add(int x,int v) {
	while(x <= maxv) {
		C[x] += v;
		x += lowbit(x);
	}
}

inline int query(int x) {
	int ans = 0;
	while(x > 0) {
		ans += C[x];
		x -= lowbit(x);
	}
	return ans;
}

inline int sum(int l,int r) {
	return query(r) - query(l - 1);
}

int main() {
	int T; scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		memset(C,0,sizeof(C));
		for(int i = 1;i <= N;i++) scanf("%d",&val[i]);
		for(int i = 1;i <= N;i++) {
			low[i] = sum(0,val[i] - 1);
			high[i] = sum(val[i] + 1,maxv - 5);
			add(val[i],1);
		}
		memset(C,0,sizeof(C));
		long long ans = 0;
		for(int i = N;i >= 1;i--) {
			ans += (long long)low[i] * sum(val[i] + 1,maxv - 5) + (long long)high[i] * sum(0,val[i] - 1);
			add(val[i],1);
		}
		cout << ans << endl;
	}
	return 0;
}
