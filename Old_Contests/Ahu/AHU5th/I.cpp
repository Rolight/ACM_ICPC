#include <iostream>

using namespace std;
const int maxn = 105;

int main() {
	ios::sync_with_stdio(false);
	int T,n;
	cin >> T;
	while(T--) {
		int odd = -1,fodd = -1,codd = 0,cfodd = 0,tmp;
		cin >> n;
		for(int i = 0;i < n;i++) {
			cin >> tmp;
			if(tmp & 1) {
				if(odd == -1) odd = i + 1;
				codd++;
			} else {
				if(fodd == -1) fodd = i + 1;
				cfodd++;
			}
		}
		if(codd == 1) cout << odd << endl;
		else cout << fodd << endl;
	}
	return 0;
}
