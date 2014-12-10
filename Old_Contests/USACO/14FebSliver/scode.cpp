#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const int maxn = 105;
int sp[maxn];
map<string,int> mem;
string str;

inline void getFail(string &p,int *f) {
	int m = p.size();
	f[0] = f[1] = 0;
	for(int i = 1;i < m;i++) {
		int j = f[i];
		while(j && p[i] != p[j]) j = f[j];
		f[i + 1] = p[i] == p[j] ? j + 1 : 0;
	}
}	

inline int find(string &T,string &P,int *f) {
	int n = T.size(),m = P.size();
	getFail(P,f);
	int j = 0;
	for(int i = 0;i < n;i++) {
		while(j && P[j] != T[i]) j = f[j];
		if(P[j] == T[i]) j++;
		if(j == m) return i - m + 1;
	}
	return -1;
}

int dfs(string now) {
	if(now.size() == str.size()) {
		if(now == str) return 1;
		else return 0;
	}
	if(now.size() > str.size()) return 0;
	if(now.size() == 1) return 0;
	if(find(str,now,sp) == -1) return mem[now] = 0;
	if(mem.count(now)) return mem[now];
	int ret = 0;
	for(string::iterator iter = now.begin();iter != now.end();++iter) {
		if(iter != now.begin() && iter - now.begin() + now.size() <= str.size()) {
			string add(string(now.begin(),iter));
			if(find(str,add,sp) != -1) ret += dfs(add + now) + dfs(now + add);
		}
		if(iter != now.end() && now.end() - iter <= str.size()) {
			string add(string(iter,now.end()));
			if(find(str,add,sp) != -1) ret += dfs(add + now) + dfs(now + add);
		}
	}
	return mem[now] = ret % 2014;
}

int main() {
	ifstream fin("scode.in");
	ofstream fout("scode.out");
	int ans = 0;
	fin >> str;
	for(int i = 0;i < str.size();i++) {
		for(int j = i + 2;j < str.size();j++) {
			string wait(str.begin() + i,str.begin() + j);
			if(!mem.count(wait)) ans += dfs(wait);
		}
	}
	fout << ans % 2014 << endl;
	return 0;
}


