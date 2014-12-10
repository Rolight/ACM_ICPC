#include <cstdio>
#include <cstring>
#include <iostream>

#define lowbit(x) ((x)&(-x))

using namespace std;

const int maxi = 100005;
const int maxn = 20001;
int C[maxi],num[maxn],n;
int l[maxn],r[maxn];

inline void add(int x,int d) {
	while(x <= maxi) {
		C[x] += d; x += lowbit(x);
	}
}

inline int sum(int x) {
	int ans = 0;
	while(x > 0) {
		ans += C[x]; x -= lowbit(x);
	}
	return ans;
}

int main() {
	int T; scanf("%d",&T);
	while(T--) {
		long long ans = 0;
		scanf("%d",&n);
		memset(C,0,sizeof(C));
		for(int i = 1;i <= n;i++) scanf("%d",num + i);
		for(int i = 1;i <= n;i++) {
			add(num[i],1);
			l[i] = sum(num[i] - 1);
		}
		memset(C,0,sizeof(C));
		for(int i = n;i >= 1;i--) {
			add(num[i],1);
			r[i] = sum(num[i] - 1);
		}
		for(int i = 2;i < n;i++) {
			ans += l[i] * (n - i - r[i]) + r[i] * (i - 1 - l[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
