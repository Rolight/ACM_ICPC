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
	freopen("in.txt","w",stdout);
	const int maxn = 300;
	int n = rand() % maxn + 1,m = rand() % maxn + 1;
	printf("%d %d\n",n,m);
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			printf("%d ",rand());
		}
		putchar('\n');
	}
	printf("\n800\n");
	for(int i = 1;i <= 800;i++) {
		int x = rand() % n + 1,y = rand() % m + 1;
		int dx = rand() % (n - x + 1) ,dy = rand() % (m - y + 1);
		printf("%d %d %d %d\n",x,y,x+dx,y+dy);
	}
	fclose(stdout);
	return 0;
}


