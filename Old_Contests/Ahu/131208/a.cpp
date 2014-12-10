#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int p[100] = {
	2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97
};

struct bigint {
	int len,data[500];
	bigint() {
		len = 1;
		memset(data,0,sizeof(data));
	};
	bigint(int val) {
		memset(data,0,sizeof(data));
		len = 0;
		while(val) {
			data[len++] = val % 10;
			val /= 10;
		}
		if(!len) len = 1;
	};
	string tostr() {
		string out("");
		for(int i = len - 1;i >= 0;i--) out += data[i] + '0';
		return out;
	}
};

bigint operator*(bigint a,bigint b) {
	bigint c = 0;
	int lena = a.len,lenb = b.len;
	for(int i = 0;i < lena;i++) {
		for(int j = 0;j < lenb;j++) {
			c.data[i + j] += a.data[i] * b.data[j];
			if(c.data[i + j] >= 10) {
				c.data[i + j + 1] += c.data[i + j] / 10;
				c.data[i + j] %= 10;
				c.len = i + j + 2;
			} else c.len = i + j + 1;
		}
	}
	return c;
}

void work(int &a,int &b) {
	for(int i = 0;p[i] && a != 1 && b != 1;i++) {
		if(a % p[i] == 0 && b % p[i] == 0) {
			a /= p[i]; b/= p[i];
			i--;
		}
	}
	if(a == 0) a = 1;
}

bigint C(int n,int m) {
	int a[101],b[101];
	for(int i = n,j = 1;i >= n - m + 1;i--,j++) a[j] = i;
	for(int i = 1;i <= m;i++) b[i] = i;
	for(int i = 1;i <= m;i++) 
		for(int j = 1;j <= m;j++) 
			work(a[i],b[j]);
	bigint ans = 1;
	for(int i = 1;i <= m;i++) {
		bigint tmp = a[i];
		ans = ans * tmp;
	}
	return ans;
}

int main() {
	int n,m;
	while(scanf("%d%d",&n,&m),n)
		printf("%d things taken %d at a time is %s exactly.\n",n,m,C(n,m).tostr().c_str());
	return 0;
}
