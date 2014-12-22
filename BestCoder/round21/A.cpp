#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int p[5] = {1, 2, 4, 7, 15};

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		int t = 0;
		for(int i = 4; i >= 0; i--) {
			if(n - p[i] >= 1) {
				if(t != 0) putchar(' ');
				printf("%d", n - p[i]), t = 1;
			}
		}
		puts("");
	}
	return 0;
}
