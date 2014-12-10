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

int main() {
	int t,n,m,v,k;
	scanf("%d",&t);
	while(t--) {
		int ans = 0;
		scanf("%d%d%d%d",&n,&m,&v,&k);
		LL M = m,V = v,K = k,N = n;
		while(M < N) {
			ans++;
			if(M < 0 || M >= (M - V) * K) {
				ans = -1;
				break;
			}
			M = (M - V) * K;
		}
		printf("%d\n",ans);
	}
	return 0;
}


