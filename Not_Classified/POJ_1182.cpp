#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 50001;
int p[maxn],r[maxn];
int rela[3][3] = {0,1,2,1,2,0,2,0,1};

int findset(int i) {
	if(i == p[i]) return i;
	int root = findset(p[i]);
	r[i] = rela[r[i]][r[p[i]]];
	return p[i] = root;
}

int main() {
	int n,k,c,a,b;
	scanf("%d%d",&n,&k);
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		p[i] = i; r[i] = 0;
	}
	for(int i = 0;i < k;i++) {
		scanf("%d%d%d",&c,&a,&b);
		if(a > n || b > n) {
			ans++; continue;
		}
		int x = findset(a),y = findset(b);
		if(c == 1) {
			if(x == y && r[a] != r[b]) ans++;
			else if(x != y) {
				p[a] = b; r[x] = 0;
				findset(a);
			}
		} else {
			if(x == y && r[a] != (r[b] + 1) % 3) ans++;
			else if(x != y) {
				p[a] = b; r[a] = 1;
				findset(a);
			}
		}
		/*
		for(int j = 1;j <= 10;j++) printf("%4d",j); putchar('\n');
		for(int j = 1;j <= 10;j++) printf("%4d",p[j]); putchar('\n');
		for(int j = 1;j <= 10;j++) printf("%4d",r[j]); putchar('\n');
		*/
	}
	printf("%d\n",ans);
	return 0;
}
