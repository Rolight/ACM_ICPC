#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100001;
int fa[maxn],n,vis[maxn];

void set_union(int f,int s) {
	if(fa[s] == 0) fa[s] = f;
	else {
		set_union(f,fa[s]);
		fa[s] = f;
	}
}

int query(int c) {
	if(fa[c] != 0) return fa[c] = query(fa[c]);
	else return c;
}

int main() {
	int a,b,max = -1;
	bool ok = true;
	while(scanf("%d%d",&a,&b),a != -1) {
		if(a == 0 && b == 0) {
			bool has = false;
			if(!ok) puts("No");
			else {
				for(int i = 1;i <= max;i++) if(vis[i]) {
					if(query(i) == i) {
						if(has) {
							ok = false; break;
						} else has = true;
					}
				}
				if(ok) puts("Yes");
				else puts("No");
			}
			memset(fa,0,sizeof(fa));
			memset(vis,0,sizeof(vis));
			ok = true;
		} else if(ok) {
			vis[a] = vis[b] = 1;
			if(a > max) max = a;
			if(b > max) max = b;
			if(b == query(a) || a == query(b)) ok = false;
			else set_union(a,b);
		} 
	}
	return 0;
}
