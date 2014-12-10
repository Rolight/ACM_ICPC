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
const double PI = acos(-1);

void setfile() {
	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}

double x,l,d,y;

double f(double x) {
	return l * cos(x) - x / tan(x) + d / sin(x);
}

int main() {
	x = 10,y=  6,l = 13.5,d = 4;
	for(double i = 0;i <= PI / 2;i += PI / 90) {
		printf("%lf %lf\n",i / PI * 180,f(i));
	}
	return 0;
}


