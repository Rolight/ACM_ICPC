#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>

#define bits 1
#define bitq 2
#define bitpq 4

using namespace std;

int main() {
	int n;
	while(~scanf("%d",&n)) {
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		int cmd,val,possible = 7;
		for(int i = 0;i < n;i++) {
			scanf("%d%d",&cmd,&val);
			if(cmd == 1) {
				if(possible & bits) s.push(val);
				if(possible & bitq) q.push(val);
				if(possible & bitpq) pq.push(val);
			} else {
				int ret;
				if(possible & bits) {
					if(s.empty()) possible &= (~bits);
					else {
						ret = s.top(); s.pop();
					}
					if(ret != val) possible &= (~bits);
				}
				if(possible & bitq) {
					if(q.empty()) possible &= (~bitq);
					else {
						ret = q.front(); q.pop();
					}
					if(ret != val) possible &= (~bitq);
				}
				if(possible & bitpq) {
					if(pq.empty()) possible &= (~bitpq);
					else {
						ret = pq.top(); pq.pop();
					}
					if(ret != val) possible &= (~bitpq);
				}
			}
		}
		switch(possible) {
			case 0: puts("impossible"); break;
			case bits: puts("stack"); break;
			case bitq: puts("queue"); break;
			case bitpq: puts("priority queue"); break;
			default: puts("not sure");
		}
	}
	return 0;
}
