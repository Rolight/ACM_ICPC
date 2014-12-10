#include <iostream>
#include <cstring>

#define mm 10003

using namespace std;

struct mat {
	int data[2][2];
	mat() {
		memset(data,0,sizeof(data));
	};
	mat(int a,int b,int c,int d) {
		data[0][0] = a; data[0][1] = b; data[1][0] = c; data[1][1] = d;
	};
};


mat operator* (mat a,mat b) {
	mat c;
	c.data[0][0] = a.data[0][0] * b.data[0][0] + a.data[0][1] * b.data[1][0];
	c.data[1][0] = a.data[1][0] * b.data[0][0] + a.data[1][1] * b.data[1][0];
	c.data[0][1] = a.data[0][0] * b.data[0][1] + a.data[0][1] * b.data[1][1];
	c.data[1][1] = a.data[1][0] * b.data[0][1] + a.data[1][1] * b.data[1][1];
	c.data[0][0] %= mm; c.data[1][1] %= mm; c.data[1][0] %= mm; c.data[0][1] %= mm;
	return c;
}

mat pow(mat a,int n) {
	if(n == 1) return a;
	if(n == 2) return a * a;
	mat ans = pow(a * a,n >> 1);
	if(n & 1) ans = ans * a;
	return ans;
}

int fib(int n) {
	if(n <= 2) return 1;
	else {
		mat ans = pow(mat(1,1,1,0),n - 2);
		return ans.data[0][0] + ans.data[0][1];
	}
}

int gcd(int a,int b) {
	return (b == 0) ? a : gcd(b, a % b);
}

int main() {
	int m,n;
	while(cin >> m >> n , m || n) {
		cout << fib(gcd(m,n)) % mm << endl;
	}
	return 0;
}
