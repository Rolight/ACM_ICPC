#include <cstdio>
#include <vector>
#include <map>

using namespace std;


int main() {
	int n,m;
	while(~scanf("%d%d",&n,&m)) {
		map<int,vector<int> > table;
		int k,v;
		for(int i = 1;i <= n;i++) {
			scanf("%d",&v);
			table[v].push_back(i);
		}
		for(int i = 1;i <= m;i++) {
			scanf("%d%d",&k,&v);
			if(k > table[v].size()) putchar('0');
			else {
				printf("%d",table[v][k - 1]);
			}
			putchar('\n');
		}
	}
	return 0;
}
