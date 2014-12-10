#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v1, v2;

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		v1.clear();
		v2.clear();
		for(int i = 0; i < n; i++) {
			int tmp; scanf("%d", &tmp);
			v1.push_back(tmp);
		}
		for(int i = 0; i < n; i++) {
			int tmp; scanf("%d", &tmp);
			v2.push_back(tmp);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		v1.erase(unique(v1.begin(), v1.end()), v1.end());
		v2.erase(unique(v2.begin(), v2.end()), v2.end());
		bool bad = false;
		if(v1.size() != v2.size()) bad = true;
		for(int i = 0; i < v1.size(); i++) if(v1[i] != v2[i]) bad = true;
		if(bad) puts("NO");
		else puts("YES");
	}
	return 0;
}