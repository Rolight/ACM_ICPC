#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
double a, b, c, d;

int main() {
	while(scanf("%lf%lf%lf%lf", &a, &b, &c, &d) != EOF) {
		a = b * log(a);
		c = d * log(c);
		double cmp = a - c;
		if(fabs(cmp) < 1e-7) puts("=");
		else if(cmp < 0) puts("<");
		else puts(">");
	}
	return 0;
}
