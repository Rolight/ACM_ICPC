#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n,m;
	while(~scanf("%d%d",&n,&m)) {
		map<int,vector<int> > list;
		for(int i = 1;i <= n;i++) {
			int tmp; scanf("%d",&tmp);
			list[tmp].push_back(i);
		}
		for(int i = 0;i < m;i++) {
			int k,p;
			scanf("%d%d",&k,&p);
			if(k > list[p].size()) printf("0\n");
			else printf("%d\n",list[p][k - 1]);
		}
	}
	return 0;
}
