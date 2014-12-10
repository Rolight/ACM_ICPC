#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1005;

char mat[maxn][maxn];
int h[maxn],*ph[maxn];

void quicksort(int s,int e) {
	if(s >= e) return;
	int i = s,j = e,mid = (s + e) / 2,std = *ph[mid];
	while(1) {
		while(*ph[i] < std) i++;
		while(*ph[j] > std) j--;
		if(i < j) {
			int *t = ph[i]; ph[i] = ph[j]; ph[j] = t;
		} else break;
		i++; j--;
	}
	quicksort(s,i - 1);
	quicksort(j + 1,e);
}

int solve(int n,int m) {
	memset(h,0,sizeof(h));
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(mat[i][j] == '1') h[j]++;
			else h[j] = 0;
			ph[j] = h + j;
		}
		quicksort(1,m);
		for(int j = m;j >= 1;j--) {
			ans = max(ans,(m - j + 1) * (*ph[j]));
		}
	}
	return ans;
}

int main() {
	int n,m;
	while(~scanf("%d%d",&n,&m)) {
		for(int i = 1;i <= n;i++) scanf("%s",mat[i] + 1);
		printf("%d\n",solve(n,m));
	}
	return 0;
}
