#include <cstdio>
#include <iostream>
#include <cstring>

typedef long long LL;

const int maxn = 100000 + 10;
const LL MOD = 1e9 + 7;
char buf[maxn];

LL extend_gcd(LL a,LL b,LL &x,LL &y){
    if(b==0){x = 1; y = 0; return a;}
    LL gcd = extend_gcd(b,a%b,x,y);
    LL t=x;
    x=y;y=t-a/b*x;
    return gcd;
}
LL Get_Inverse(LL num){
    LL x,y;
    extend_gcd(num,MOD,x,y);
    return (x%MOD+MOD)%MOD;
}

LL pow(LL a, LL p) {
	if(p == 0) return 1;
	LL ret = pow(a * a % MOD, p / 2);
	if(p & 1) ret = (ret * a) % MOD;
	return ret;
}

void gao() {
	int len = strlen(buf);
	LL num = 0;
	for(int i = 0; i < len; i++) {
		num = (num * 10 + buf[i] - '0') % (MOD - 1);
	}
	num = pow(3, num);
	num = (num - 1 + MOD) % MOD;
	num = (num * Get_Inverse(2) % MOD + 1) % MOD;
	std::cout << num << std::endl;
}

int main() {
	while(gets(buf) != NULL) gao();
	return 0;
}
