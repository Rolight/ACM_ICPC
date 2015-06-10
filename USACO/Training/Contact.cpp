/*
ID: flsnnx1
LANG: C++
TASK: contact
*/

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

typedef long long LL;

const int maxn = 2e5 + 10;
const int maxm = (1 << 16) + 10;


struct Node {
	int l, r, cnt, val;
	Node(std::pair<int, int> p, int c, int v): cnt(c), val(v) {
		l = p.first; r = p.second;
	}
	bool operator < (const Node &x) const {
		if(cnt != x.cnt) return cnt > x.cnt;
		if(r - l != x.r - x.l) return r - l < x.r - x.l;
		return val < x.val;
	}
};

int cnt[maxm], len;
std::string str, buf;
std::map< int, std::pair<int, int> > pos;
std::vector<Node> vp;
int N, A, B;

void count(int k) {
	if(k > len) return;
	LL hc = 0, mask = (1 << k) - 1;
	for(int i = 0; i < k; i++) {
		hc = (((hc << 1) | (str[i] - '0')) & mask);
	}
	cnt[hc << 4 | k]++;
	pos[hc << 4 | k] = std::make_pair(0, k - 1);
	for(int i = k; i < len; i++) {
		hc = (((hc << 1) | (str[i] - '0')) & mask);
		pos[hc << 4 | k] = std::make_pair(i - k + 1, i);
		cnt[hc << 4 | k]++;
	}
}

int main() {
	freopen("contact.in", "r", stdin);
	freopen("contact.out", "w", stdout);
	std::cin >> A >> B >> N;
	while(std::cin >> buf) str += buf;
	len = str.length();
	for(int i = A; i <= B; i++) count(i);
	for(int i = 0; i < (1 << 16); i++) if(cnt[i] != 0) {
		vp.push_back(Node(pos[i], cnt[i], i));
	}
	std::sort(vp.begin(), vp.end());
	int first = 1, pcnt = 0, i, lcnt = 0;
	for(int i = 0; i < vp.size(); i++) {
		if(i == 0 || vp[i].cnt != vp[i - 1].cnt) {
			first = 1; pcnt++;
			lcnt = 0;
			if(pcnt == N + 1) break;
			if(i != 0) puts("");
			printf("%d\n", vp[i].cnt);
		}
		if(lcnt == 6) {
			lcnt = 0; first = 1;
			puts("");
		}
		if(first == 1) first = 0;
		else putchar(' ');
		printf("%s", str.substr(vp[i].l, vp[i].r - vp[i].l + 1).c_str());
		lcnt++;
	}
	puts("");
	return 0;
}
