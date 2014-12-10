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
char gene1[maxn],gene2[maxn];
int rela[5][5] = {5,-1,-2,-1,-3,
				  -1,5,-3,-2,-4,
				  -2,-3,5,-2,-2,
				  -1,-2,-2,5,-1,
				  -3,-4,-2,-1,0};

inline int mp(char c) {
	switch(c) {
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'T': return 3;
	}
	return 4;
}

inline int getval(char a,char b) {
	return rela[mp(a)][mp(b)];
}

int f[maxn][maxn];

int main() {
	int T; scanf("%d",&T);
	while(T--) {
		int len1,len2;
		scanf("%d%s%d%s",&len1,gene1 + 1,&len2,gene2 + 1);
		for(int i = 1;i <= len1;i++) f[i][0] = f[i - 1][0] + getval(gene1[i],'-');
		for(int i = 1;i <= len2;i++) f[0][i] = f[0][i - 1] + getval('-',gene2[i]);
		for(int i = 1;i <= len1;i++) {
			for(int j = 1;j <= len2;j++) {
				f[i][j] = -INF;
				f[i][j] = max(f[i][j - 1] + getval('-',gene2[j]), f[i][j]);
				f[i][j] = max(f[i][j], f[i - 1][j] + getval(gene1[i],'-'));
				f[i][j] = max(f[i][j], f[i - 1][j - 1] + getval(gene1[i],gene2[j]));
			}
		}
		printf("%d\n",f[len1][len2]);
	}
	return 0;
}


