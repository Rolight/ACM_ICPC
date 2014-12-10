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

int cnt[30];
char a[1005],b[1005];

int main() {
	int ans = 0;
	scanf("%s%s",a,b);
	int lena = strlen(a),lenb = strlen(b);
	for(int i = 0;i < lena;i++) cnt[a[i] - 'a']++;
	for(int i = 0;i < lenb;i++) {
		if(cnt[b[i] - 'a'] == 0) {
			printf("-1\n"); return 0;
		}
	}
	for(int i = 0;i < lenb;i++) {
		if(cnt[b[i] - 'a'] > 0) {
			cnt[b[i] - 'a']--; ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}


