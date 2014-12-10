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

struct Skill {
	int power,cost;
	bool operator < (const Skill &x) const {
		if(cost == x.cost) return power < x.power;
		else return cost < x.cost;
	}
};

const int maxn = 205;
const int maxnt = 5;
int n,t,q,f[maxn][maxn];
Skill skill[maxn];


int main() {
	while(scanf("%d%d%d",&n,&t,&q),n) {
		memset(f,0,sizeof(f));
		memset(skill,0,sizeof(skill));
		skill[0].power = 1; skill[0].cost = 0;
		for(int i = 1;i <= n;i++) {
			scanf("%d%d",&skill[i].cost,&skill[i].power);
		}
		//sort(skill,skill + n + 1);
		int deadtime = (100 % q == 0) ? (100 / q) : ((100 / q) + 1);
		int ans = -1;
		for(int i = 1;i <= deadtime;i++) {
			for(int j = 0;j <= 100 + (i - 1) * t;j++) {
				int maxv = -INF;
				for(int k = 0;k <= n;k++) {
					if(j >= skill[k].cost) {
						maxv = max(maxv,f[i - 1][j - skill[k].cost] + skill[k].power);
					} //else break;
				}
				f[i][j] = maxv;
				if(f[i][j] >= 100) {
					ans = i; break;
				}
			}
			if(ans != -1) break;
		}
		if(ans != -1) printf("%d\n",ans);
		else puts("My god");
	}
	return 0;
}


