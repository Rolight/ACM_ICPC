#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int n;

bool ok(int cc) {
	int cnt = 0;
	for(int i = 1;i <= 4;i++) cnt += ((cc & (1 << i)) != 0);
	//printf("%d %d\n",cc,cnt);
	return cnt >= 3;
}

long long f[20][20][2][(1<<6)];

long long dfs(int now,int last_high,int have,int color) {
	if(now == n + 1) {
		if(have && ok(color)) return 1;
		else return 0;
	}
	long long &note = f[now][last_high][have][color];
	if(note != -1) return note;
	long long ret = 0;
	for(int i = 1;i <= 4;i++) {
		if(abs(i - last_high) == 3) {
			ret += dfs(now + 1,i,1,color | (1 << i));
		} else ret += dfs(now + 1,i,have,color | (1 << i));
	}
//	printf("%d %d %d %d %d\n",now,last_high,have,color,ret);
	return note = ret;
}

int main() {
	int kase = 1;
	while(cin >> n,~n) {
		memset(f,-1,sizeof(f));
		cout << n << ": " << dfs(1,15,0,0) << endl;
	}
	return 0;
}
