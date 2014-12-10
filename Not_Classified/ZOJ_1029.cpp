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

struct Line {
	int l,r;
	bool operator < (const Line &x) const {
		if(l != x.l) return l < x.l;
		return r < x.r;
	}
};

const int maxn = 205;
Line l[maxn];
bool f[maxn];

void swap(int &a,int &b) {
	int t = a; a = b; b = t;
}

int main() {
	int T; scanf("%d",&T);
	while(T--) {
		memset(f,0,sizeof(f));
		int N; scanf("%d",&N);
		int ans = 0;
		for(int i = 1;i <= N;i++) {
			scanf("%d%d",&l[i].l,&l[i].r);
			l[i].l = (l[i].l - 1) / 2;
			l[i].r = (l[i].r - 1) / 2;
			if(l[i].r < l[i].l) swap(l[i].l,l[i].r);
		}
		sort(l + 1,l + 1 + N);
		for(int i = 1;i <= N;i++) if(f[i] == false) {
			Line nowl = l[i];
			f[i] = true;
			for(int j = i + 1;j <= N;j++) if(f[j] == false) {
				if(l[j].l > nowl.r) {
					f[j] = true; nowl = l[j];
				}
			}
			ans++;
		}
		printf("%d\n",ans * 10);
	}
	return 0;
}


