#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

int p[1001];

int find(int x) {
	return (x == p[x]) ? x : p[x] = find(p[x]);
}

int main() {
	int n,m;
	while(~scanf("%d%d",&n,&m)) {
		for(int i = 1;i <= n;i++) p[i] = i;
		for(int i = 0;i < m;i++) {
			int a,b; scanf("%d%d",&a,&b);
			if(find(a) != find(b)) {
				p[find(a)] = p[find(b)];
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i++) if(find(i) == i) ans++;
		printf("%d\n",ans - 1);
	}
	return 0;
}
