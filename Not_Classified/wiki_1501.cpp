#include <iostream>
#include <cstdio>


using namespace std;

struct {
	int l,r,d;
} node[1 << 17];

int maxdeep = -1,maxwid = 1,queue[1 << 17];

void dfs(int now,int deep) {
	if(now) {
		dfs(node[now].l,deep + 1);
		dfs(node[now].r,deep + 1);
	} else {
		if(deep - 1 > maxdeep) maxdeep = deep - 1;
	}
}

void bfs() {
	int front = 0,rear = 1,nowwid = 0,nowdeep = 1;
	queue[front] = 1;
	node[1].d = 1;
	while(front < rear) {
		int lson = node[queue[front]].l,rson = node[queue[front]].r;
		if(node[queue[front]].d != nowdeep) {
			nowwid = 1; nowdeep++;
		} else if(queue[front] != 1) nowwid++;
		if(lson) {
			queue[rear++] = lson;
			node[lson].d = nowdeep + 1;
		}
		if(rson) {
			queue[rear++] = rson;
			node[rson].d = nowdeep + 1;
		}
		if(nowwid > maxwid) maxwid = nowwid;
		printf("deep is %d\n",nowdeep);
		front++;
	}
}

int main() {
	int n,lnode,rnode;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) {
		scanf("%d%d",&lnode,&rnode);
		node[i].l = lnode;
		node[i].r = rnode;
	}
	dfs(1,1);
	bfs();
	printf("%d %d\n",maxwid,maxdeep);
	return 0;
}
