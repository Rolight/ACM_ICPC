#include <cstdio>
#include <sstream>
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


const int maxn = 105;

typedef pair<int,int> line;

inline bool cmp(line a,line b) {
	if(a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

void swap(int &a,int &b) {
	int tmp = a;a = b;b = tmp;
}
line l[maxn];
bool vis[maxn];

int main() {
	int n; scanf("%d",&n);
	for(int i = 0;i < n;i++) {
		scanf("%d%d",&l[i].first,&l[i].second);
		if(l[i].first > l[i].second) swap(l[i].first,l[i].second);
	}
	
	sort(l,l + n,cmp);

	int cnt = 0,nowend = -100000;
	for(int i = 0;i < n;i++) {
		if(l[i].first >= nowend) {
			cnt++; nowend = l[i].second;
		}
	}
	printf("%d\n",cnt);
	return 0;
}


