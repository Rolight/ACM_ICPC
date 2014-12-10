#include <cstdio>
#include <cstring>
#include <cctype>

char buf[15],c;
int _x;

inline int readint() {
	c = getchar();
	while(!isdigit(c)) c = getchar();
	_x = 0;
	while(isdigit(c)) {
		_x = _x * 10 + c - '0';
		c = getchar();
	}
	return _x;
}

inline void writeint(int num) {
	_x = 0;
	if(num == 0) {
		putchar('0');
	} else {
		while(num) {
			buf[_x++] = num % 10 + '0';
			num /= 10;
		}
		_x--;
		while(_x >= 0) {
			putchar(buf[_x]); _x--;
		}
	}
}

int main() {
	int n,x,c[101];
	while(scanf("%d",&n),n) {
		memset(c,0,sizeof(c));
		for(int i = 0;i < n;i++) {
			x = readint(); 
			c[x]++;
		}
		bool first = true; 
		for(int i = 1;i <= 100;i++) {
			while(c[i]--) {
				if(!first) putchar(' ');
				writeint(i);
				first = false;
			}
		}
		putchar('\n');
	}
	return 0;
}
