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

const int N = 100010;
const int maxn = N;

int n,sumv[maxn + 5];
map<int,int> id;

inline int lowbit(int x) {
	return x & (-x);
}

void addc(int pos,int val) {
	while(pos <= maxn) {
		sumv[pos] += val;
		pos += lowbit(pos);
	}
}

inline int getsum(int pos) {
	int ans = 0;
	while(pos > 0) {
		ans += sumv[pos];
		pos -= lowbit(pos);
	}
	return ans;
}

inline int sum(int l,int r) {
	return getsum(r) - getsum(l - 1);
}

int query_low(int l,int r) {
	while(l < r) {
		int m = (l + r) >> 1;
		if(sum(m + 1,r) >= 1) l = m + 1;
		else r = m;
	}
	return l;
}

int query_up(int l,int r) {
	while(l < r) {
		int m = (l + r) >> 1;
		if(sum(l,m) >= 1)  r = m;
		else l = m + 1;
	}
	return l;
}

int power[N],idc[N];

int main() {
	while(scanf("%d",&n),n) {
		memset(sumv,0,sizeof(sumv));
		id.clear();
		vector<int> vec;
		map<int,int> mp;
		for(int i = 0;i < n;i++) {
			scanf("%d%d",&idc[i],&power[i]);
			vec.push_back(power[i]);
		}
		sort(vec.begin(),vec.end());
		int p = 1;
		for(vector<int>::iterator iter = vec.begin();iter != vec.end();p++,iter++)
			mp[*iter] = p;
		for(int i = 0;i < n;i++) {
			if(i == 0) {
				printf("%d %d\n",idc[i],1);
				id[mp[power[i]]] = idc[i];		
				addc(mp[power[i]],1);
				continue;
			}
			int low = query_low(1,mp[power[i]]);
			int upper = query_up(mp[power[i]],vec.size() + 1);
			int dlow = abs(vec[low - 1] - vec[mp[power[i]] - 1]);
			int dup = abs(vec[upper - 1] - vec[mp[power[i]] - 1]);
			if(id.count(upper) == 0) dup = 100000000 + 5;
			if(id.count(low) == 0) dlow = 100000000 + 5;
			if(dlow > dup) {
				printf("%d %d\n",idc[i],id[upper]);
			} else printf("%d %d\n",idc[i],id[low]);
			id[mp[power[i]]] = idc[i];		
			addc(mp[power[i]],1);
		}
	}
	return 0;
}


