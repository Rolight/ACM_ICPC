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

const int maxn = 205;
const int maxm = 40000 + 5;
int N,M;

struct Node {
	int id,wid;
	int ic,ie[maxn],oc,oe[maxn];
};

bool cmp(Node a,Node b) {
	return a.id < b.id;
}

Node node[maxn],arr[maxn];
bool vis[maxn];

int solve() {
	memset(vis,0,sizeof(vis));
	for(int k = 1;k <= N;k++) {
		int x = -1;
		for(int i = N;i >= 1;i--) if(!vis[i]) {
			if(node[i].oc == 0) {
				x = i; break;
			}
		}
		if(x == -1) return x;
		vis[x] = true;
		arr[k] = node[x];
		for(int i = 0;i < node[x].ic;i++) {
			node[node[x].ie[i]].oc--;
		}
	}
	for(int i = 1;i <= N;i++) {
		arr[i].wid = N - i + 1;
	}
	sort(arr + 1,arr + 1 + N,cmp);
	for(int i = 1;i <= N;i++) {
		if(i != 1) putchar(' ');
		printf("%d",arr[i].wid);
	}
	putchar('\n');
	return 0;
}

int main() {
	int T; scanf("%d",&T);
	while(T--) {
		memset(node,0,sizeof(node));
		scanf("%d%d",&N,&M);
		for(int i = 1;i <= N;i++) {
			node[i].id = i;
			node[i].ic = node[i].oc = 0;
		}
		for(int i = 1;i <= M;i++) {
			int a,b; scanf("%d%d",&a,&b);
			node[a].oe[node[a].oc++] = b;
			node[b].ie[node[b].ic++] = a;
		}
		if(solve() == -1) puts("-1");
	}
	return 0;
}



