#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1020;
int next[maxn],ww[maxn][maxn],w[maxn][maxn];
bool vis[maxn];

int main() {
	int T,n; scanf("%d",&T);
	while(T--) {
		memset(ww,-1,sizeof(ww));
		memset(w,-1,sizeof(w));
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for(int i = 0;i < n;i++) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			ww[a][b] = ww[b][a] = c;
			w[a][b] = c;
		}
		int r = 0,r1 = 0,pos = 1,count = 0;
		while(count < n && r != -1) {
			if(vis[pos]) {
				r = -1; break;
			}
			vis[pos] = true;
			int next = -1,ct = 0;
			for(int i = 1;i <= n;i++) {
				if(ww[pos][i] != -1 && (!vis[i] || (count == n - 1 && i == 1))) {
					if(next == -1) next = i;
					else if(ct == 2) {
						r = r1 = -1; break;
					}
					ct++;
				}
			}
			if(next == -1) {
				r = next; break;
			}
			if(r != -1) {
				if(w[pos][next] == -1) r += ww[pos][next];
				else r1 += ww[pos][next];
			}
			printf("%d %d\n",pos,next);
			pos = next;
			count++;
		}
		printf("%d\n",min(r,r1));
	}
	return 0;
}
