#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1010;
int p[maxn];
bool h[maxn];

void set(int son,int dad) {
	p[son] = dad;
}

int find(int now) {
	if(p[now]) return p[now] = find(p[now]);
	else return now;
}

bool istree(int n) {
	int root = -1;
	for(int i = 1;i <= n;i++) if(h[i]) {
		int ret = find(i);
		if(root == -1) root = ret;
		else if(root != ret) return false;
	}
	return true;
}

int main() {
	int c = 1,a,b,max = -1;
	bool ok = true;
	while(1) {
		scanf("%d%d",&a,&b);
		h[a] = h[b] = true;
		if(a > max) max = a;
		if(b > max) max = b;
		if(a == -1 || b == -1) break;
		if(p[b]) ok = false;
		if(a || b) set(b,a);
		else {
			bool ret = istree(max);
			printf("Case %d is %s\n",c,(ret && ok)?"a tree.":"not a tree.");
			c++;
			max = -1;
			memset(p,0,sizeof(p));
			memset(h,0,sizeof(h));
			ok = true;
		}
	}
	return 0;
}
