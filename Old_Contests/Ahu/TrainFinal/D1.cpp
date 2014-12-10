#include <cstdio>
#include <cstring>
#include <bitset>
#include <iostream>
#include <algorithm>
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

int mp[305][305];
bitset<305> val[18];
int n,m,ll;

bool operator < (bitset<305> a,bitset<305> b) {
	for(int i = 0;i < 301;i++) if(a[i] != b[i]) return a[i] < b[i];
	return false;
}

set<bitset<305> > tb;

int main() {
	while(scanf("%d%d",&n,&m) != EOF) {
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				scanf("%d",&mp[i][j]);
				val[i][j] = mp[i][j];
			}
		}
		int first = n / 2,last = n - n / 2;
		tb.clear();
		bitset<305> tmp;
		bitset<305> tar;
		tar.set();
		bool found = false;
		for(int i = 1;i <= (1 << first) - 1;i++) {
			bool ok = true;
			tmp.set(0);
			for(int k = 1;k <= first;k++) {
				if((1 << (k - 1)) & i) {
					ok = (tmp & val[k]).none();
				}
				if(!ok) break;
			}
			if(ok) {
				tmp = ~tmp;
				if(tmp == tar) {
					found = true; break;
				}
				tb.insert(tmp);
			}
		}
		for(int i = 1;i <= (1 << last) - 1;i++) {
			bool ok = true;
			tmp.set(0);
			for(int k = 1;k <= last;k++) {
				if((1 << (k - 1)) & i) {
					ok = (tmp & (val[k + first])).none();
				}
			}
			if(ok && tb.count(tmp)) {
				found = true;
				break;
			} else if(ok && tmp == tar) {
				found = true;
				break;
			}
		}
		if(found) puts("Yes, I found it");
		else puts("It is impossible");
	}
	return 0;
}


