/*
ID: flsnnx1
LANG: C++
TASK: msquare
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>

void setIO() {
	freopen("msquare.in", "r", stdin);
	freopen("msquare.out", "w", stdout);
}

int oprA(int state) {
	int low = state % 10000;
	state /= 10000;
	state += low * 10000;
	return state;
}

int oprB(int state) {
	int low = state % 10000, hig = state / 10000;
	low = low / 10 + low % 10 * 1000;
	hig = hig / 10 + hig % 10 * 1000;
	return hig * 10000 + low;
}

int oprC(int state) {
	int g2 = state / 1000000 % 10, g3 = state / 100000 % 10,
		g6 = state / 100 % 10, g7 = state / 10 % 10;
	state = state - g2 * 1000000 - g3 * 100000 - g6 * 100 - g7 * 10;
	int tmp = g3; g3 = g2; g2 = g6; g6 = g7; g7 = tmp;
	state = state + g2 * 1000000 + g3 * 100000 + g6 * 100 + g7 * 10;
	return state;
}

int fact[10], p10[10], r[10];
//¿µÍØÕ¹¿ª
int getHash(int state) {
	int ret = 0, now, now1, nowcnt, tmp = state;
	for(int i = 1; i <= 8; i++) {
		r[8 - i + 1] = tmp % 10;
		tmp /= 10;
	}
	for(int i = 1; i <= 8; i++) {
		nowcnt = 0;
		for(int j = i + 1; j <= 8; j++) if(r[j] < r[i]) {
			nowcnt++;
		}
		ret += nowcnt * fact[8 - i];
	}
	return ret;
}

const int maxn = 362880;
bool vis[maxn];
int prev[maxn];
char op[maxn];
std::queue<int> q;
std::stack<char> stk;

void bfs(int str, int end) {
	q.push(str);
	memset(prev, -1, sizeof(prev));
	vis[getHash(str)] = true;
	while(!q.empty()) {
		int now = q.front(), nh = getHash(now); q.pop();
		if(now == end) break;
		int pa = oprA(now), pb = oprB(now), pc = oprC(now);
		int ha = getHash(pa), hb = getHash(pb), hc = getHash(pc);
		if(!vis[ha]) {
			op[ha] = 'A'; prev[ha] = nh; vis[ha] = true; q.push(pa);
		}
		if(!vis[hb]) {
			op[hb] = 'B'; prev[hb] = nh; vis[hb] = true; q.push(pb);
		}
		if(!vis[hc]) {
			op[hc] = 'C'; prev[hc] = nh; vis[hc] = true; q.push(pc);
		}
	}
}

int main() {
	setIO();
	fact[0] = p10[0] = 1;
	for(int i = 1; i <= 9; i++) {
		fact[i] = fact[i - 1] * i;
		p10[i] = p10[i - 1] * 10;
	}
	int str = 12348765, end = 0, tmp;
	for(int i = 1; i <= 8; i++) scanf("%d", &r[i]);
	std::swap(r[5], r[8]);
	std::swap(r[6], r[7]);
	for(int i = 1; i <= 8; i++) end = end * 10 + r[i];
	bfs(str, end);
	int cnt = 0;
	for(int i = getHash(end); prev[i] != -1; i = prev[i]) {
		stk.push(op[i]);
		cnt++;
	}
	printf("%d\n", cnt);
	while(!stk.empty()) {
		putchar(stk.top());
		stk.pop();
	}
	puts("");
	return 0;
}
