#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <ctime>
#include <cstdlib>

typedef long long ll;
const int n = 5e4;

ll longrand() {
    return
        ((ll)rand() << 34) |
        ((ll)rand() << 19) |
        ((ll)rand() << 4)  |
        (rand() & 15);
}

int main() {
	freopen("lala.in", "w", stdout);
	int T = 1000;
	printf("%d\n", T);
	while(T--) {
		printf("%d\n", n);
		for(int i = 1; i <= n; i++) {
			printf("%I64d ", longrand() % (1LL << 29));
		}
		puts("");
	}
	return 0;
}
