#include <cstdio>
#include <cstring>
#include <algorithm>

#define LEFT 'L'
#define RIGHT 'R'
#define TURNING 'T'

using namespace std;

const int maxn = 10005;
int order[maxn];

struct Ant {
	int id,pos,dir;
	bool operator < (const Ant& x) const {
		return pos < x.pos;
	};
};

Ant a[maxn];

int main() {
	int L,T,n,k;
	scanf("%d",&k);
	for(int kase = 1;kase <= k;kase++) {
		scanf("%d%d%d",&L,&T,&n);
		for(int i = 0;i < n;i++) {
			scanf("%d %c",&a[i].pos,&a[i].dir);
			a[i].id = i;
		}
		sort(a,a + n);
		for(int i = 0;i < n;i++) {
			order[a[i].id] = i;
			if(a[i].dir == LEFT) {
				a[i].pos -= T;
			} else {
				a[i].pos += T;
			}
		}
		sort(a,a + n);
		printf("Case #%d:\n",kase);
		for(int i = 0;i < n;i++) {
			int nowp = order[i];
			if(a[nowp].pos < 0 || a[nowp].pos > L) {
				puts("Fell off");
			} else {
				int left = -1,right = -1;
				if(nowp > 0) left = a[nowp - 1].pos;
				if(nowp < n) right = a[nowp + 1].pos;
				if(left != a[nowp].pos && right != a[nowp].pos) {
					printf("%d %c\n",a[nowp].pos,a[nowp].dir);
				} else {
					printf("%d Turning\n",a[nowp].pos);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
