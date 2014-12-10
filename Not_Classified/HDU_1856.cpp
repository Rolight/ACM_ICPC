#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000001;
int f[maxn],count[maxn];

int findset(int n) {
	if(f[n] == -1) return n;
	else return f[n] = findset(f[n]);
}

int main() {
	int n = -1,m,a,b;
	while(~scanf("%d",&m)) {
		memset(f,-1,sizeof(f));
		memset(count,0,sizeof(count));
		for(int i = 0;i < m;i++) {
			scanf("%d%d",&a,&b);
			if(a > n) n = a;
			if(b > n) n = b;
			int x = findset(a),y = findset(b);
			if(x != y) f[x] = y;
		}
		for(int i = 1;i <= n;i++) count[findset(i)]++;
		int ans = -1;
		for(int i = 1;i <= n;i++) if(ans < count[i]) ans = count[i];
		printf("%d\n",ans);
	}
	return 0;
}
