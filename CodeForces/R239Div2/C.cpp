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

int a,b;

int main() {
	scanf("%d%d",&a,&b);
	for(int i = 1;i < a;i++) {
		int sqa = a * a,sqi = i * i;
		int val = sqa - sqi,tmp = sqrt(val);
		if(tmp * tmp == val) {
			if(i * b % a == 0 && tmp * b % a == 0) {
				int i1 = i * b / a,tmp1 = tmp * b / a;
				if(tmp != i1) { 
					puts("YES");
					printf("%d %d\n",i,tmp);
					printf("%d %d\n",0,0);
					printf("%d %d\n",-tmp1,i1);
					return 0;
				}
			}
		}
	}
	puts("NO");
	return 0;
}


