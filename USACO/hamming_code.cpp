
/*
ID: flsnnx1
LANG: C++
TASK: hamming
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N,B,D;

inline int getbit(int n,int i) {
	return (bool)(n & (1 << i));
}

inline int hamming(int a,int b) {
	int cnt = 0;
	for(int i = 0;i <= B;i++) {
		cnt += (getbit(a,i) != getbit(b,i));
	}
	return cnt;
}

int main() {
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
	vector<int> ans;
	scanf("%d%d%d",&N,&B,&D);
	for(int i = 0;i < (1 << B);i++) {
		bool ok = true;
		int m = ans.size();
		for(int j = 0;j < m;j++) {
			if(hamming(ans[j],i) < D) {
				ok = false; break;
			}
		}
		if(ok) ans.push_back(i);
		if(ans.size() == N) break;
	}
	int m = ans.size();
	for(int i = 0;i < m;i++) {
		if(i != 0 && i % 10 == 0) putchar('\n');
		else if(i != 0) putchar(' ');
		printf("%d",ans[i]);
	}
	putchar('\n');
	fclose(stdin);
	fclose(stdout);
	return 0;
}
