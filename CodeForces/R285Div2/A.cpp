#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <string>

using namespace std;

int calc(int p, int t) {
	return max(3 * p / 10, p - p / 250 * t);
}

int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int sc1 = calc(a, c), sc2 = calc(b, d);
	if(sc1 == sc2) {
		puts("Tie"); return 0;
	}
	printf("%s\n", sc1 > sc2 ? "Misha" : "Vasya");
	return 0;
}

