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

using namespace std;

const int maxn = 305;

int mp[maxn][maxn];
bool vis[(1 << 16) + 100];
int n,m;

bool check(int str,int end) {
	for(int i = 1;i <= m;i++) {
		int sum = 0;
		for(int j = str;j <= end;j++) {
			sum += mp[j][i];
		}
		if(sum != 1) return false;
	}
	return true;
}

int main() {
	while(scanf("%d%d",&n,&m) != EOF) {
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= m;j++) {
				scanf("%d",&mp[i][j]);
			}
		}
		bool ok = false;
		for(int i = 1;i <= n;i++) {
			for(int j = i;j <= n;j++) {
				if(check(i,j)) {
					ok = true;
					break;
				}
			}
			if(ok) break;
			else 
		}
		if(ok) puts("Yes, I found it");
		else puts("It is impossible");
	}
	return 0;
}


