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
const int maxn = 105;

struct Event {
	int t, id;
	char team, color;
	bool operator < (const Event &x) const {
		return t < x.t;
	}
};

int hcnt[maxn], acnt[maxn], n;
bool vh[maxn], va[maxn];
char home[maxn], away[maxn];
Event e[maxn];

int main() {
	scanf("%s%s", home, away);
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %c%d %c", &e[i].t, &e[i].team, &e[i].id, &e[i].color);
	}
	sort(e, e + n);
	for(int i = 0; i < n; i++) {
		if(e[i].team == 'a') {
			if(e[i].color == 'y') {
				acnt[e[i].id]++;
			}
			else {
				acnt[e[i].id] += 2;
			}
			if(acnt[e[i].id] >= 2 && !va[e[i].id]) {
				printf("%s %d %d\n", away, e[i].id, e[i].t);
				va[e[i].id] = true;
			}
		}
		else {
			if(e[i].color == 'y') {
				hcnt[e[i].id]++;
			}
			else {
				hcnt[e[i].id] += 2;
			}
			if(hcnt[e[i].id] >= 2 && !vh[e[i].id]) {
				printf("%s %d %d\n", home, e[i].id, e[i].t);
				vh[e[i].id] = true;
			}
		}
	}
	return 0;
}
