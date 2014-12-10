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

const int maxlen = 205;
char A[maxlen],B[maxlen],C[maxlen << 1];
char outstring[2][5] = {"no","yes"};
int lena,lenb;
int note[maxlen][maxlen];

int dfs(int posa,int posb) {
	int posc = posa + posb;
	if(posa == lena && posb == lenb) return 1;
	if(~note[posa][posb]) return note[posa][posb];
	int ret = 0;
	if(C[posc] == A[posa]) {
		ret |= dfs(posa + 1,posb);
	}
	if(ret) return ret;
	if(C[posc] == B[posb]) {
		ret |= dfs(posa,posb + 1);
	}
	return note[posa][posb] = ret;
}

int main() {
	int n; scanf("%d",&n);
	for(int kase = 1;kase <= n;kase++) {
		memset(note,-1,sizeof(note));
		scanf("%s%s%s",A,B,C);	
		lena = strlen(A);
		lenb = strlen(B);
		printf("Data set %d: %s\n",kase,outstring[dfs(0,0)]);
	}
	return 0;
}


