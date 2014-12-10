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
//	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}

int main() {
 	setfile();
	int n = 100000,m = 100000;
	srand(time(NULL));
	printf("%d %d\n",n,m);
	for(int i = 0;i < m;i++) {
		int cmd = rand() % 4 + 1;
		int str = rand() % n + 1;
		int dd = rand() % (n - str) + 1;
		int end = str + dd;
		int vv = cmd == 4 ? rand() % 4 + 1 : rand() % 10000 + 1;
		printf("%d %d %d %d\n",cmd,str,end,vv);
		
	}
	printf("0 0\n");
	return 0;
}


