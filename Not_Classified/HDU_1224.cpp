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
int d[maxn][maxn],w[maxn],val[maxn],prev[maxn];
int T,N,P;


void printpath(int now) {
	if(prev[now] == 0) return;
	printpath(prev[now]);
	printf("%d->",now);
}

int main() {
	scanf("%d",&T);
	for(int kase = 1;kase <= T;kase++) {
		scanf("%d",&N);
		memset(val,0,sizeof(val));
		for(int i = 1;i <= N;i++) {
			scanf("%d",&val[i]);
		}
		memset(d,-1,sizeof(d));
		memset(w,0,sizeof(w));
		scanf("%d",&P);
		for(int i = 1;i <= P;i++) {
			int a,b; scanf("%d%d",&a,&b);
			d[a][b] = 1;
		}
		for(int i = 1;i <= N + 1;i++) {
			w[i] = val[i]; int maxj = i,maxv = -INF;
			for(int j = 1;j < i;j++) {
				if(d[j][i] == 1 && w[j] > maxv) {
					maxj = j; maxv = w[j];
				}
			}
			if(maxv == -INF) {
				w[i] = val[i];
			} else {
				w[i] = val[i] + maxv;
				prev[i] = maxj;
			}
		}
		printf("CASE %d#\npoints : %d\ncircuit : 1->",kase,w[N + 1]);
		printpath(prev[N + 1]);
		putchar('1');
		putchar('\n');
		if(kase < T) putchar('\n');
	}
	return 0;
}


