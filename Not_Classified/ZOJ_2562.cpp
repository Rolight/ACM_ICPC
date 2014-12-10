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

int prime[20] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
int times[20];
LL ans,anscnt;

void dfs(LL curval,LL curcnt,int nowt,LL lim) {
	if(nowt >= 20) return;
	if(curcnt > anscnt) {
		anscnt = curcnt;
		ans = curval;
	}
	if(curcnt == anscnt) {
		ans = min(curval,ans);
	}
	for(int i = 1;i < 80;i++) {
		if(nowt == 0 || i <= times[nowt - 1]) {
			curval *= prime[nowt];
			curcnt = curcnt / i * (i + 1);
			times[nowt] = i;
			if(curval > lim) return;
			dfs(curval,curcnt,nowt + 1,lim);
		}
		else break;
	}
}


int main() {
	LL lim;
	while(cin >> lim) {
		memset(times,0,sizeof(times));
		ans = anscnt = 0;
		dfs(1,1,0,lim);
		cout << ans << endl;
	}
	return 0;
}


