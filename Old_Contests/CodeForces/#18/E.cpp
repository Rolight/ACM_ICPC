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

const int maxn = 505;
const int sigma_size = 26;

int n,m;
int mat[maxn][maxn],tar[maxn][maxn],opt[maxn][maxn];
int f[maxn][sigma_size][sigma_size];

void get_tar(int now,int a,int b) {
	int cnt = 0;
	if(now == 0) return;

	for(int i = 1;i <= m;i++) {
		int nc = (i % 2 == 1) ? a : b;
		opt[now][i] = nc + 'a';
		if(nc != mat[now][i] - 'a') {
			cnt++;
		}
	}

	for(int i = 0;i < sigma_size;i++) {
		for(int j = 0;j < sigma_size;j++) {
			if(i == j || i == a || j == b) continue;
			if(f[now - 1][i][j] + cnt == f[now][a][b]) {
				get_tar(now - 1,i,j);
				return;
			}
		}
	}
} 


int main() {
	int ans = INF,ansa,ansb;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			scanf(" %c",&mat[i][j]);
		}
	}

	for(int i = 1;i <= n;i++) {
		for(int na = 0;na < sigma_size;na++) {
			for(int nb = 0;nb < sigma_size;nb++) {
				if(na == nb) continue;
				int minv = INF,cnt = 0;
				for(int pa = 0;pa < sigma_size;pa++) {
					for(int pb = 0;pb < sigma_size;pb++) {
						if(pa != pb && pa != na && pb != nb) {
							minv = min(minv,f[i - 1][pa][pb]);
						}
					}
				}
				for(int j = 1;j <= m;j++) {
					int now = (j % 2 == 1) ? na : nb;
					if(now != mat[i][j] - 'a') {
						cnt++;
					}
				}
				f[i][na][nb] = cnt + minv;
				if(i == n && cnt + minv < ans) {
					ans = cnt + minv;
					ansa = na;
					ansb = nb;
				}
			}
		}
	}

	printf("%d\n",ans);
	get_tar(n,ansa,ansb);
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			putchar(opt[i][j]);
		}
		putchar('\n');
	}
	return 0;
}

