#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

const int maxn = 151;

struct program {
	int str,end;
};

int n;
program p[maxn];

bool cmp(program a,program b) {
	return a.end < b.end;
}

int main() {
	freopen("recording.in","r",stdin);
	freopen("recording.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d%d",&p[i].str,&p[i].end);
	sort(p + 1,p + n + 1,cmp);
	int ans = 1,last = p[1].end;
	for(int i = 2;i <= n;i++) {
		if(p[i].str >= last) {
			ans++; last = p[i].end;
			p[i].str = p[i].end = INT_MAX;
		}
	}
	sort(p + 1,p + n + 1,cmp);
	if(p[1].end != INT_MAX) {
		ans++; last = p[1].end;
		for(int i = 2;i <= n;i++) {
			if(p[i].str >= last && p[i].str != INT_MAX) {
				ans++; last = p[i].end;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
