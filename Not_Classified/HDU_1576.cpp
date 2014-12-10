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

void setfile() {
	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}

const int MOD = 9973;

void gcd(int a,int b,int &d,int &x,int &y) {
	if(b == 0) {
		d = a; x = 1;y = 0;
		return;
	}
	gcd(b,a % b,d,y,x); y -= x * (a / b);
}

int main() {
	int n,b,T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&b);
		int x1,y1,d;
		gcd(b,MOD,d,x1,y1);
		int x = x1 * n;
		while(x < 0) x += 9973;
		x %= 9973;
		printf("%d\n",x);
	}
	return 0;
}


