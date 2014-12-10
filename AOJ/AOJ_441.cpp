#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000 + 10;
int pre_pos[maxn];

int main() {
	int A, B;
	while (scanf("%d%d", &A, &B), A) {
		memset(pre_pos, -1, sizeof(pre_pos));
		A %= B;
		if (A == 0) {
			puts(".\nThis expansion terminates.");
			continue;
		}
		int nowmod = A, nowval, len, nowpos = 0;
		pre_pos[A] = 0;
		bool terminal = false;
		putchar('.');
		while (1) {
			nowpos++;
			nowval = (nowmod * 10) / B;
			nowmod = (nowmod * 10) % B;
			if (nowval == 0 && nowmod == 0) {
				terminal = true; break;
			}
			printf("%d", nowval);
			if (pre_pos[nowmod] != -1) {
				len = nowpos - pre_pos[nowmod];
				break;
			}
			pre_pos[nowmod] = nowpos;
		}
		putchar('\n');
		if (terminal) puts("This expansion terminates.");
		else printf("The last %d digits repeat forever.\n", len);
 	}
	return 0;
}
