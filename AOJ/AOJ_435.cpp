#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

#define max(a,b) (((a)>(b))?(a):(b))

using namespace std;

class bign {
	public:
		int id[1000],sd[1000],ilen,slen;
		bign():ilen(0),slen(0) {
			memset(id,0,sizeof(id));
			memset(sd,0,sizeof(sd));
		};
		bign(char *num) {
			memset(id,0,sizeof(id));
			memset(sd,0,sizeof(sd));
			while(num[0] == '0') num++;
			if(num[0] == '.') num--;
			int len = strlen(num),ppos = 0;
			while(num[ppos] != '.') ppos++;
			while(num[len - 1] == '0') len--;
			if(num[len - 1] == '.') len++;
			for(int i = ppos - 1;i >= 0;i--) id[ppos - i - 1] = num[i] - '0';
			for(int i = ppos + 1;i < len;i++) sd[i - ppos - 1] = num[i] - '0';
			ilen = ppos; slen = len - ppos - 1;
		};
		string str() {
			char out[1000];
			int pos = 0;
			for(int i = ilen - 1;i >= 0;i--) out[pos++] = id[i] + '0';
			out[pos++] = '.';
			for(int i = 0;i < slen;i++) out[pos++] = sd[i] + '0';
			out[pos] = 0;
			return string(out);
		}
};

bign operator+(bign a,bign b) {
	int len = max(a.slen,b.slen);
	for(int i = len - 1;i >= 0;i--) {
		a.sd[i] += b.sd[i];
		if(i && a.sd[i] > 9) {
			a.sd[i - 1] += a.sd[i] / 10;
			a.sd[i] %= 10;
		}
	}
	if(a.sd[0] > 9) {
		a.id[0]++;
		a.sd[0] %= 10;
	}
	for(a.slen = len;a.sd[a.slen - 1] == 0 && a.slen > 1;a.slen--);
	len = max(a.ilen,b.ilen);
	for(int i = 0;i < len;i++) {
		a.id[i] += b.id[i];
		a.id[i + 1] += a.id[i] / 10;
		a.id[i] %= 10;
	}
	if(a.id[len]) a.ilen = len + 1;
	else a.ilen = len;
	return a;
}

int main() {
	char a[1000],b[1000];
	while(~scanf("%s%s",a,b)) {
		bign ga(a),gb(b);
		cout << (ga + gb).str() << endl;
	}
	return 0;
}
