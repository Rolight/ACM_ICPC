#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int main() {
	int n,k,val,now;
	char cmd;
	while(~scanf("%d%d",&n,&k)) {
		priority_queue<int,vector<int>,greater<int> > heap;
		now = 0;
		for(int i = 0;i < n;i++) {
			scanf(" %c",&cmd);
			if(cmd == 'I') {
				scanf("%d",&val);
				now++; heap.push(val);
				if(now > k) heap.pop();
			} else printf("%d\n",heap.top());
		}
	}
	return 0;
}
