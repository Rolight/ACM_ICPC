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

struct Board {
	int a, b;
	Board(int a = 0, int b = 0) : 
		a(a), b(b) {}
	bool operator == (const Board &x) const {
		return a == x.a && b == x.b;
	}
	bool operator < (const Board &x) const {
		if(x.a == a) return x.b < b;
		return x.a < a;
	}
};

const int mod = 1e9 + 7;

vector<Board> vec;
int f[4000][300][2], n, l;

int main() {
	scanf("%d%d", &n, &l);
	for(int i = 1; i <= n; i++) {
		int a, b; scanf("%d%d", &a, &b);
		if(a > b) swap(a, b);
		vec.push_back(Board(a, b));
	}
	sort(vec.begin(), vec.end());
	//vec.erase(unique(vec.begin(), vec.end()), vec.end());
	int cnt_board = vec.size();
	for(int i = 1; i <= l; i++) {
		for(int j = 0; j < cnt_board; j++) {
			if(i == vec[j].b) {
				f[i][j][0] = (f[i][j][0] + 1) % mod;
			}
			if(i == vec[j].a && vec[j].a != vec[j].b) {
				f[i][j][1] = (f[i][j][1] + 1) % mod;
			}
			else for(int k = 0; k < cnt_board; k++) if(j != k) {
				if(i - vec[j].b > 0) {
					if(vec[j].b == vec[k].a) f[i][j][0] = (f[i - vec[j].b][k][0] + f[i][j][0]) % mod;
					if(vec[j].b == vec[k].b) f[i][j][0] = (f[i - vec[j].b][k][1] + f[i][j][0]) % mod;
				}
				if(i - vec[j].a > 0 && vec[j].a != vec[j].b) {
					if(vec[j].a == vec[k].a) f[i][j][1] = (f[i - vec[j].a][k][0] + f[i][j][1]) % mod;
					if(vec[j].a == vec[k].b) f[i][j][1] = (f[i - vec[j].a][k][1] + f[i][j][1]) % mod;
				}
			}
			//printf("for length:%d, (%d,%d) ans is %d %d\n", i, vec[j].a, vec[j].b, f[i][j][0], f[i][j][1]);
		}
	}
	int ans = 0;
	for(int i = 0; i < cnt_board; i++) {
		ans = (ans + f[l][i][0]) % mod;
		ans = (ans + f[l][i][1]) % mod;
	}
	printf("%d\n", ans);
	return 0;
}
