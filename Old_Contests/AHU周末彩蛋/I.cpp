#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1000005;

int f[maxn];

inline void getfail(char *str) {
    int m = strlen(str);
    f[0] = f[1] = 0;
    for(int i = 2;i <= m;i++) {
        int j = f[i - 1];
        while(j && str[i - 1] != str[j]) j = f[j];
        if(str[i - 1] == str[j]) f[i] = j + 1;
        else f[i] = 0;
    }
}

int gao(char *str) {
	int n;
	n = strlen(str);
	getfail(str);
	if(f[n] > 0 && n % (n - f[n]) == 0) {
		return (n - f[n]);
	}
	else return n;
}

char str1[maxn], str2[maxn];

int main() {
    int n,kase = 0;
    while(scanf("%s%s",str1, str2) != EOF) {
		int p1 = gao(str1), p2 = gao(str2);
		int len1 = strlen(str1), len2 = strlen(str2);
		if(strncmp(str1, str2, max(p1, p2)) == 0) {
			if(p1 == p2) {
				int ans = 0;
				for(int i = p1; i <= min(len1, len2); i += p1) {
					if(len1 % i == 0 && len2 % i == 0) {
						ans++;
					}
				}
				printf("%d\n", ans);
			}
			else puts("1");
		}
		else {
			puts("0");
		}
	}
	return 0;
}
