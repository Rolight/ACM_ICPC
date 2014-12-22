#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef unsigned long long LL;

struct Cow {
	LL pos, speed;
	bool operator < (const Cow &x) const {
		pos < x.pos;
	}
};

bool cmp(Cow a, Cow b) {
	return a.pos < b.pos;
}

const int maxn = 100000 + 5;
Cow cow[maxn];
LL N, T;

int main() {
	freopen("cowjog.in", "r", stdin);
	freopen("cowjog.out", "w", stdout);
	//std::cout.sync_with_stdio(false);
	cin >> N >> T;
	for(int i = 1; i <= N; i++) {
		cin >> cow[i].pos >> cow[i].speed;
	}
	//sort(cow + 1, cow + 1 + N);
	for(int i = 1; i <= N; i++) {
		cow[i].pos += cow[i].speed * T;
	}
	for(int i = N; i > 1; i--) {
		if(cow[i - 1].pos >= cow[i].pos) {
			cow[i - 1].pos = cow[i].pos + 1;
		}
	}
	int ans = 1;
	for(int i = 2; i <= N; i++) {
		if(cow[i - 1].pos < cow[i].pos) {
			ans++;
		}
	}
	cout << ans << endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
