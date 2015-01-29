#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;
const int maxn = 1e5 + 10;
const int maxk = 1e6 + 10;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

struct Node {
	int a, b;
	Node(int a, int b): a(a), b(b) {
		int p = gcd(a, b);
		a /= p; b /= p;
	}
	Node(): a(1), b(1) {}
	bool operator == (const Node &x) const {
		return a == x.a && b == x.b;
	}
	bool operator < (const Node &x) const {
		if(a == x.a) return b < x.b;
		return a < x.a;
	}
};

int n, m, val[maxk];
Node t[maxn], str[maxk];
vector<Node> vec;
map<int, int> ch[maxn + maxk];
int fail[maxn + maxk];

void Addmp(Node node) {
	vec.push_back(node);
}

int getNodeid(Node node) {
	return lower_bound(vec.begin(), vec.end(), node) - vec.begin() + 1;
}

void Addstr(int len) {
	int u = 0;
	for(int i = 1; i <= len; i++) {
		int v = getNodeid(str[i]);
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &val[i]);
		if(i > 0) {
			t[i] = Node(val[i], val[i - 1]);
			Addmp(t[i]);
		}
	}
	for(int i = 0; i < m; i++) {
		int nowk; scanf("%d", &nowk);
		for(int j = 0; j < nowk; j++) {
			scanf("%d", &val[j]);
			if(j > 0) {
				str[j] = Node(val[j], val[j - 1]);
				Addmp(str[j]);
			}
		}
		Addstr(nowk - 1);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	gao();
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		solve();
	}
	return 0;
}
