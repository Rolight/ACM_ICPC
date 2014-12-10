#include <cstdio>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <cctype>
#include <ctime>
#include <set>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <string>
#include <list>

#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"

using namespace std;

typedef long long LL;
const int INF = INT_MAX / 2;
const double eps = 1e-9;

void setfile() {
	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}

double f(double H,double h,double D,double x) {
	return H - D / x * (H - h) + D - x;
}


//Èý·ÖËÑË÷
double tsearch(double H,double h,double D) {
	double l = D * (H - h) / H,r = D,mid,midr;
	while(fabs(l - r) > eps) {
		mid = (l + r) / 2;
		midr = (mid + r) / 2;
		if(f(H,h,D,mid) > f(H,h,D,midr)) {
			r = midr;
		} else l = mid;
	}
	return f(H,h,D,l);
}

int main() {
	int T; scanf("%d",&T);
	double H,h,D;
	for(int kase = 1;kase <= T;kase++) {
		scanf("%lf%lf%lf",&H,&h,&D);
		printf("%.3f\n",tsearch(H,h,D));
	}
	return 0;
}


