#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 105;
int f[maxn];
char pat[maxn],str[maxn];

inline void getfail() {
	int len = strlen(pat);
	f[0] = f[1] = 0;
	for(int i = 2;i < len;i++) {
		int j = f[i - 1];
		while(j && str[i - 1] != str[j]) j = f[j];
		if(str[i - 1] == str[j]) f[i] = j + 1;
		else f[i] = 0;
	}
}

inline int kmp() {
	int lenp = strlen(pat),lens = strlen(str);
	int i = 0,j = 0;
	for(;i < lens;i++) {
		while(j && pat[j] != str[i]) j = f[j];
		if(pat[j] == str[i]) j++;
		if(j == lenp) return i - lenp + 2;
	}
	return -1;
}

int main() {
	int T; scanf("%d",&T);
	while(T--) {
		scanf("%s%s",str,pat);
		printf("%d\n",kmp());
	}
	return 0;
}
