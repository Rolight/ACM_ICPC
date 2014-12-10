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

void gcd(LL a,LL b,LL &d,LL &x,LL &y) {
	if(b == 0) {
		d = a; x = 1; y = 0;
	} else {
		gcd(b,a % b,d,y,x); y -= x * (a / b);
	}
}

void swap(LL &a,LL &b) {
	LL tmp = a; a = b; b = tmp;
}

int main() {
	 LL x,y,n,m,L;
	 while(cin >> x >> y >> m >> n >> L) {
		 LL d,xx,yy,t;
		 if(n < m) {
			 swap(n,m); swap(x,y);
		 }
		 gcd(n - m,L,d,xx,yy);
		 if((x - y) % d != 0) puts("Impossible");
		 else {
			 t = (x - y) / d * xx;
			 while(t < 0) t += L / d;
			 t %= (L / d);
			 cout << t << endl;
		 }
	 }
	 return 0;
}


