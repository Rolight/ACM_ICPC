#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 81;
int n,m;

struct bigint {
	int data[70],len;
	bigint() {
		len = 0;
		memset(data,0,sizeof(data));
	}
	bigint(int val) {
		len = 0;
		memset(data,0,sizeof(data));
		while(val) {
			data[len++] = val % 100000;
			val /= 100000;
		}
	}
	void output() {
		if(len == 0) {
			putchar('0');
			return;
		}
		printf("%d",data[len - 1]);
		for(int i = len - 2;i >= 0;i--) printf("%05d",data[i]);
	}
};

bigint operator* (const bigint &a,const bigint &b) {
	bigint c;
	if(a.len == 0 || b.len == 0) return c;
	for(int i = 0;i < a.len;i++) {
		for(int j = 0;j < b.len;j++) {
			c.data[i + j] += a.data[i] * b.data[j];
			if(c.data[i + j] > 99999) {
				c.data[i + j + 1] += c.data[i + j] / 100000;
				c.data[i + j] %= 100000;
				c.len = i + j + 2;
			} else c.len = i + j + 1;
		}
	}
	return c;
}

bigint operator+ (const bigint &a,const bigint &b) {
	bigint c;
	int len = max(a.len,b.len);
	for(int i = 0;i < len;i++) {
		c.data[i] += a.data[i] + b.data[i];
		if(c.data[i] > 99999) {
			c.data[i + 1] = c.data[i] / 100000;
			c.data[i] %= 100000;
			c.len = i + 2;
		} else c.len = i + 1;
	}
	return c;
}

bool operator< (const bigint &a,const bigint &b) {
	int len = min(a.len,b.len);
	if(a.len != b.len) return a.len < b.len;
	for(int i = len - 1;i >= 0;i--) if(a.data[i] != b.data[i]) return a.data[i] < b.data[i];
	return false;
}

bigint f[maxn][maxn];
int val[maxn];

bigint solve() {
	for(int k = 0;k < m;k++) {
		for(int i = 0;i + k < m;i++) {
			int j = i + k;
			bigint left,right;
			if(i != j) {
				left = (f[i + 1][j] + bigint(val[i])) * bigint(2);
				right = (f[i][j - 1] + bigint(val[j])) * bigint(2);
				if(left < right) f[i][j] = right;
				else f[i][j] = left;
			} else f[i][j] = bigint(val[i] * 2);
		}
	}
	return f[0][m - 1];
}

int main() {
	while(~scanf("%d%d",&n,&m)) {
		bigint ans;
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < m;j++) {
				scanf("%d",&val[j]);
			}
			ans = solve() + ans;
		}
		ans.output(); putchar('\n');
	}
	return 0;
}
