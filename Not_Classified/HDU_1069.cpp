#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

const int maxn = 40;

struct box {
	int x,y,z;
};

box b[maxn * 3];
int f[maxn * 3];

inline bool contain(box a,box b) {
	return (a.x < b.x && a.y < b.y) || (a.y < b.x && a.x < b.y);
}

inline bool cmp(box a,box b) {
	return a.x * a.y < b.x * b.y;
}

int main() {
	int n,cc = 0;
	while(scanf("%d",&n),n) {
		for(int i = 0;i < n * 3;i += 3) {
			scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].z);
			b[i + 1].x = b[i].y; b[i + 1].y = b[i].z; b[i + 1].z = b[i].x;
			b[i + 2].x = b[i].z; b[i + 2].y = b[i].x; b[i + 2].z = b[i].y;
		}
		sort(b,b + n * 3,cmp);
		int ans = 0;
		for(int i = 0;i < n * 3;i++) {
			f[i] = b[i].z;
			for(int j = i - 1;j >= 0;j--) {
				if(contain(b[j],b[i])) {
					f[i] = max(f[i],f[j] + b[i].z);
				}
			}
			if(f[i] > ans) ans = f[i];
		}
		printf("Case %d: maximum height = %d\n",++cc,ans);
	}
	return 0;
}
