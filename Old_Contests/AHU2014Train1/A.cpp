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
const int INF = INT_MAX / 3;

void setfile() {
	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}

const int maxn = 500;
int len;
char buf[maxn];
char str[maxn];
int f[maxn][maxn];

void print_ans(int l,int r) {
	str[l * 3] = buf[l]; str[r * 3] = buf[r];
	if(l == r) {
		str[l * 3] = buf[l];
		if(buf[l] == '(') str[l * 3 + 1] = ')';
		if(buf[r] == ')') str[l * 3 - 1] = '(';
		if(buf[l] == '[') str[l * 3 + 1] = ']';
		if(buf[r] == ']') str[l * 3 - 1] = '[';
	} else {
		if(r == l + 1) {
			if(f[l][r] != 0) {
				print_ans(l,l);
				print_ans(r,r);
			}
		} else {
			if(((buf[l] == '(' && buf[r] == ')') || (buf[l] == '[' && buf[r] == ']'))
					&& f[l][r] == f[l + 1][r - 1]) {
				print_ans(l + 1,r - 1);
			} else {
				for(int m = l;m <= r;m++) {
					if(f[l][r] == f[l][m] + f[m + 1][r]) {
						print_ans(l,m);
						print_ans(m + 1,r);
						break;
					}
				}
			}
		}
	}
}

int main() {
	scanf("%s",buf + 1);
	len = strlen(buf + 1);
	memset(f,0,sizeof(f));
	memset(str,0,sizeof(str));
	for(int i = 1;i <= len;i++) f[i][i] = 1;
	for(int i = 1;i < len;i++) {
		if(buf[i] == '(' && buf[i + 1] == ')') f[i][i + 1] = 0;
		else if(buf[i] == '[' && buf[i + 1] == ']') f[i][i + 1] = 0;
		else f[i][i + 1] = 2;
	}
	for(int i = 2;i <= len;i++) {
		for(int l = 1;l + i <= len;l++) {
			int r = l + i;
			f[l][r] = INF;
			if(buf[l] == '(' && buf[r] == ')') f[l][r] = f[l + 1][r - 1];
			if(buf[l] == '[' && buf[r] == ']') f[l][r] = f[l + 1][r - 1];
			for(int m = l;m <= r;m++) {
				f[l][r] = min(f[l][r],f[l][m] + f[m + 1][r]);
			}
		}
	}
	print_ans(1,len);
	for(int i = 0;i <= len * 3 + 3;i++) {
		if(str[i] != 0) putchar(str[i]);
	}
	putchar('\n');
	return 0;
}
