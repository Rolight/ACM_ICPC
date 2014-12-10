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

const int maxn = 205;
char buf[maxn];
int cnt[26];

int main() {
	while(scanf("%s",buf) != EOF) {
		int len = strlen(buf);
		memset(cnt,0,sizeof(cnt));
		for(int i = 0;i < len;i++) {
			cnt[buf[i] - 'a'] = 1;
		}
		int sum = 0;
		for(int i = 0;i < 26;i++) sum += cnt[i];
		if(sum % 2 == 0) puts("CHAT WITH HER!");
		else puts("IGNORE HIM!");
	}
	return 0;
}


