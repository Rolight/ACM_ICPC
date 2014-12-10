/*
ID: flsnnx1
LANG: C++
TASK: nocows
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

#define INPUT_FILE "nocows.in"
#define OUTPUT_FILE "nocows.out"

using namespace std;

typedef long long LL;
const int INF = INT_MAX / 2;

void setfile() {
	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}

const int maxn = 205;
const int maxk = 105;
const int MOD = 9901;
int dp[maxn][maxk];

int main() {
	setfile();
	int N,K;
	cin >> N >> K;
	for(int i = 1;i <= K;i++) dp[1][i] = 1;
	for(int i = 3;i <= N;i++) {
		for(int j = 2;j <= K;j++) {
			for(int k = 1;k < i - 1;k++) {
				LL adc = (dp[k][j - 1] % MOD) * (dp[i - 1 - k][j - 1]) % MOD;
				dp[i][j] += adc % MOD;
				dp[i][j] %= MOD;
			}
		}
	}
	cout << (dp[N][K] - dp[N][K - 1] + MOD) % 9901 << endl;
	return 0;
}


