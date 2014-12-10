#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;
const int maxn = 2e5 + 10;
char buf[maxn];

void gao(char *str) {
	int len = strlen(str);
	int cnt0 = 0, cnt1 = 0, cntw = 0;
	for(int i = 0; i < len; i++) {
		if(str[i] == '0') cnt0++;
		if(str[i] == '1') cnt1++;
		if(str[i] == '?') cntw++;
	}
	if(cnt0 + cntw > cnt1) puts("00");
	if(cnt0 + cntw + 1 >= cnt1 && cnt1 + cntw >= cnt0) {
		if(str[len - 1] == '?') {
			//假设最后一位填1
			if(cnt0 + cntw >= cnt1 + 1 && cnt1 + cntw >= cnt0) puts("01");
			//假设最后一位填0
			if(cnt0 + cntw + 1 >= cnt1 && cnt1 + cntw - 1 >= cnt0 + 1) puts("10");

		}
		else if(str[len - 1] == '1') puts("01");
		else puts("10");
	}
	if(cnt1 + cntw > cnt0 + 1) puts("11");
}

int main() {
	while(scanf("%s", buf) != EOF) {
		gao(buf);
	}
	return 0;
}
