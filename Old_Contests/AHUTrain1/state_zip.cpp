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
			if(nret == ret) cnt[prev][now][state]++;
			if(nret > ret) {
				cnt[prev][now][state] = 1;
				ret = nret;
			}
		}
	}
	printf("%d %d %d %d\n",prev,now,state,cnt[prev][now][state]);
	return note[prev][now][state] = ret;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		memset(w,-1,sizeof(w));
		memset(cnt,0,sizeof(cnt));
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
		int ansi = -1,ansj = -1;
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < n;j++) if(i != j && w[i][j] != -1) {
				LL ret = dfs(i,j,(1<<i)|(1<<j)) + w[i][j] + c[i] + c[j];
				if(ret > ans) {
					ans = ret;
					ccnt = 0;
				}
				if(ret == ans) {
					ccnt += cnt[i][j][(1<<i)|(1<<j)];
				}
			}
		}
		bool ok = false;
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < n;j++) {
				if(note[i][j][maxstate] != -1) {
					ok = true; break;
				}
			}
		}

		if(n == 1) cout << c[0] << endl;
		else if(!ok) cout << "0 0" << endl;
		else cout << ans << " " << ccnt / 2 << endl;
	}
	return 0;
}


