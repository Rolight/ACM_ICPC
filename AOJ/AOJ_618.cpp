#include <iostream>

using namespace std;
typedef long long LL;

int main() {
	LL n, k;
	while(cin >> n >> k) {
		LL ans = -1, l = 1, r = k;
		while(l <= r) {
			LL mid = l + r >> 1, val = (mid + k - 3) * (k - mid) / 2 + k;
			if(val >= n) {
				ans = k - mid + 1; l = mid + 1;
			}
			else r = mid - 1;
		}
		if(n == 1) ans = 0;
		cout << ans << endl;
	}
}

