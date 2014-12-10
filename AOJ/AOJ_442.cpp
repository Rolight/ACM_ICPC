#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxlen = 255;
const int maxnode = 1050 * maxlen + 5;
const int sigma_size = 26;

struct trie {
	int ch[maxnode][sigma_size],val[maxnode];
	int sz,count;
	char buf[maxlen];
	trie() {
		sz = 1; memset(ch[0],0,sizeof(ch[0]));
	}
	inline int idx(char c) {
		return c - 'a';
	}

	void clear() {
		sz = 1; memset(ch[0],0,sizeof(ch[0]));
	}

	void insert(char *str,int v) {
		int u = 0,n = strlen(str);
		for(int i = 0;i < n;i++) {
			int c = idx(str[i]);
			if(ch[u][c] == 0) {
				memset(ch[sz],0,sizeof(ch[sz]));
				val[sz] = 0;
				ch[u][c] = sz++;
			}
			u = ch[u][c];
		}
		val[u] = v;
	}

	void print_l(char *s) {
		int len = strlen(s);
		for(int i = 0;i < len;i++) buf[i] = s[i];
		buf[len] = 0;
		int u = 0;
		for(int i = 0;i < len;i++) {
			int c = idx(s[i]);
			if(ch[u][c] == 0) return;
			u = ch[u][c];
		}
		count = 0;
		print_all(u,len);
	}

	void print_all(int u,int pos) {
		if(count >= 6) return;
		if(u == 0) return;
		if(pos >= maxlen) return;
		if(val[u]) {
			buf[pos] = 0;
			puts(buf); count++;
		}
		for(int i = 0;i < sigma_size;i++) {
			if(ch[u][i] != 0) {
				buf[pos] = i + 'a';
				print_all(ch[u][i],pos + 1);
				buf[pos] = 0;
			}
		}
	}
};

char word[maxlen];
trie t;

int main() {
	int N,M;
	while(~scanf("%d",&N)) {
		t.clear();
		for(int i = 0;i < N;i++) {
			scanf("%s",word);
			t.insert(word,1);
		}
		printf("%d\n",t.sz);
		scanf("%d",&M);
		for(int i = 0;i < M;i++) {
			scanf("%s",word);
			t.print_l(word);
		}
	}
	return 0;
}
