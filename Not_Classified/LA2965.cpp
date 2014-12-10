#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

const int maxn = 24;

int n,val[maxn];
char s[1000];
map<int,int> table,table1;

int main() {
	while(~scanf("%d",&n)) {
		for(int i = 0;i < n;i++) {
			scanf("%s",s);
			val[i] = 0;
			for(int j = 0;s[j];j++) val[i] ^= (1 << (s[j] - 'A'));
		}
		table.clear();
		table1.clear();
		int n1 = n / 2,n2 = n - n1;
		//中途相遇法，先处理前半部分
		for(int i = 1;i <= (1 << n1);i++) {
			int nowval = 0,nowc = 0;
			for(int j = 0;j < n1;j++) {
				if(((1 << j) & i) != 0) {
					nowval ^= val[j];
					nowc++;
				}
			}
			if(table.count(nowval) == 0 || table[nowval] < nowc) {
				table[nowval] = nowc;
				table1[nowval] = i;
			}
		}
		//后半部分
		int ans = 0,ansval = 0,ansi = 0;
		for(int i = 1;i <= (1 << n2);i++) {
			int nowval = 0,nowc = 0;
			for(int j = 0;j < n2;j++) {
				if(((1 << j) & i) != 0) {
					nowval ^= val[j + n1];
					nowc++;
				}
			}
			if(table.count(nowval) != 0 && table[nowval] + nowc > ans) {
				ans = table[nowval] + nowc;
				ansval = nowval;
				ansi = i;
			}
		}
		//输出结果
		printf("%d\n",ans);
		for(int i = 0;i < n1;i++) if((1 << i) & table1[ansval]) printf("%d ",i + 1);
		for(int i = 0;i < n2;i++) if((1 << i) & ansi) printf("%d ",i + n1 + 1);
		printf("\n");
	}
	return 0;
}
