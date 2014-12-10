#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 2005;
typedef long long LL;
LL num[maxn][maxn];
LL sum1[maxn][maxn], sum2[maxn][maxn], sum3[maxn][maxn], sum4[maxn][maxn];
LL sum[maxn * 8], xx[maxn * 8], yy[maxn * 8];
LL ans;
int n,x1,y1,x2,y2;

int main() {
	ans = -1;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			scanf("%I64d",&num[i][j]);
			sum1[i][j] = sum1[i - 1][j - 1] + num[i][j];
			sum2[i][j] = sum2[i - 1][j + 1] + num[i][j];
		}
	}
	for(int i = n;i >= 1;i--) {
		for(int j = n;j >= 1;j--) {
			sum3[i][j] = sum3[i + 1][j - 1] + num[i][j];
			sum4[i][j] = sum4[i + 1][j + 1] + num[i][j];
		}
	}
	
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			LL cnt1 = sum1[i][j] + sum2[i][j] + sum3[i][j] + sum4[i][j] - 3 * num[i][j];
			if(cnt1 >= sum[i + j]) {
				sum[i + j] = cnt1;
				xx[i + j] = i; yy[i + j] = j;
			}
		}
	}
	
	for(int i = 2;i <= n + n;i++) {
		for(int j = i + 1;j <= n + n;j += 2) {
			LL nowc = sum[i] + sum[j];
			if(nowc > ans) {
				ans = nowc;
				x1 = xx[i]; y1 = yy[i];
				x2 = xx[j]; y2 = yy[j];
			}
		}
	}
	cout << ans << endl;
	cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	return 0;
}
