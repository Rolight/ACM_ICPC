/*
ID: flsnnx1
LANG: C++
TASK: shopping
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <set>

const int maxs = 1024;
const int maxc = 1000;
const int maxn = 4096;

int pcnt[maxs][maxc], price[maxs], ccnt;
int f[6][6][6][6][6];
int s, b, n, tmp[maxc], tmpp, c, k;
int bc[5], bk[5];
bool okp[maxs];
std::set<int> setc;

int main() {
	freopen("shopping.in", "r", stdin);
	freopen("shopping.out", "w", stdout);
	scanf("%d", &s);
	ccnt = 0;
	for(int i = 0; i < s; i++) {
		scanf("%d", &n);
		for(int j = 0; j < n; j++) {
			scanf("%d%d", &c, &k);
			pcnt[ccnt][c] = k;
		}
		scanf("%d", &price[ccnt]);
		ccnt++;
	}
	scanf("%d", &b);
	for(int i = 0; i < b; i++) {
		scanf("%d%d%d", &bc[i], &bk[i], &price[ccnt]);
		setc.insert(bc[i]);
		pcnt[ccnt][bc[i]] = 1;
		ccnt++;
	}
	for(int i = 0; i < ccnt; i++) {
		okp[i] = true;
		for(int j = 0; j < maxc; j++) if(pcnt[i][j] > 0) {
			if(setc.count(j) == 0) {
				okp[i] = false; break;
			}
		}
	}
	memset(f, 0x3f, sizeof(f));
	f[0][0][0][0][0] = 0;
	//dp
	for(int d1 = 0; d1 <= bk[0]; d1++) {
		for(int d2 = 0; d2 <= bk[1]; d2++) {
			for(int d3 = 0; d3 <= bk[2]; d3++) {
				for(int d4 = 0; d4 <= bk[3]; d4++) {
					for(int d5 = 0; d5 <= bk[4]; d5++) {
						int &now = f[d1][d2][d3][d4][d5];
						for(int i = 0; i < ccnt; i++) if(okp[i]) {
							if(d1 >= pcnt[i][bc[0]] && 
								d2 >= pcnt[i][bc[1]] &&
								d3 >= pcnt[i][bc[2]] &&
								d4 >= pcnt[i][bc[3]] &&
								d5 >= pcnt[i][bc[4]]
								) {
								now = std::min(now, 
										f[d1 - pcnt[i][bc[0]]][d2 - pcnt[i][bc[1]]][d3 - pcnt[i][bc[2]]][d4 - pcnt[i][bc[3]]][d5 - pcnt[i][bc[4]]] + price[i]);
							}

						}
					}
				}
			}
		}
	}
	printf("%d\n", f[bk[0]][bk[1]][bk[2]][bk[3]][bk[4]]);
	return 0;
}
