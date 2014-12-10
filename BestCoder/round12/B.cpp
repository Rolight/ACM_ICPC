#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 1024;
typedef long long LL;
char buf[maxn];
LL ra, rb;

bool isnum(char c) {
	return c >= '0' && c <= '9';
}

int main() {
	while(gets(buf) != NULL) {
		cin >> ra >> rb;
		int len = strlen(buf);
		getchar();
		bool bad = false;
		for(int i = 0; i < len; i++) if(!isnum(buf[i])) {
			if(i == 0 && buf[i] == '-') continue;
			bad = true; break;
		}
		if(bad) {
			puts("NO"); continue;
		}
		int spos = 0, leadzero = 0;
		bool flag = false;
		if(buf[0] == '-') spos++;
		for(int i = spos; i < len; i++) {
			if(buf[i] != '0') flag = true;
			if(!flag) leadzero++;
		}
		if(len - spos == 1 || leadzero == 0) bad = false;
		else bad = true;
		if(len - spos == 1 && spos == 1 && buf[1] == '0') bad = true;
		if(len - spos == 0) bad = true;
		if(bad) {
			puts("NO"); continue;
		}
		LL num = 0;
		for(int i = spos; i < len; i++) {
			num = num * 10 + buf[i] - '0';
			/*
			if(abs(num) > 1e10) {
				bad = true; break;
			}
			*/
			printf("%d %lld\n",i - spos + 1 , num);
		}
		printf("%lld\n", num);
		if(buf[0] == '-') num *= -1;
		if(num <= rb && num >= ra && bad == false) puts("YES");
		else puts("NO");
	}
	return 0;
}

