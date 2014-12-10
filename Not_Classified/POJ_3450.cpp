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

const int maxn = 4000 + 5;
const int maxlen = 205;

char dict[maxn][maxlen];
char ans[maxlen];
int f[maxlen];

void getfail(char *str,int len) {
	f[0] = f[1] = 0;
	for(int i = 2;i <= len;i++) {
		int j = f[i - 1];
		while(j && str[j] != str[i - 1]) j = f[j];
		if(str[j] == str[i - 1]) f[i] = j + 1;
		else f[i] = 0;
	}
} 

bool find(char *pat,char *t,int lent,int lenp) {
	int j = 0;
	for(int i = 0;i < lent;i++) {
		while(j && t[i] != pat[j]) j = f[j];
		if(pat[j] == t[i]) j++;
		if(j == lenp) return true;
	}
	return false;
}

int main() {
	int n;
	while(scanf("%d",&n),n) {
		memset(ans,0,sizeof(ans));
		for(int i = 0;i < n;i++) scanf("%s",dict[i]);
		int mlen = strlen(dict[0]);
		int anslen = -1,ansi = 0;
		for(int len = mlen;len >= 1;len--) {
			if(len < anslen) continue;
			for(int pos = 0;pos + len <= mlen;pos++) {
				getfail(dict[0] + pos,len);
				bool ok = true;
				for(int i = 1;i < n;i++) {
					bool ret = find(dict[0] + pos,dict[i],strlen(dict[i]),len);
					if(ret == false) {
						ok = ret; break;
					}
				}
				if(ok && (len > anslen || (len == anslen && strncmp(ans,dict[0] + pos,len) > 0))) {
					anslen = len;ansi = pos;
					strncpy(ans,dict[0] + pos,len);
					ans[len] = 0;
				}
			}
		}
		if(anslen != -1) {
			puts(ans);
		} else {
			puts("IDENTITY LOST");
		}
	}
	return 0;
}


