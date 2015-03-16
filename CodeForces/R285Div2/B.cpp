#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <string>

using namespace std;

map<string, pair<string, string> > mp;
typedef map<string, pair<string, string> >::iterator Iter;

void Change(string a, string b) {
	string real_name;
	if(mp.count(a) == 0) {
		real_name = a;
	}
	else {
		Iter it = mp.find(a);
		real_name = it->second.first;
		mp.erase(it);
	}
	mp[b] = make_pair(real_name, b);
}

int main() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) {
		string a, b;
		cin >> a >> b;
		Change(a, b);
	}
	cout << mp.size() << endl;
	for(Iter it = mp.begin(); it != mp.end(); ++it) {
		cout << it->second.first << " " <<
			it->second.second << endl;
	}
	return 0;
}

