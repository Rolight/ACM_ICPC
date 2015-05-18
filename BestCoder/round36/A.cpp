#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>

using namespace std;
 
typedef long long LL;
const int maxn = 256;
char str[maxn];
int id[maxn], cnt[maxn];
char cid[maxn];

int main() {
	while(scanf("%s", str) != EOF) {
		int len = strlen(str);
		memset(id, 0, sizeof(id));
		memset(cnt, 0, sizeof(cnt));
		for(int i = 1; i < len; i++) {
			if(str[i] == str[i - 1]) id[i] = id[i - 1];
			else id[i] = id[i - 1] + 1;
		}
		if(id[len - 1] == 2) {
			for(int i = 0; i < len; i++) {
				cid[id[i]] = str[i];
				cnt[id[i]]++;
			}
			if(cid[0] != cid[1] && cid[0] != cid[2] && cid[1] != cid[2]
					&& cnt[0] == cnt[1] && cnt[1] == cnt[2]) puts("YES");
			else puts("NO");
		}
		else puts("NO");
	}
	return 0;
}
