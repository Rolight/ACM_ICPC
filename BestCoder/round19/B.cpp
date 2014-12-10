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
typedef long long LL;
const LL INF = 2e18;
char str[16];
LL A, B, p10[18];

void gao() {
	int len = strlen(str);
	B = INF;
	LL S = 0;
	for(int i = 0; i < len; i++) S = S * 10 + str[i] - '0';
	int xl = str[0] == '0' ? 1 : 0;
	for(int i = xl; i <= 4; i++) {
		for(int j = 0; j < p10[4 - i]; j++) {
			for(int k = xl; k < p10[i]; k++) {
				LL T = k * p10[4 - i + len] + S * p10[4 - i] + j;
				if(T % A == 0) B = min(B, T / A);
			}
		}
	}
	printf("%I64d\n", B);
}

int main() {
	p10[0] = 1;
	for(int i = 1; i <= 18; i++) p10[i] = p10[i - 1] * 10;
	while(scanf("%I64d%s", &A, str) != EOF) gao();
	return 0;
}
