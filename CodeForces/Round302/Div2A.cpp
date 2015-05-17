#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 200;
int k, cnt[26];
char buf[maxn];

int main() {
	scanf("%d%s", &k, buf);
	int n = strlen(buf), out = 0;
	memset(cnt, -1, sizeof(cnt));
	for(int i = 0; i < n; i++) {
		if(cnt[buf[i] - 'a'] == -1) {
			cnt[buf[i] - 'a'] = i;
			out++;
		}
	}
	if(out < k) puts("NO");
	else {
		puts("YES");
		for(int i = 0; i < n; i++) {
			if(i > 0 && cnt[buf[i] - 'a'] == i && k > 1) {
				putchar('\n');
				k--;
			}
			putchar(buf[i]);
		}
		putchar('\n');
	}
	return 0;
}
