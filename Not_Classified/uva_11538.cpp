#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long long n,m;
	while(cin >> n >> m,m || n) {
		if(m < n) swap(n,m);
		cout << n << " " << m << endl;
		cout << m * n * (m + n - 2) + 2 * n * (n - 1) * (2 * n - 4) / 3 + 2 * (m - n + 1) * n * (n - 1) << endl;
	}
	return 0;
}
