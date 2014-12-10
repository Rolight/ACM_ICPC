#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100001;

int f[maxn];

int findset(int i) {
	return f[i] == i ? i : f[i] = findset(f[i]);
}

inline void init() {
	for(int i = 1;i <= maxn;i++) f[i] = i;
}

int main() {
	int a,b,ans = 0;
	init();
	while(scanf("%d",&a) != -1) {
		if(a != -1) {
			scanf("%d",&b);
			int x = findset(a),y = findset(b);
			if(x == y) ans++;
			else f[x] = y;
		} else {
			printf("%d\n",ans);
			init();
			ans = 0;
		}
	}
	return 0;
}
