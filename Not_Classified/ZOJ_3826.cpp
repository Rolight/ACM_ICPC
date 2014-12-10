#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <vector>

using namespace std;
const int buf_size = 1.5e7;
const int maxn = buf_size;
typedef pair<int, int> PII;
typedef long long LL;
const int bval = 1e9 + 7;
char buf[maxn];
LL pow10[maxn], hash[maxn];

int len;

struct Node {
	int kl, kr, vl, vr;
	bool root;
	Node() {
		vl = 1; vr = len;
		root = false;
	}
};

map<LL, PII> mp;

void make_hash() {
	hash[0] = 0;
	for(int i = 1; i <= len; i++) {
		hash[i] = hash[i - 1] * bval + buf[i];
	}
}

LL get_hash(int l, int r) {
	return hash[r] - hash[l - 1] * pow10[r - l + 1];
}

void gao() {
	stack<Node> stk;
	stk.push(Node());
	while(!stk.empty()) {
		Node now = stk.top(); stk.pop();
		int nowl = vl + 1, nowr = vr - 1;
	}
}

int main() {
	int T; scanf("%d", &T);
	pow10[0] = 1;
	for(int i = 1; i < buf_size; i++) 
		pow10[i] = pow10[i - 1] * 10;
	while(T--) {
		scanf("%s", buf + 1);
		len = strlen(buf + 1);
		mp.clear(); gao();
	}
	return 0;
}
