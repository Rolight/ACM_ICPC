#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100001;

int r[maxn],n,sum,left[maxn],right[maxn];

bool ok(int val) {
	right[0] = 0; left[0] = r[0];
	for(int i = 1;i < n;i++) {
		if(r[i] > val - left[i - 1] - right[i - 1]) return false;
		if((i + 1) % 2 == 0) {
			left[i] = min(r[i],r[0] - left[i - 1]);
			right[i] = r[i] - left[i];
		} else {
			right[i] = min(r[i],val - r[0] - right[i - 1]);
			left[i] = r[i] - right[i];
		}
	}
	return left[n - 1] == 0;
}

int bsearch() {
	int L = 1,R = sum;
	while(L < R) {
		int mid = (L + R) / 2;
		if(ok(mid)) R = mid;
		else L = mid + 1;
	}
	return L;
}

int main() {
	while(scanf("%d",&n),n) {
		sum = 0;
		for(int i = 0;i < n;i++) {
		   	scanf("%d",&r[i]);
			sum += r[i];
		}
		if(n % 2 == 1) printf("%d\n",bsearch());
		else {
			int maxd = 0;
			for(int i = 0;i < n;i++) {
				int f = ((i == 0) ? n - 1 : i - 1);
				maxd = max(maxd,r[i] + r[f]);
			}
			printf("%d\n",maxd);
		}
	}
	return 0;
}
