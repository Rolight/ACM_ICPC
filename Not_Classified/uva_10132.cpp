#include <cstdio>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <cctype>
#include <ctime>
#include <set>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <string>
#include <list>

#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"

using namespace std;

typedef long long LL;
const int INF = INT_MAX / 2;

void setfile() {
	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}

bool cmp(string a,string b)  {
	return a.size() < b.size();
}

const int maxn = 300;

vector<string> buf,sans;
bool vis[maxn];
string line;
int N,cnt,len;

bool ok(const string &str) {
	int amount = 0;
	memset(vis,0,sizeof(vis));
	for(int i = 0;i < cnt;i++) {
		if(vis[i]) continue;
		for(int j = cnt - 1;j >= 0;j--) {
			if(vis[j]) continue;
			if(buf[i].size() + buf[j].size() < len) return false;
			if(buf[i] + buf[j] == str || buf[j] + buf[i] == str) {
				amount += 2; vis[j] = vis[i] = true; break;
			}
		}
		if(amount == cnt) return true;
	}
	return true;
}

int main() {
	scanf("%d",&N);
	getchar();
	getline(cin,line);
	for(int kase = 1;kase <= N;kase++) {
		buf.clear(); sans.clear();
		while(getline(cin,line) && line.size() != 0) buf.push_back(line);

		cnt = buf.size();
		sort(buf.begin(),buf.end(),cmp);
		int minlen = buf[0].size(),maxlen = buf[cnt - 1].size();
		len = minlen + maxlen;

		for(int i = 0;i < cnt && buf[i].size() == minlen;i++) {
			for(int j = cnt - 1;j >= 0 && buf[j].size() == maxlen;j--) {
				sans.push_back(buf[i] + buf[j]);
				sans.push_back(buf[j] + buf[i]);
			}
		}

		for(int i = 0;i < sans.size();i++) {
			if(ok(sans[i])) {
				cout << sans[i] << endl;
				break;
			}
		}
		if(kase != N) cout << endl;
	}
	return 0;
}


