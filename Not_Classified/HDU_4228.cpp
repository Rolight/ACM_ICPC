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

typedef unsigned long long LL;
const int INF = INT_MAX / 2;
const LL maxval = 1e18 + 1;
const int maxn = 75 + 5;
const int maxcnt = 160;
LL cnt[maxn * 2];
int prime[20] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
int times[20];

void dfs(LL curnum,LL curcnt,int nowt) {
	if(curnum > maxval) return;
	if(curcnt <= maxcnt) {
		cnt[curcnt] = min(cnt[curcnt],curnum);
	}
	for(int i = 1;i <= maxcnt;i++) {
		if(nowt == 0 || i <= times[nowt - 1]) {
			curnum *= prime[nowt]; 
			if(curnum > maxval) break;
			curcnt = curcnt / i * (i + 1);
			times[nowt] = i;
			dfs(curnum,curcnt,nowt + 1);
		}
		else break;
	}
}

int main() {
	for(int i = 1;i <= maxcnt;i++) cnt[i] = maxval;
	dfs(1,1,0);
	int N;
	while(cin >> N,N) {
		LL a1 = cnt[N * 2 - 1],a2 = cnt[N * 2],sa = sqrt(a1);
		if(sa * sa == a1 && a1 < a2) cout << a1 << endl;
		else cout << a2 << endl;
	}
	return 0;
}


