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

const int maxlen = 65;
const int maxn = 15;

char str[maxn][maxlen];
int f[maxlen];
int T,N,alen; 

void getf(char *str,int len) {
	f[0] = f[1] = 0;
	for(int i = 2;i <= len;i++) {
		int j = f[i - 1];
		while(j && str[i - 1] != str[j]) j = f[j];
		if(str[i - 1] == str[j]) f[i] = j + 1;
		else f[i] = 0;
	}
}

bool find(char *pat,char *t,int lenp,int lent) {
	getf(pat,lenp);
	int j = 0;
	for(int i = 0;i < lent;i++) {
		while(j && pat[j] != t[i]) j = f[j];
		if(pat[j] == t[i]) j++;
		if(j == lenp) return true;
	}
	return false;
}

bool ok(char *pat,int lenp) {
	for(int i = 1;i < N;i++) {
		if(find(pat,str[i],lenp,alen) == false) return false;
	}
	return true;
}

int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		for(int i = 0;i < N;i++) {
			scanf("%s",str[i]);
		}
		alen = strlen(str[0]);
		if(N == 1) {
			if(alen < 3) puts("no significant commonalities");
			else puts(str[0]);
			continue;
		}
		int nmax = 2,nstr = -1;
		for(int i = alen - 1;i >= 0;i--) { //Ã¶¾ÙÆðµã
			for(int nowlen = nmax;i + nowlen - 1 < alen;nowlen++) {
				if(ok(str[0] + i,nowlen)) {
					if(nowlen > nmax || (nowlen == nmax && nstr == -1)) {
						nmax = nowlen; nstr = i;
					}
					if(nowlen == nmax && str[0][i] < str[0][nstr]) {
						nmax = nowlen; nstr = i;
					}
				}
			}
		}
		if(nmax < 3) puts("no significant commonalities");
		else {
			for(int i = nstr;i < nstr + nmax;i++) {
				putchar(str[0][i]);
			}
			putchar('\n');
		}
	}
	return 0;
}


