#include <cstdio>
#include <algorithm>

using namespace std;

bool bigfirst(int a,int b) {
	return a > b;
}

void bigsort(int *a,int len) {
	sort(a,a + len,bigsort);
}

bool smallfirst(int a,int b) {
	return a < b;
}

void smallsort(int *a,int len) {
	sort(a,a + len,smallfirst);
}

int getnum(char *str) {
	int d;
	sscanf(str,"%d",&d);
	return d;
}

void split(int *a,int num) {
	a[0] = num / 1000;
	num %= 1000;
	a[1] = num / 100;
	num %= 100;
	a[2] = num / 10;
	a[3] = num % 10;
}

int megre(int *n) {
	return n[0] * 1000 + n[1] * 100 + n[2] * 10 + n[3];
}

int main() {
	int a[4],num;
	while(scanf("%d",&num),num != -1) {
		int now = num,len = 4,time = 0;
		printf("N=%d:\n",num);
		if(num % 1111 == 0) {
			puts("No!!"); continue;
		}
		while(now != 6174 && now) {
		}
	}
	return 0;
}
