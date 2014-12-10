#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
	int n,d,m,l;
	scanf("%d%d%d%d",&n,&d,&m,&l);
	__int64 L = -m;
	long long R = -m + l;
	long long x = d;
	for(int i = 1;i <= n;i++) {
		L += m;
		R += m;
		__int64 t = R / d;
		if(x + d < L)
			break;
		x = d * t;
	}
	printf("%I64d\n",x + d);
	return 0;
}
