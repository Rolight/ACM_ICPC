#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

char a[1000],b[1000];

int main() {
	while(gets(a)) {
		gets(b);
		int left,right,len = strlen(a),lenb = strlen(b);
		for(int i = 0;i < len;i++) if(a[i] == '|') {
			left = i; right = len - i - 1; break;
		}
		int c = abs(right - left);
		if(((lenb - c) & 1) || lenb < c) puts("Impossible");
		else {
			if(left < right) {
				for(int i = 0;i < left;i++) putchar(a[i]);
				for(int i = 0;i < c + (lenb - c) / 2;i++) putchar(b[i]);
				putchar('|');
				for(int i = left + 1;i < len;i++) putchar(a[i]);
				for(int i = c + (lenb - c) / 2;i < lenb;i++) putchar(b[i]);
			} else {
				for(int i = 0;i < left;i++) putchar(a[i]);
				for(int i = 0;i < (lenb - c) / 2;i++) putchar(b[i]);
				putchar('|');
				for(int i = left + 1;i < len;i++) putchar(a[i]);
				for(int i = (lenb - c) / 2;i < lenb;i++) putchar(b[i]);
			}
			putchar('\n');
		}
	}
	return 0;
}
