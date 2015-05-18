#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>


char month_str[12][32] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};

int conv(const char *str) {
	for(int i = 0; i < 12; i++) if(strcmp(month_str[i], str) == 0) {
		return i + 1;
	}
	return 0;
}

int isR(int y) {
	return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}


int calc(int y1, int y2) {
	//printf("calc %d %d\n", y1, y2);
	int ret = 0;
	for(; y1 % 400 != 0 && y1 < y2; y1++) if(isR(y1)) ret++;
	for(; y2 % 400 != 0 && y2 > y1; y2--) if(isR(y2)) ret++;
	//printf("calc %d %d\n", y1, y2);
	if(y2 - y1 < 400) {
		for(int i = y1; i <= y2; i++) if(isR(i)) ret++;
	}
	else ret += 97 * ((y2 - y1) / 400) + 1;
	return ret;
}

int gao(int y1, int m1, int d1, int y2, int m2, int d2) {
	if(m1 > 2) y1++;
	if(m2 < 2 || (m2 == 2 && d2 < 29)) y2--;
	return calc(y1, y2);
}

int main() {
	int y1, m1, d1, y2, m2, d2;
	int T; std::cin >> T;
	char buf[32];
	for(int kase = 1; kase <= T; kase++) {
		scanf("%s %d, %d", buf, &d1, &y1);
		m1 = conv(buf);
		scanf("%s %d, %d", buf, &d2, &y2);
		m2 = conv(buf);
		printf("Case #%d: %d\n", kase, gao(y1, m1, d1, y2, m2, d2));
	}
	return 0;
}
