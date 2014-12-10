#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <fstream>

using namespace std;

const int maxn = 200001;

struct Trie {
	int ch[maxn][26];
	int val[maxn],id[maxn];
	bool exist[maxn];
	int sz;
	Trie():sz(1) {
		memset(ch[0],0,sizeof(ch[0]));
		memset(exist,false,sizeof(exist));
	}
	inline int idx(char c) {
		return c - 'a';
	}
	void insert(char *s,int t) {
		int u = 0,n = strlen(s);
		for(int i = 0;i < n;i++) {
			int c = idx(s[i]);
			if(!ch[u][c]) {
				memset(ch[sz],0,sizeof(ch[sz]));
				val[sz] = 0;
				ch[u][c] = sz++;
			}
			val[u]++;
			u = ch[u][c];
		}
		id[u] = t;
		exist[u] = true;
	}
	int query(char *s,int kth) {
		int u = 0,n = strlen(s);
		for(int i = 0;i < n;i++) {
			int c = idx(s[i]);
			if(!ch[u][c]) return -1;
			u = ch[u][c];
		}
		if(val[u] < kth) return -1;
		return getid(u,kth);
	}
	int getid(int node,int kth) {
		int sum = 0,i;
		if(kth == 0) return id[node];
		for(i = 0;i < 26;i++) if(ch[node][i] != 0) {
			sum += val[ch[node][i]] + (int)(exist[ch[node][i]]);
			if(sum >= kth) break;
		}
		getid(ch[node][i],kth - (sum - val[ch[node][i]]));
	}
};

char str[1001];
Trie trie;

int main() {
	ifstream fin("auto.in");
	ofstream fout("auto.out");
	int W,N,th;
	fin >> W >> N;
	for(int i = 0;i < W;i++) {
		fin >> str;
		trie.insert(str,i + 1);
	}
	for(int i = 0;i < N;i++) {
		fin >> th >> str;
		fout << trie.query(str,th) << endl;
	}
	return 0;
}
