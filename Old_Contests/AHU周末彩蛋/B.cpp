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
const int maxn = 1024;
int numa[maxn], numc[maxn], numb[maxn];

int to3(LL num, int *str) {
	int len = 0;
	while(num) {
		str[len++] = num % 3;
		num /= 3;
	}
	return len;
} 

int main() {
	int a, b, c;
	cin >> a >> c;
	int lena = to3(a, numa);
	int lenc = to3(c, numc);
	int lenb = max(lena, lenc);
	for(int i = 0; i < lenb; i++) {
		numb[i] = (numc[i] - numa[i]) % 3 + 3;
		numb[i] %= 3;
	}
	int ans = 0;
	for(int i = lenb - 1; i >= 0; i--) ans = ans * 3 + numb[i];
	cout << ans << endl;
	return 0;
}
