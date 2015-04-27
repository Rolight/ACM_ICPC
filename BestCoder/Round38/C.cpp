#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 32;

int bit0[maxn], bit1[maxn];
int L1, R1, L2, R2, ans;
int gg[maxn];

int getbit(int num, int pos) {
	int ret = (bool)((1 << pos) & num);
	return ret;
}

int dfs(int n, int lbd1, int rbd1, int lbd2, int rbd2, int num1, int num2, int z) {
	if(n == -1) {
		ans = max(ans, z);
		return 0;
	}
	if( n <= 30 && (z | ((1 << (n + 1)) - 1)) <= ans) return 0;
	if(!lbd1 && !lbd2 && !rbd1 && !rbd2 && gg[n] != -1) {
		return gg[n];
	}
	int l1 = lbd1 ? getbit(L1, n) : 0, r1 = rbd1 ? getbit(R1, n) : 1;
	int l2 = lbd2 ? getbit(L2, n) : 0, r2 = rbd2 ? getbit(R2, n) : 1;
	/*
	printf("now is %d %d %d %d\n", n, num1, num2, z);
	printf("range is %d, %d and %d, %d\n", l1, r1, l2, r2);
	system("pause");
	*/
	int ret = 0;
	if(l1 == r1 && l2 == r2) {
		int i = l1, j = l2;
		ret = dfs(
				n - 1, 
				lbd1 && i == l1,
				rbd1 && i == r1,
				lbd2 && j == l2,
				rbd2 && j == r2,
				num1 | (i << n),
				num2 | (j << n),
				z | ((i ^ j) << n)
		   ) | ((i ^ j) << n);
	}
	else if(l1 != r1 && l2 == r2) {
		int i = l2 ^ 1, j = l2;
		ret = dfs(
				n - 1, 
				lbd1 && i == l1,
				rbd1 && i == r1,
				lbd2 && j == l2,
				rbd2 && j == r2,
				num1 | (i << n),
				num2 | (j << n),
				z | ((i ^ j) << n)
		   ) | ((i ^ j) << n);
	}
	else {
		for(int i = l1; i <= r1; i++) {
			ret = max(dfs(
					n - 1, 
					lbd1 && i == l1,
					rbd1 && i == r1,
					lbd2 && i == l2,
					rbd2 && i == r2,
					num1 | (i << n),
					num2 | (i << n),
					z | ((i ^ i) << n)
			   ) | ((i ^ i) << n),
					ret);
		}
	}
	if(!lbd1 && !lbd2 && !rbd1 && !rbd2) {
		gg[n] = ret;
	}
	return ret;
}

int gao() {
	ans = 0;
	memset(gg, -1, sizeof(gg));
	int ret = dfs(31, 1, 1, 1, 1, 0, 0, 0);
	//printf("dfs ret is %d\n", ret);
	return ans;
}

int main() {
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		scanf("%d%d%d%d", &L1, &R1, &L2, &R2);
		printf("Case #%d: %d\n", kase, gao());
	}
	return 0;
}
