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

int main() {
	int a[3],b[3];
	while(scanf("%d%d%d",&a[0],&a[1],&a[2]),a[0]) {
		scanf("%d%d%d",&b[0],&b[1],&b[2]);
		sort(a,a + 3); sort(b,b + 3);
		if(a[0] >= b[0] && a[1] >= b[1] && a[2] >= b[2]) {
			puts("Yes");
		} else puts("No");
	}
	return 0;
}


