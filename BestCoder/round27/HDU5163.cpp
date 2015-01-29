#include <cstdio> 
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 2e5 + 10;
typedef long long LL;
int n, m, d[maxn];
LL pos[maxn];

LL getdis(int ns ,int s, int t) {
	//printf("calc %d %d %d\n", ns, s, t);
	bool right = true;
	LL ret = 0;	
	//from ns to s
	if(s >= ns) {
		ret += pos[s] - pos[ns];
	}
	else {
		ret += (pos[n] - pos[ns]) * 2;
		ret += pos[ns] - pos[s];
		right = false;
	}
	//cout << "lala:" << ret << endl;
	//from s to t
	if(right) {
		if(t >= s) ret += (pos[t] - pos[s]);
		else {
			ret += (pos[n] - pos[s]) * 2;
			ret += (pos[s] - pos[t]);
		}
	}
	else {
		if(t <= s) ret += pos[s] - pos[t];
		else {
			ret += pos[s] + pos[t];
		}
	}
	return ret;
}

void gao() {
	scanf("%d%d", &n, &m);
	memset(pos, 0, sizeof(pos));
	for(int i = 2; i <= n; i++) {
		scanf("%d", &d[i]);
		pos[i] = pos[i - 1] + d[i];
	}
	int s, t, ns;
	LL dis;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d", &s, &t);
		ns = (i - 1) % n + 1;
		dis = getdis(ns, s, t);
		printf("%I64d\n", dis);
	}
}

int main() {
	int T; scanf("%d", &T);
	while(T--) gao();
	return 0;
}
