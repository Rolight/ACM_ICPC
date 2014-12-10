#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>

#define maxn 100001

using namespace std;

int N,K,a[maxn];
map<int,int> c;
set<int> num;
int main() {
	cin >> N >> K;
	for(int i = 1;i <= N;i++) {
		cin >> a[i];
		c[a[i]] = 0;
	}
	for(int i = 1;i <= K;i++) {
		c[a[i]]++;
		if(c[a[i]] == 1) num.insert(a[i]);
		if(c[a[i]] > 1) num.erase(a[i]);
	}
	for(int i = 0;i + K <= N;i++) {
		if(i > 0) {
			if(c[a[i]] > 0) c[a[i]]--;
			c[a[i + K]]++;
			if(c[a[i]] == 1) num.insert(a[i]);
			else num.erase(a[i]);
			if(c[a[i + K]] == 1) num.insert(a[i + K]);
			else num.erase(a[i + K]);
		}
		set<int>::reverse_iterator max = num.rbegin();
		if(max == num.rend()) cout << "Nothing" << endl;
		else cout << *max << endl;
	}
	return 0;
}
