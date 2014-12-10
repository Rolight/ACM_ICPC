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

const int maxn = 105;
int p[maxn];
double f[maxn];

int main() {
	int N,C,T,L,VR,VT1,VT2;
	while(~scanf("%d",&L)) {
		scanf("%d%d%d%d%d%d",&N,&C,&T,&VR,&VT1,&VT2);
		for(int i = 1;i <= N;i++) scanf("%d",&p[i]);
		memset(f,0,sizeof(f));
		double v1 = VT1,v2 = VT2,vr = VR;
		p[N + 1] = L; f[0] = -T;
		for(int i = 1;i <= N + 1;i++) {
			double mintime = (double)INF * INF;
			for(int j = i - 1;j >= 0;j--) {
				int dis = p[i] - p[j];
				double nowtime = 0;
				if(dis <= C) nowtime = dis / v1;
				else nowtime = C / v1 + (dis - C) / v2;
				mintime = min(mintime,nowtime + T + f[j]);
			}
			f[i] = mintime;
		}
		if(f[N + 1] > L / vr) puts("Good job,rabbit!");
		else puts("What a pity rabbit!");
	}
	return 0;
}


