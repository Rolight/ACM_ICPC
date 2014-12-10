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

vector<int> pm;
bool vis[1000006];
int m;

bool bp(int a,int b) {
	int mm = max(a,b);
	for(int i = 0;i < pm.size() && pm[i] <= mm;i++) {
		if(a % pm[i] == 0 && b % pm[i] == 0) return false;
	}
	return true;
}

int main() {
	int n;
	scanf("%d",&n);
	vis[1] = true;
	for(int i = 2;i <= n + 5;i++) if(vis[i] == false) {
		for(int j = i + i;j <= n + 5;j += i) {
			vis[j] = true;
		}
		pm.push_back(i);
	}
	int b1 = 1,b2 = 1;
	for(int i = n - 1;i > 1;i--) {
		if(bp(i,n)) {
			if(b1 == 1) b1 = i;
			else b2 = i;
		}
		if(b1 != 1 && b2 != 1) break;
	}
	cout << (long long)b1 * b2 * n << endl;
	return 0;
}


