#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
#include <climits>

using namespace std;

const int maxn = 16;
int w[maxn][maxn],N,S,f[maxn][1 << 16];

/*
int solve(int i) {
	int ret = INT_MAX;
	if(f[i][S] != -1) return f[i][S];
	if(S == 0) {
		return f[i][S] = w[1][i];
	}
	for(int j = 1;j <= N;j++) {
		if(S & (1 << j)) {
			S ^= (1 << j);
			ret = min(ret,solve(j) + w[i][j]);
			S |= (1 << j);
		}
	}
	return f[i][S] = ret;
}
*/

int solve(int i) {
	memset(f,0,sizeof(f));
	for(int j = 2;j <= N;j++) f[j][0] = w[1][j];
	for(int t = 1;t < N;t++) {
		
	}	
}

int main() {
	ios::sync_with_stdio(false);
	while(cin >> N && N) {
		S = 0;
		for(int i = 1;i <= N;i++) {
			for(int j = 1;j <= N;j++) {
				cin >> w[i][j];
			}
			if(i > 1) S |= (1 << i);
		}
		cout << solve(1) << endl;
	}
	return 0;
}
