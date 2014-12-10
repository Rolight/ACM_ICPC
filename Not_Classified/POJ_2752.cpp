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

const int maxn = 400000 + 5;
char a[maxn];
int fa[maxn];
vector<int> ans;

void getfail(int f[],char str[],int len) {
	f[0] = f[1] = 0;
	for(int i = 2;i <= len;i++) {
		int j = f[i - 1];
		while(j && str[j] != str[i - 1]) j = f[j];
		if(str[j] == str[i - 1]) f[i] = j + 1;
		else f[i] = 0;
	}
}

int main() {
	while(~scanf("%s",a)) {
		int len = strlen(a);
		getfail(fa,a,len);
		ans.clear();
		ans.push_back(len);
		int j = fa[len];
		while(j) {
			ans.push_back(j);
			j = fa[j];
		}
		for(int i = ans.size() - 1;i >= 0;i--) printf("%d ",ans[i]);
		putchar('\n');
	}
	return 0;
}


