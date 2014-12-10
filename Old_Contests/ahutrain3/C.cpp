#include <set>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int MM = 2333377;

struct Snow {
	int a[6],hc;
	void gethash() {
		hc = 0;
		for(int i = 0;i < 6;i++) {
			hc += a[i];
		}
		hc %= MM;
	}
};

vector<Snow> hash[MM];

inline bool equ(Snow &a,Snow &x) {
	bool clockequ = true,nclockequ = true;
	int c[12];
	for(int i = 0;i < 6;i++) {
		c[i] = c[i + 6] = a.a[i];
	}
	for(int i = 0;i < 6;i++) {
		if(a.a[i] == x.a[0]) {
			clockequ = nclockequ = true;
			for(int j = 0;j < 6;j++) {
				clockequ = clockequ && (c[i + j] == x.a[j]);
				nclockequ = nclockequ && (x.a[j] == c[i - j + 6]);
			}
			if(clockequ || nclockequ) return true;
		}
	}
	return false;
}

bool myfind(Snow &now) {
	int hc = now.hc;
	for(int j = 0;j < hash[hc].size();j++) {
		if(equ(hash[hc][j],now)) return true;
	}
	return false;
}

int main() {
	freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	Snow tmp;
	bool found = false;
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < 6;j++)
			scanf("%d",&tmp.a[j]);
		if(found == false) {
			tmp.gethash();
			if(myfind(tmp)) found = true;
			hash[tmp.hc].push_back(tmp);
		}
	}
	if(found) puts("Twin snowflakes found.");
	else puts("No two snowflakes are alike.");
	return 0;
}

