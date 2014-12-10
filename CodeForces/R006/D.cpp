#include <cstdio>
#include <sstream>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <cctype>
#include <ctime>
#include <set>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <string>
#include <list>

#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"

using namespace std;

typedef long long LL;
const int INF = INT_MAX / 2;

void setfile() {
	freopen(INPUT_FILE,"r",stdin);
	freopen(OUTPUT_FILE,"w",stdout);
}

const int maxn = 20;

int n,a,b;
int h[maxn],ans = 0;
int f[maxn][maxn + 150][maxn + 150];
int t[maxn];
vector<int> path;
stack<int> pp;

int dfs(int now,int prev_hp,int now_hp) {
	if(now == n - 1) {
		if(prev_hp < 0) return 0;
		else return INF;
	}
	if(~f[now][prev_hp + 100][now_hp + 100]) return f[now][prev_hp + 100][now_hp + 100];
	//printf("%d %d %d now is ",now,prev_hp,now_hp);
	int ret = INF;
	int times;
	if(prev_hp >= 0) {
		times = prev_hp / b + 1;
	} else times = 0;
	for(int i = times;;i++) {
		int tmp = dfs(now + 1,now_hp - i * a,h[now + 1] - i * b) + i;
		if(tmp < ret) {
			ret = tmp;
		}
		if(now_hp - i * a < 0) break;
	}
	return f[now][prev_hp + 100][now_hp + 100] = ret;
}

void print_pp() {
	while(!pp.empty()) {
		printf("%d ",pp.top() + 1);
		pp.pop();
	}
	putchar('\n');
}

int print_path(int now,int prev_hp,int now_hp) {
	if(now == n - 1) {
		if(prev_hp < 0) {
			print_pp();	exit(0);
		}
		else return INF;
	}
	int ret = INF;
	int times;
	if(prev_hp >= 0) {
		times = prev_hp / b + 1;
	} else times = 0;
	for(int i = times;;i++) {
		int tmp = dfs(now + 1,now_hp - i * a,h[now + 1] - i * b) + i;
		if(tmp == f[now][prev_hp + 100][now_hp + 100]) {
			for(int j = 0;j < i;j++) pp.push(now);
			print_path(now + 1,now_hp - i * a,h[now + 1] - i * b);
			for(int j = 0;j < i;j++) pp.pop();
		}
		if(now_hp - i * a < 0) break;
	}
	return f[now][prev_hp + 100][now_hp + 100];
}

int main() {
	scanf("%d%d%d",&n,&a,&b);
	memset(f,-1,sizeof(f));
	for(int i = 0;i < n;i++) scanf("%d",&h[i]);
	int pre1 = 0,pre2 = 0;
	h[1] -= (h[0] / b + 1) * a;
	h[2] -= (h[0] / b + 1) * b;
	pre1 += h[0] / b + 1;
	h[0] -= (h[0] / b + 1) * b;
	for(int i = 1;i <= pre1;i++) path.push_back(1);
	if(h[n - 1] >= 0) {
		h[n - 2] -= (h[n - 1] / b + 1) * a;
		h[n - 3] -= (h[n - 1] / b + 1) * b;
		pre2 += h[n - 1] / b + 1;
		h[n - 1] -= (h[n - 1] / b + 1) * b;
		for(int i = 1;i <= pre2;i++) path.push_back(n - 2);
	}
	int ret = dfs(1,h[0],h[1]);
	printf("%d\n",ret + pre1 + pre2);
	for(int i = 0;i < path.size();i++) printf("%d ",path[i] + 1);
	print_path(1,h[0],h[1]);
	return 0;
}
