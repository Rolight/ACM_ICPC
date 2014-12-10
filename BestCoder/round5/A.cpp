#include <cstdio>
#include <algorithm>

using namespace std;
const int maxn = 3e5 + 10;
typedef long long LL;
int n;
LL val[maxn], ans = 0;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &val[i]);
	}
	sort(val, val + n);
	LL sum = 0;
	for (int i = 0; i < n; i++) sum += val[i];
	ans += sum;
	for (int i = 0; i < n - 1; i++) {
		ans += sum; sum -= val[i];
	}
	printf("%I64d\n", ans);
	return 0;
}s