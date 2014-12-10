#include <cstdio>
#include <cstring>
#include <vector>
#include <math.h>

using namespace std;

int primelist[20005],ct;
int sn,np[100001],n;
vector<int> p;

void getprimelist() {
	int n = 10010;
	primelist[1] = 1;
	for (int i = 2;i <= n;i++) if(!primelist[i]) {
		p.push_back(i);
		for(int j = i << 1;j <= n;j += i) primelist[j] = 1;
	}
}

void dfs(int now,int val,int prev) {
	if(p[prev + 1] > sn + 1) return;
	for(int i = prev + 1;1LL * val * p[i] <= n && p[i] <= sn;i++) {
		dfs(now + 1,val * p[i],i);
		if(now & 1) {
			ct -= n / (val * p[i]);
		}
		else { 
			ct += n / (val * p[i]);
		}
		if(now == 1) ct++;
	}
}

int main() {
	getprimelist();
	while(~scanf("%d",&n),n) {
		ct = n; sn = sqrt((double)n) + 2;
		dfs(1,1,-1);
		printf("%d\n",ct - 1);
	}
	return 0;
}
