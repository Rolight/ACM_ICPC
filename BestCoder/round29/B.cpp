#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;

const LL mod = 10000007;
const int maxn = 32;

struct Matrix {
    int n, m;
    LL data[maxn][maxn];
    Matrix(int n = 0, int m = 0): n(n), m(m) {
        memset(data, 0, sizeof(data));
    }
};
 
Matrix operator * (Matrix a, Matrix b) {
    int n = a.n, m = b.m;
    Matrix ret(n, m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 1; k <= a.m; k++) {
                ret.data[i][j] += a.data[i][k] * b.data[k][j];
                ret.data[i][j] %= mod;
            }
        }
    }
    return ret;
}
 
Matrix operator + (Matrix a, Matrix b) {
    for(int i = 1; i <= a.n; i++) {
        for(int j = 1; j <= a.m; j++) {
            a.data[i][j] += b.data[i][j];
            a.data[i][j] %= mod;
        }
    }
    return a;
}
 
Matrix pow(Matrix mat, LL k) {
	Matrix ret(mat.n, mat.m);
	for(int i = 1; i <= mat.n; i++) ret.data[i][i] = 1;
	while(k) {
		if(k & 1) ret = ret * mat;
		mat = mat * mat;
		k >>= 1;
	}
	return ret;
}

const int maxz = 1e6 + 10;
int arr[maxz], n, k;

int main() {
	while(scanf("%d%d", &n, &k) != EOF) {
		for(int i = 1; i <= n; i++) scanf("%d", arr + i);
		sort(arr + 1, arr + 1 + n);
		Matrix a0(3, 1), a(3, 3);
		a0.data[1][1] = arr[n]; 
		a0.data[2][1] = arr[n - 1]; 
		a0.data[3][1] = arr[n - 1] + arr[n];
		a.data[1][1] = 1; a.data[1][2] = 1; a.data[1][3] = 0;
		a.data[2][1] = 1; a.data[2][2] = 0; a.data[2][3] = 0;
		a.data[3][1] = 1; a.data[3][2] = 1; a.data[3][3] = 1;
		a = pow(a, k) * a0;
		LL ans = a.data[3][1];
		for(int i = 1; i < n - 1; i++) {
			ans = (ans + arr[i]) % mod;
		}
		cout << ans << endl;
	}
	return 0;
}
