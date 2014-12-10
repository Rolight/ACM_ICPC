#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

const int maxn = 1005;

struct Component {
	int price,quality;
};


int cnt,budget,maxquality;
map<string,int> id;
vector<Component> comp[maxn];

void readin() {
	char name[30],power[30];
	int p,q,n;
	cnt = maxquality = 0;
	scanf("%d%d\n",&n,&budget);
	id.clear();
	for(int i = 0;comp[i].size();i++) {
		comp[i].clear();
	}
	for(int i = 0;i < n;i++) {
		scanf("%s%s%d%d",name,power,&p,&q);
		int nowid;
		if(id.count(name)) {
			nowid = id[name];
		} else {
			nowid = cnt++;
			id[name] = nowid;
		}
		comp[nowid].push_back((Component){p,q});
		if(q > maxquality) {
			maxquality = q;
		}
	}
}

bool ok(int val) {
	int total = 0;
	for(int i = 0;i < cnt;i++){
		int cheapest = INT_MAX,m = comp[i].size();
		for(int j = 0;j < m;j++) if(comp[i][j].quality >= val) {
			cheapest = min(cheapest,comp[i][j].price);
		}
		if(cheapest == INT_MAX) return false;
		total += cheapest;
		if(total > budget) {
			return false;
		}
	}
	return true;
}

void work() {
	int str = 0,end = maxquality,mid;
	while(str < end) {
		mid = str + (end - str + 1) / 2;
		if(ok(mid)) {
			str = mid;
		} else {
			end = mid - 1;
		}
	}
	cout << str << endl;
}

int main() {
	int T; cin >> T;
	while(T--) {
		readin();
		work();
	}
	return 0;
}
