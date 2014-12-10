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

const int maxn = 1000000 + 5;
char str[maxn];
int f[maxn];

void getFail(int len) {
	f[0] = f[1] = 0;
	for(int i = 2;i <= len;i++) {
		int j = f[i - 1];
		while(j && str[j] != str[i - 1]) j = f[j];
		if(str[i - 1] == str[j]) f[i] = j + 1;
		else f[i] = 0;
	}
}

int main() {
	int kase = 1,n;
	while(scanf("%d",&n),n) {
		scanf("%s",str);
		getFail(n);
		printf("Test case #%d\n",kase++);
		for(int i = 2;i <= n;i++) {
			if(i % (i - f[i]) == 0 && f[i] != 0) {
				printf("%d %d\n",i,i / (i - f[i]));
			}
		}
		putchar('\n');
	}
	return 0;
}


