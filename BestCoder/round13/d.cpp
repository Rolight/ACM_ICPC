#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = (1 << 22) + 10;
int M, n, a[maxn], aid[maxn];
int b[maxn], bcnt, topp[maxn], k;

int binary_search(int x)
{
	int l = 0, r = k, mid;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (topp[mid] >= x) r = mid - 1;
		else //temp[mid]<x
		{
			l = mid;
			if (topp[l + 1] >= x)return l + 1;
			else l++;
		}
	}
}//找到序列中不大于x的最大的数，正因为二分查找才使得复杂度变身为n*log（n） 

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		bcnt = 0;
		scanf("%d%d", &n, &M);
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++) {
			scanf("%d", &aid[i]);
			a[aid[i]]++;
			topp[i] = 1e9;
		}
		topp[0] = -100;
		int maxcha = -1, lastval = -1, ans = 0;
		for (int i = 0; i <= M; i++) if(a[i]) {
			if (lastval == -1) lastval = i;
			b[++bcnt] = i - lastval;
			lastval = i;
		}
		int k = 0; topp[0] = b[1];
		for (int i = 1; i <= bcnt; i++) {
			if (b[i] > topp[k]) topp[++k] = b[i];
			else {
				if (b[i] <= topp[0]) topp[0] = b[i];
				else {
					topp[binary_search(b[i])] = b[i];
				}
			}
		}
		printf("%d\n", k + 1);
	}
	return 0;
}