/*
ID: flsnnx1
LANG: C++
TASK: preface
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>
#include <map>
#include <iostream>

using namespace std;

const int maxn = 4001;
const int maxlen = 100;

char rnum[maxn][maxlen];
char ch[7] = {'I','V','X','L','C','D','M'};
int val[7] = {1,5,10,50,100,500,1000};
int cnt[7];
char buff[maxlen];
string str[maxn];

string getval(int v,int id) {
	string ret("");
	if(v <= 3 && v > 0) for(int i = 0;i < v;i++) ret += ch[id];
	if(v == 4) ret = ret + ch[id] + ch[id + 1];
	if(v == 5) ret = ret + ch[id + 1];
	if(v >= 6 && v <= 8) {
		ret += ch[id + 1];
		for(int i = 6;i <= v;i++) ret += ch[id];
	}
	if(v == 9) ret = ret + ch[id] + ch[id + 2];
	if(v == 10) ret = ret + ch[id + 2];
//	printf("%d %s\n",v,ret.c_str());
	return ret;
}

inline int imap(char c) {
	switch(c) {
		case 'I': return 0;
		case 'V': return 1;
		case 'X': return 2;
		case 'L': return 3;
		case 'C': return 4;
		case 'D': return 5;
		case 'M': return 6;
	}
}

void getcnt(string &s) {
	int m = s.size();
	for(int i = 0;i < m;i++) cnt[imap(s[i])]++;
}

int main() {
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
	int n; scanf("%d",&n);
	for(int a = 0;a < 4;a++) {
		for(int b = 0;b <= 9;b++) {
			for(int c = 0;c <= 9;c++) {
				for(int d = 0;d <= 9;d++) {
					int now = a * 1000 + b * 100 + c * 10 + d;
					if(now > n) {
						a = b = c = 10; break;
					}
					str[now] = getval(a,6) + getval(b,4) + getval(c,2) + getval(d,0);
					//printf("%d %s\n",now,str[now].c_str());
				}
			}
		}
	}
	for(int i = 1;i <= n;i++) getcnt(str[i]);
	for(int i = 0;i < 7;i++) {
		if(cnt[i] > 0) printf("%c %d\n",ch[i],cnt[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
