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
const int maxn = 80;

int n, p;
char buf[1024];
LL a[maxn][maxn], k[maxn][maxn], ans[maxn];

LL gcd(LL a, LL b) {
	return b == 0 ? a : gcd(b, a % b);
}

LL lcm(LL a, LL b) {
	return a / gcd(a, b) * b;
}

LL abs1(LL x) {
	return x < 0 ? -x : x;
}

//高斯消元
void Gauss() {
	int row, col;
	for(row = 0, col = 0; row < n && col < n; col++) {
		int kk = row;
		while(a[kk][col] == 0 && kk < n) kk++;
		if(kk >= n) continue;
		for(int i = 0; i <= n; i++) swap(a[row][i], a[kk][i]);
		for(int i = 0; i < n; i++) if(i != row && a[i][col] != 0) {
			LL lc = lcm(abs1(a[row][col]), abs1(a[i][col]));
			LL c1 = lc / a[row][col], c2 = lc / a[i][col];
			for(int j = 0; j <= n; j++) {
				a[i][j] = (a[i][j] * c2 - a[row][j] * c1) % p + p;
				a[i][j] %= p;
			}
		}
		row++;
	}
	for(int i = row - 1; i >= 0; i--) {
		LL right = a[i][n], left = a[i][i];
		for(int j = i + 1; j < n; j++) {
			right = (right - ans[j] * a[i][j]) % p + p;
			right %= p;
		}
		while(right % left != 0) right += p;
		ans[i] = right / left % p;
	}
}

void debug() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%s", &p, buf);
		n = strlen(buf);
		memset(k, 0, sizeof(k));
		memset(a, 0, sizeof(a));
		//预处理出所有的幂 
		for(int i = 1; i <= n; i++) {
			k[i][0] = 1;
			for(int j = 1; j < n; j++) {
				k[i][j] = (k[i][j - 1] * i) % p;
			}
		}
		//构建增广矩阵
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				a[i][j] = k[i + 1][j];
			}
			a[i][n] = buf[i] == '*' ? 0 : buf[i] - 'a' + 1;
		}
		//解方程
		Gauss();
		for(int i = 0; i < n - 1; i++) {
			cout << ans[i] << " ";
		}
		cout << ans[n - 1] << endl;
	}
	return 0;
}
