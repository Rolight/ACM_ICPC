#include <iostream>
#include <cstdio>

using namespace std;

#define maxn 100001
#define f(p) ((p)>>1)
#define l(p) ((p)<<1)
#define r(p) (((p)<<1)+1)
#define swap(t,a,b)((t)=(a),(a)=(b),(b)=(t))

int N,K,num[maxn],heap[maxn << 2],cheap = 1,_t;

void up(int pos) {
	while(pos >= 1 && heap[pos] < heap[f(pos)]){
		swap(_t,heap[pos],heap[f(pos)]);
		pos = f(pos);
	}
}

void down(int pos) {
	while(pos <= cheap / 2) {
		int left = heap[l(pos)],right = heap[r(pos)],min;
		if(r(pos) > cheap) min = l(pos);
		else min = left < right ? l(pos) : r(pos);
		if(heap[pos] <= heap[min]) break;
		else {
			swap(_t,heap[pos],heap[min]);
			pos = min;
		}
	}
}

void insert(int n) {
	heap[++cheap] = n;
	up(cheap);
}

int pop() {
	int ans = heap[1];
	swap(_t,heap[1],heap[cheap]);
	cheap--;
	down(1);
	return ans;
}

int main() {
	scanf("%d%d",&N,&K);
	for(int i = 1;i <= N;i++) scanf("%d",num + i);
	heap[1] = num[1];

	return 0;
}
