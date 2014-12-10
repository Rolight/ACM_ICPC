#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

struct bigfloat {
	int num[1000],ex,len;
	bigfloat():ex(0),len(0) {
		memset(num,0,sizeof(num));
	};
	bigfloat(char *str) {
		memset(num,0,sizeof(num));
		while(str[0] == '0' && str[1] != '.') str++;
		len = strlen(str);
		while(str[len - 1] == '0' && str[len - 2] != '.') len--;
		for(int i = len - 1,pos = 0;i >= 0;i--) {
			if(str[i] == '.') ex = pos;
			else num[pos++] = str[i] -'0';
		}
		len--;
	}
	string str() {
		if(len == 2 && num[0] == 0 && num[1] == 0) return "0";
		string out("");
		if(num[len - 1] != 0) out += '0' + num[len - 1];
		for(int i = len - 2;i >= 1;i--) {
			if(i == ex - 1) out += '.';
			out += num[i] + '0';
		}
		if(num[0]) {
			if(ex == 0) out += '.'; 
			out += num[0] + '0' ;
		}
		return out;
	}
};

bigfloat operator* (bigfloat a,bigfloat b) {
	bigfloat c;
	c.len = (a.len > b.len) ? a.len : b.len;
	c.ex = a.ex + b.ex;
	for(int i = 0;i < a.len;i++) {
		for(int j = 0;j < b.len;j++) {
			c.num[i + j] += a.num[i] * b.num[j];
			if(c.num[i + j] > 9) {
				c.num[i + j + 1] += c.num[i + j] / 10;
				c.num[i + j] %= 10;
				c.len = i + j + 2;
			} else c.len = i + j + 1;
		}
	}
	int mp = 0;
	while(c.num[mp] == 0 && mp < c.ex - 1) mp++;
	for(int i = 0;i + mp < c.len;i++) {
		c.num[i] = c.num[i + mp];
	}
	c.ex -= mp;
	c.len -= mp;
	while(c.num[c.len - 1] == 0 && c.len > c.ex + 1) c.len--;
	return c;
}


int main() {
	char sn[1000];
	int m;
	while(~scanf("%s%d",sn,&m)) {
		bigfloat n(sn),ans("1.0");
		for(int i = 1;i <= m;i++) ans = ans * n;
		cout << ans.str() << endl;
	}
	return 0;
}