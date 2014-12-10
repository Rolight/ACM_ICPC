#include <iostream>
#include <algorithm>

#define dv(x) ((x)>>1)

using namespace std;

const int maxn = 1000001;
long long f[maxn];

int main() {
	for(long long i = 4;i <= maxn;i++) {
		f[i] = f[i - 1] + dv((i - 1) * (i - 2)) - dv((dv(i * (i - 1)) - dv(i)));
	}
	int n;
	while(cin >> n,n >= 3) {
		cout << f[n] << endl;
	}
	return 0;
}
