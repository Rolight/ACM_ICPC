#include <iostream>

using namespace std;
const int maxn = 1000;
int ti[maxn];

int main() {
	ios::sync_with_stdio(false);
	int T,n,a,b;
	cin >> T;
	while(T--) {
		int ans = 0;
		cin >> n;
		for(int i = 1;i < n;i++) cin >> ti[i];
		cin >> a >> b;
		for(int i = a;i < b;i++) ans += ti[i];
		cout << ans << endl;
	}
	return 0;
}
