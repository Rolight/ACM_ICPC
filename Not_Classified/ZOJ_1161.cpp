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


const int maxn = 2000;
int d[maxn],f[maxn],t[maxn],endt[maxn],n,h;
int st[maxn];
int ff[maxn][maxn];

int val(int i,int time) {
	if(time < 0) return INF;
	int last = f[i] - d[i] * (time - 1);
	int ret;
	if(last < 0) {
		ret =  (f[i] + f[i] % d[i]) * (f[i] / d[i] + 1) / 2;
	} else ret =  (f[i] + last) * time / 2;
	return ret;
}

void get_path(int now,int tt) {
	if(now == 0) return;
	int tarval = ff[now][tt];
	endt[now] = tt;
	for(int i = tt - t[now];i >= t[now - 1];i--) {
		if(tarval == ff[now - 1][i] + val(now,tt - i - t[now])) {
			get_path(now - 1,i); break;
		}
	}
}

int main() {
	bool first = true;
	int T = 1; scanf("%d",&T);
	while(T--) {
		if(first) first = false;
		else putchar('\n');
		bool first1 = true;
		while(scanf("%d",&n),n) {
			if(first1) first1 = false;
			else putchar('\n');
			int ans = 0,ansi = 1,anst = 0;
			scanf("%d",&h);
			h *= 12;
			memset(ff,0,sizeof(ff));
			memset(st,0,sizeof(st));
			for(int i = 1;i <= n;i++) scanf("%d",&f[i]);
			for(int i = 1;i <= n;i++) scanf("%d",&d[i]);
			for(int i = 2;i <= n;i++) scanf("%d",&t[i]);
			for(int i = 2;i <= n;i++) st[i] += st[i - 1] + t[i];
			for(int i = 1;i <= n;i++) {
				for(int tt = st[i];tt <= h;tt++) {
					ff[i][tt] = ff[i - 1][tt - t[i]];
					for(int dt = st[i];dt <= tt;dt++) {
						ff[i][tt] = max(ff[i][tt],ff[i - 1][dt - t[i]] + val(i,tt - dt));
					}
					if(ff[i][tt] > ans) {
						ans = ff[i][tt];
						ansi = i;
						anst = tt;
					}
				}
			}
			get_path(ansi,anst);
			int resth = h - anst;
			for(int i = 1;i <= n;i++) {
				if(i > 1) printf(", ");
				if(i > ansi) putchar('0');
				else printf("%d",(endt[i] - endt[i - 1] - t[i]) * 5 + (i == 1 ? resth : 0) * 5);
			}
			putchar('\n');
			printf("Number of fish expected: %d\n",ans);
		}
	}
	return 0;
}

