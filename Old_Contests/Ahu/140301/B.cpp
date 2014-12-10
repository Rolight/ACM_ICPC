#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct stu {
	int b,c,id;
	stu(int bb,int cc,int idd):b(bb),c(cc),id(idd) {}
	stu():b(0),c(0),id(0) {}
	bool operator < (const stu &x) const {
		if(b == x.b) return c < x.c;
		return b < x.b;
	}
};

struct bug {
    int b,id,ans;
    bool operator < (const bug &x) const {
        return b < x.b;
    }
};

const int maxn = 100001;
int n,m,s,ans[maxn];
set<stu>
stu p[maxn];
bug a[maxn];

bool ok(int t) {
	int pos = m - 1,cost = 0;
	while(pos >= 0) {
		int k = lower_bound(p,p + n,stu(a[pos].b,0)) - p;
		cost += p[k].c;
		for(int i = pos;i > pos - t && i >= 0;i--) {
			a[i].ans = p[k].id;
		}
		pos -= t;
	}
	if(cost <= s && pos <= 0) return true;
	else return false;
}

bool cmp(bug a,bug b) {
	return a.id < b.id;
}

int main() {
	int maxa = 0;
	scanf("%d%d%d",&n,&m,&s);
	for(int i = 0;i < m;i++) scanf("%d",&a[i].b),a[i].id = i;
	for(int i = 0;i < n;i++) scanf("%d",&p[i].b),p[i].id = i + 1;
	for(int i = 0;i < n;i++) scanf("%d",&p[i].c);
	sort(p,p + n); sort(a,a + m);
	int k = lower_bound(p,p + n,stu(a[m - 1].b,0)) - p;
	if(k < n && p[k].c < s) {
		puts("YES");
		int l = 1,r = m;
		while(l < r) {
			int mid = (l + r) / 2;
			if(ok(mid)) r = mid;
			else l = mid + 1;
		}
		ok(l);
		sort(a,a + m,cmp);
		for(int i = 0;i < m;i++) {
			printf("%d%c",a[i].ans,(i == m - 1 ? '\n':' '));
		}
	}
	else {
		puts("NO");
	}
	return 0;
}
