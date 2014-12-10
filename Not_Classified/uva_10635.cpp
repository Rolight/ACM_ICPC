#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 250 * 250 + 5;
int g[maxn],num[maxn],a[maxn];

int bsearch(int arr[],int l,int r,int v) {
	while(l < r) {
		int mid = (l + r) / 2;
		if(arr[mid] < v) l = mid + 1;
		else r = mid;
	}
	return l;
}

int LIS(int arr[],int n) {
	int ret = 0;
	memset(g,7,sizeof(g));
	for(int i = 1;i <= n;i++) {
		int k = bsearch(g,1,i,arr[i]);
		g[k] = arr[i];
		ret = max(ret,k);
	}
	return ret;
}

int main() {
	int n,p,q,T,tmp;
	scanf("%d",&T);
	for(int kase = 1;kase <= T;kase++) {
		scanf("%d%d%d",&n,&p,&q);
		memset(num,0,sizeof(num));
		for(int i = 1;i <= p + 1;i++) {
			scanf("%d",&tmp); num[tmp] = i;
		}
		int pos = 0;
		for(int i = 1;i <= q + 1;i++) {
			scanf("%d",&tmp);
			if(num[tmp]) a[++pos] = num[tmp];
		}
		printf("Case %d: %d\n",kase,LIS(a,pos));
	}
	return 0;
}
