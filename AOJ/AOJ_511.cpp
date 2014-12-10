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

struct Plank {
	int w,l;
};

bool cmp(Plank a,Plank b) {
	bool ret;
	if(a.w != b.w) return a.w < b.w;
	else return a.l < b.l;
}

const int maxn = 5005;
Plank pp[maxn];
bool f[maxn];

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int N,ans = 0; scanf("%d",&N);
		memset(f,0,sizeof(f));
		for(int i = 1;i <= N;i++) {
			scanf("%d%d",&pp[i].w,&pp[i].l);
		}
		sort(pp + 1,pp + 1 + N,cmp);
		for(int i = 1;i <= N;i++) {
			Plank nowpp = pp[i];
			if(f[i] == false) {
				f[i] = true;
				for(int j = i + 1;j <= N;j++) {
					if(f[j] == false && pp[j].w >= nowpp.w && pp[j].l >= nowpp.l) {
						nowpp = pp[j]; f[j] = true;
					}
				}
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
