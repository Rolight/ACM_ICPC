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

struct Segment {
	int l,r,id;
	bool operator < (const Segment &x) const {
		if(r != x.r) return r < x.r;
		return l < x.l;
	}
};

const int maxn = 1005;
Segment s[maxn];

int main() {
	int n;
	while(~scanf("%d",&n),n) {
		int ans = 0;
		for(int i = 1;i <= n;i++) {
			scanf("%d%d",&s[i].l,&s[i].r);
			s[i].id = i;
		}
		sort(s + 1,s + 1 + n);
		int nowr = -INF;
		for(int i = 1;i <= n;i++) {
			if(s[i].l > nowr) {
				if(nowr != -INF) putchar(' ');
				printf("%d",s[i].id);
				nowr = s[i].r;
			}
		}
		putchar('\n');
	}
	return 0;
}


