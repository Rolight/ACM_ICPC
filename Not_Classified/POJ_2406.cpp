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

const int maxn = 1000 * 1000 + 5;
char str[maxn];
int f[maxn];

int main() {
	while(scanf("%s",str),str[0] != '.') {
		int len = strlen(str);
		f[0] = f[1] = 0;
		for(int i = 2;i <= len;i++) {
			int j = f[i - 1];
			while(j && str[i - 1] != str[j]) j = f[j];
			if(str[i - 1] == str[j]) f[i] = j + 1;
			else f[i] = 0;
		}
		if(len % (len - f[len]) == 0) 
			printf("%d\n",len / (len - f[len]));
		else printf("1\n");
	}
	return 0;
}


