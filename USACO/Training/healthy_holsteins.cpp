
/*
ID: flsnnx1
LANG: C++
TASK: holstein
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>

using namespace std;

const int maxv = 26;
const int maxg = 16;

int v[maxv],g[maxg][maxv];

int main() {
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	int nv,ng;
	scanf("%d",&nv);
	for(int i = 0;i < nv;i++) scanf("%d",&v[i]);
	scanf("%d",&ng);
	for(int i = 0;i < ng;i++) {
		for(int j = 0;j < nv;j++) {
			scanf("%d",&g[i][j]);
		}
	}
	int ansstate,minval = INT_MAX / 2;
	for(int state = 1;state < (1 << ng);state++) {
		int cnt[maxv],bcnt = 0;
		memset(cnt,0,sizeof(cnt));
		for(int i = 0;i < ng;i++) {
			if((1 << i) & state) {
				for(int j = 0;j < nv;j++) {
					cnt[j] += g[i][j];
				}
				bcnt++;
			}
		}
		bool ok = true;
		for(int i = 0;i < nv;i++) {
			if(cnt[i] < v[i]) {
				ok = false; break;
			}
		}
		if(ok && bcnt < minval) {
			minval = bcnt;
			ansstate = state;
		}
	}
	printf("%d",minval);
	for(int i = 0;i < ng;i++) {
		if((1 << i) & ansstate) {
			printf(" %d",i + 1);
		}
	}
	putchar('\n');
	fclose(stdin);
	fclose(stdout);
	return 0;
}

