#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

struct node {
	int s,dis;
	node(int a,int b):s(a),dis(b) {
	};
};

node str(0,0);
int end,tcon[10] = {0,1,2,3,1,2,3,1,2,3};
int p10[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000},direction[4] = {1,-1,3,-3};

inline int findzero(int num) {
	int mask = 100000000,pos = 9,nn = num;
	while(num / mask != 0) {
		pos--; num %= mask; mask /= 10;
	}
	return pos;
}

inline int getbit(int num,int p) {
	return (num / p10[p - 1] % 10);
}

inline int swapbit(int num,int a,int b) {
	int na = getbit(num,a),nb = getbit(num,b);
	num = num - (na - nb) * p10[a - 1] - (nb - na) * p10[b - 1];
	return num;
}

int bfs() {
	set<int> hash; queue<node> q;
	q.push(str); hash.insert(str.s);
	int ans;
	while(!q.empty()) {
		node &now = q.front();
		if(now.s == end) return now.dis;
		int pos = findzero(now.s);
		for(int i = 0;i < 4;i++) {
			int tar = pos + direction[i],ltar = tcon[pos];
			if(direction[i] == -1 || direction[i] == 1) ltar += direction[i];
			if(tar <= 9 && tar >= 1 && ltar >= 1 && ltar <= 3) {
				int newnum = swapbit(now.s,pos,tar);
				if(!hash.count(newnum)) {
					hash.insert(newnum);
					q.push(node(newnum,now.dis + 1));
				}
			}
		}
		q.pop();
	}	
	return -1;
}

int readnum() {
	int p,res,ans = 0;
	for(int i = 9;i >= 1;i--) {
		res = scanf("%d",&p);
		if(res == -1) return -1;
		ans += p * p10[i - 1];
	}
	return ans;
}

int main() {
	while((str.s = readnum()) != -1) {
		end = readnum();
		int ret = bfs();
		if(ret == -1) puts("Impossible");
		else printf("%d\n",ret);
	}
	return 0;
}
