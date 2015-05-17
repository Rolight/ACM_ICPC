#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <ctime>
#include <cstdlib>

typedef long long LL;
const int maxn = 5;

struct Node {
	char ch;
	int num;
	bool operator < (const Node &x) const {
		if(ch == x.ch) return num < x.num;
		return ch < x.ch;
	}
};

int cmp(Node a[maxn], std::set<Node> &st) {
	int ret = 0;
	for(int i = 0; i < maxn; i++) {
		if(st.count(a[i]) == 0) {
			ret++;
		}
	}
	return ret;
}

bool construct(Node a[maxn], int pos) {
	for(int i = pos - 1; i >= 0; i--) {
		a[i].ch = a[i + 1].ch;
		a[i].num = a[i + 1].num - 1;
		if(a[i].num <= 0) return false;
	}
	for(int i = pos + 1; i < maxn; i++) {
		a[i].ch = a[i - 1].ch;
		a[i].num = a[i - 1].num + 1;
		if(a[i].num > 14) return false;
	}
	for(int i = 0; i < maxn; i++) if(a[i].num > 13) a[i].num -= 13;
	return true;
}

Node str[maxn];

void gao() {
	int ans = 5;
	std::set<Node> st;
	for(int i = 0; i < maxn; i++) st.insert(str[i]);
	Node tmp[maxn];
	for(int i = 0; i < maxn; i++) {
		for(int j = 0; j < maxn; j++) {
			tmp[j] = str[i];
			if(construct(tmp, j)) {
				ans = std::min(ans, cmp(tmp, st));
			}
		}
	}
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		for(int i = 0; i < maxn; i++) {
			scanf(" %c%d", &str[i].ch, &str[i].num);
		}
		gao();
	}
	return 0;
}
