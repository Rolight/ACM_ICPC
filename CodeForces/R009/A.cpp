#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int maxi = a > b ? a : b;
	int ans = 6 - maxi + 1;
	switch(ans) {
		case 0:printf("0/1\n"); break;
		case 1:printf("1/6\n"); break;
		case 2:printf("1/3\n"); break;
		case 3:printf("1/2\n"); break;
		case 4:printf("2/3\n"); break;
		case 5:printf("5/6\n"); break;
		case 6:printf("1/1\n"); break;
	}
	return 0;
}
