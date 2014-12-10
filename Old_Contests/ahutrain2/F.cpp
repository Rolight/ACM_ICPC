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

const int maxn = 155;
struct Node {
	int cnt,cc,ch[maxn],p,id;
	bool operator < (const Node &x) const {
		return cnt < x.cnt;
	}
};

Node node[maxn];
int f[maxn][maxn];

int main() {
	int N,P;
	while(scanf("%d%d",&N,&P) != EOF) {
		memset(node,0,sizeof(node));
		for(int i = 0;i < N - 1;i++) {
			int a,b; scanf("%d%d",&a,&b);
			node[a - 1].ch[node[a - 1].cnt++] = b - 1;
			node[b - 1].p = a - 1;
		}
		for(int i = 0;i < N;i++) {
			node[i].id = i+1;
		}

		sort(node,node + N);
		for(int i = 0;i < N;i++) {
			node[i].cc = 1;
			for(int j = 0;j < node[i].cnt;j++) {
				node[i].cc += node[node[i].ch[j]].cc;
			}
		}

		for(int i = 0;i < N;i++) {
			for(int j = 0;j <= P;j++) {
				f[i][j] = INF;
			}
		}

		for(int i = 0;i < N;i++) {
			f[i][1] = 0;
			if(node[i].cnt == 0) {
				f[i][0] = 1;
			} else {
				for(int k = 0;k < node[i].cnt;k++) {
					int chid = node[i].ch[k];
					for(int j = P - 1;j >= 0;j--) {
						for(int kk = 0;kk <= node[chid].cc && kk <= j;kk++) {
							int ret = f[i][j + 1 - kk] + f[chid][kk];
							f[i][j + 1] = min(f[i][j + 1],ret);
						}
						printf("%d %d %d %d\n",node[i].id,j,k,f[i][j]);
					}
				}
			}
		}
		printf("%d\n",f[N][P]);
	}
	return 0;
}


