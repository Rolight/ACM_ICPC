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

typedef long long LL;

int main() {
	int n, tmp, ans = 0; 
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &tmp);
		ans ^= tmp;
	}
	if(ans == 0) puts("Bob");
	else puts("Alice");
	return 0;
}
