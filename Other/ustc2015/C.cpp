#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

const int maxn = 512;
int n, m;
char str[maxn];
map<string, int> mp;

struct Tuntun {
	int id, pos[maxn];
	char name[16];
	bool operator < (const Tuntun &x) const {
		int g = 0;
		for(int i = 1; i <= n; i++)  {
			if(pos[i] < x.pos[i]) g++;
			else if(pos[i] > x.pos[i]) g--;
		}
		if(g > 0) return true;
		if(g == 0) return id < x.id;
		return false;
	}
};


Tuntun t[maxn];
int gid[maxn];

bool cmp(int a, int b) {
	return t[a] < t[b];
}

int main() {
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		scanf("%d%d", &n, &m);
		mp.clear();
		for(int i = 1; i <= m; i++) {
			scanf("%s", t[i].name);
			mp[t[i].name] = i;
			t[i].id = i;
			gid[i] = i;
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				scanf("%s", str);
				t[mp[str]].pos[i] = j;
			}
		}
		/*
		sort(gid + 1, gid + 1 + m, cmp);
		printf("Case #%d: %s\n", kase, t[gid[1]].name);
		*/
		sort(t + 1, t + 1 + m);
		printf("Case #%d: %s\n", kase, t[1].name);
	}
	return 0;
}
