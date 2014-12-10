#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 50001;

#define des 1
#define undes 0

int val[maxn],tar,v;

void build(int rt,int L,int R) {
	memset(val,0,sizeof(val));
}

void update(int rt,int L,int R) {
	val[tar] = v;
}

int query(int t,int n) {
	if(val[t] == 1) return 0;
	int left = 0,right = 0;
	for(int i = t + 1;i <= n && val[i] == 0;i++) right++;
	for(int i = t - 1;i > 0 && val[i] == 0;i--) left++;
	return left + right + 1;
}

void setfile() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}

int main() {
	setfile();
	int n,m,q[maxn],cq = 0;
	char cmd;
	while(~scanf("%d%d",&n,&m)) {
		build(1,1,n);
		cq = 0;
		for(int i = 0;i < m;i++) {
			scanf(" %c",&cmd);
			if(cmd == 'R') {
				if(cq) {
					tar = q[--cq]; v = undes;
					update(1,1,n);
				}
			} else {
				scanf("%d",&tar);
				if(cmd == 'D') {
					q[cq++] = tar; v = des; update(1,1,n);
				} else printf("%d\n",query(tar,n));
			}
			//dis(n);
		}
	}
	return 0;
}
