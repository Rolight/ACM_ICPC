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

const int maxn = 13;

int n,maxstate;
LL w[maxn][maxn],c[maxn];
LL note[maxn][maxn][1 << 13];
LL cnt[maxn][maxn][1 << 13];

LL dfs(int prev,int now,int state) {
	if(state == maxstate) return note[prev][now][state] = 0;
	LL ret = -1,nret; 
	if(note[prev][now][state] != -1) {
		return note[prev][now][state];
	}
	for(int i = 0;i < n;i++) {
		if((state & (1 << i)) == 0 && w[now][i] != -1) {
			LL addv = w[now][i] + c[i];
			if(w[prev][i] != -1) addv += c[i] * c[prev] * c[now];
			nret = dfs(now,i,state | (1 << i)) + addv;
			if(nret > ret) {
				ret = nret;
			}
		}
	}
	if(ret == -1) return -INF * 100000LL;
	return note[prev][now][state] = ret;
}

LL getcount(int prev,int now,int state) {
	if(state == maxstate) return 1;
	if(cnt[prev][now][state] != -1) return cnt[prev][now][state];
	LL ret = 0;
	for(int i = 0;i < n;i++) {
		if((state & (1 << i)) == 0 && w[now][i] != -1) {
			LL addv = w[now][i] + c[i];
			if(w[prev][i] != -1) addv += c[i] * c[prev] * c[now];
			if(note[prev][now][state] == note[now][i][state | (1 << i)] + addv) {
				ret += getcount(now,i,state | (1 << i));
			}
		}
	}
	return cnt[prev][now][state] = ret;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		memset(w,-1,sizeof(w));
		memset(cnt,-1,sizeof(cnt));
		memset(note,-1,sizeof(note));
		int m;
		cin >> n >> m;
		for(int i = 0;i < n;i++) {
			cin >> c[i];
		}
		for(int i = 0;i < m;i++) {
			int u,v;
			cin >> u >> v;
			u--; v--;
			w[u][v] = w[v][u] = c[u] * c[v];
		}
		maxstate = (1 << n) - 1;
		LL ans = 0,ccnt = 0;
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < n;j++) if(i != j && w[i][j] != -1) {
				LL ret = dfs(i,j,(1<<i)|(1<<j)) + w[i][j] + c[i] + c[j];
				ans = max(ans,ret);
			}
		}
		for(int i = 0;i < n;i++) {	
			for(int j = 0;j < n;j++) {
				if(note[i][j][(1 << i)|(1 << j)] + w[i][j] + c[i] + c[j] == ans) {
					ccnt += getcount(i,j,(1<<j)|(1<<i));
				}
			}
		}
		if(n == 1) cout << c[0] << " " << 1 << endl;
		else if(ccnt == 0) cout << "0 0" << endl;
		else cout << ans << " " << ccnt / 2 << endl;
	}
	return 0;
}
