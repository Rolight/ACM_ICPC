#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;
const int maxn = 30;

int a[maxn][maxn], fid[maxn], fcnt;

void Gauss() {
	for(int i = 0; i < 20; i++) {
		int k = i;
		while(a[k][i] == 0 && k < 20) k++;
		if(k >= 20) continue;
		for(int j = 0; j <= 20; j++) swap(a[i][j], a[k][j]);
		for(int j = 0; j < 20; j++) if(i != j && a[j][i] != 0) {
			for(int k = 0; k <= 20; k++) a[j][k] ^= a[i][k];
		}
	}
}

void pa() {
	for(int i = 0; i < 20; i++) {
		for(int j = 0; j <= 20; j++) {
			printf("%d ", a[i][j]);
		}
		puts("");
	}
}

int main() {
	while(1) {
		memset(a, 0, sizeof(a));
		for(int i = 0; i < 20; i++) {
			int ret = scanf("%d", &a[i][20]);
			if(ret == EOF) return 0;
		}
		for(int i = 0; i < 20; i++) {
			a[i][i] = a[i][max(i - 1, 0)] = a[i][min(i + 1, 19)] = 1;
		}
		Gauss();
		fcnt = 0;
		memset(fid, -1, sizeof(fid));
		for(int i = 0; i < 20; i++) {
			int nowsum = 0;
			for(int j = 0; j <= 20; j++) nowsum += a[i][j];
			if(nowsum == 0) fid[i] = fcnt++;
		}
		int ans = 1e9;
		for(int i = 0; i < (1 << fcnt); i++) {
			int nowans = 0;
			for(int j = 0; j < 20; j++) {
				int nows = 0;
				for(int k = 0; k < 20; k++) if(fid[k] != -1 && a[j][k]) {
					if((1 << fid[k]) & i) nows ^= 1;
				} 
				if(nows != a[j][20]) nowans++;
			}
			int bcnt = 0;
			for(int j = 0; j < fcnt; j++) if(i & (1 << j)) bcnt++;
			ans = min(ans, nowans + bcnt);
		}
		printf("%d\n", ans);
	}
	return 0;
}
