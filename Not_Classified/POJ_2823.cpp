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

const int maxn = 1000000 + 5;

struct Num {
	int val,id;
};

struct mincmp {
	bool operator() (Num a,Num b) {
		return a.val > b.val;
	}
};

struct maxcmp {
	bool operator() (Num a,Num b) {
		return a.val < b.val;
	}
};

priority_queue<int,vector<Num>,mincmp> minheap;
priority_queue<int,vector<Num>,maxcmp> maxheap;
vector<int> ansmin(maxn),ansmax(maxn);
Num v[maxn];


int main() {
	int n,k;
	while(~scanf("%d%d",&n,&k)) {
		for(int i = 1;i <= n;i++) {
			scanf("%d",&v[i].val);
			v[i].id = i;
		}

		while(!minheap.empty()) minheap.pop();
		while(!maxheap.empty()) maxheap.pop();
		ansmin.clear();
		ansmax.clear();

		for(int i = 1;i < k;i++) {
			minheap.push(v[i]);
			maxheap.push(v[i]);
		}

		for(int i = k;i <= n;i++) {
			minheap.push(v[i]);
			maxheap.push(v[i]);

			Num now = minheap.top();

			while(now.id <= i - k) {
				minheap.pop();
				now = minheap.top();
			}
			ansmin.push_back(now.val);
			
			now = maxheap.top();
			while(now.id <= i - k) {
				maxheap.pop();
				now = maxheap.top();
			}
			ansmax.push_back(now.val);
		}

		int sz = ansmin.size();
		for(int i = 0;i < sz;i++) printf("%d ",ansmin[i]);
		putchar('\n');
		for(int i = 0;i < sz;i++) printf("%d ",ansmax[i]);
		putchar('\n');
	}

	return 0;
}


