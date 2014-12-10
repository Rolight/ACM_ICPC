#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

long long a_point, b_point;
vector<int> a_str, b_str;

int main() {
	int n, num; cin >> n;
	int last;
	for(int i = 1; i <= n; i++) {
		cin >> num;
		if(num > 0) {
			a_point += num;
			a_str.push_back(num);
		}
		else {
			b_point -= num;
			b_str.push_back(-num);
		}
		if(i == n) last = num;
	}
	int win = 0;
	if(a_point != b_point) {
		if(a_point > b_point) win = 1;
		else win = 2;
	}
	else if(a_str != b_str) {
		if(a_str > b_str) win = 1;
		else win = 2;
	}
	else {
		if(last > 0) win = 1;
		else win = 2;
	}
	if(win == 1) puts("first");
	else puts("second");
	return 0;
}
