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

const int maxw = 10000 + 5;
const int maxt = 1000000 + 5;
char w[maxw],t[maxt];
int f[maxw];

int main() {
	int T; scanf("%d",&T);
	while(T--) {
		scanf("%s%s",w,t);
		int lenw = strlen(w),lent = strlen(t);
		//getfail
		f[0] = f[1] = 0;
		for(int i = 2;i <= lenw;i++) {
			int j = f[i - 1];
			while(j && w[i - 1] != w[j]) j = f[j];
			if(w[i - 1] == w[j]) f[i] = j + 1;
			else f[i] = 0;
		}
		//count
		int ans = 0,j = 0;
		for(int i = 0;i < lent;i++) {
			while(j && t[i] != w[j]) j = f[j];
			if(t[i] == w[j]) j++;
			if(j == lenw) {
				j = f[j]; ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}


