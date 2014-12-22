/*
ID: flsnnx1
LANG: C++
TASK: prefix
*/

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

const int maxn = 200000 + 5;
const int maxm = 10 + 5;
set<string> dict;
string S;
int dp[maxn];

int main() {
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	string tmp;
	while(cin >> tmp && tmp[0] != '.') dict.insert(tmp);
	while(cin >> tmp) S += tmp;
	//cout << S << endl;
	int len = S.size();
	int ans = -1;
	for(int i = 0;i < len;i++) {
		dp[i] = -INF;
		for(int j = 1;j <= 10;j++) {
			int r = i,l = i - j + 1;	
			if(l < 0) break;
			string now(S.begin() + l,S.begin() + r + 1);
			//cout << "now is " << now << endl;
			if(dict.count(now)) {
				if(i > 0) dp[i] = max(dp[l - 1] + 1,dp[i]);
				else dp[i] = 1;
			}
		}
		if(dp[i] > 0) ans = max(ans,i);
		//printf("%d\n",dp[i]);
	}
	cout << ans + 1 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


