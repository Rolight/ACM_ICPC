#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 3005;
char buf[maxn][40],*str[maxn];
char tmp[40];

void quicksort(int s,int e) {
	if(s >= e) return;
	int i = s,j = e,mid = (i + j) / 2;
	char std[40];
	strcpy(std,str[mid]);
	while(1) {
		while(strcmp(str[i],std) < 0) i++;
		while(strcmp(str[j],std) > 0) j--;
		if(i < j) {
			char *tmp = str[i]; str[i] = str[j]; str[j] = tmp;
			i++; j--;
		} else break;
	}
	quicksort(s,i - 1);
	quicksort(j + 1,e);
}

int main() {
	int n;
	while(scanf("%d",&n) != EOF) {
		if(n == 0) puts("1");
		for(int i = 0;i < n;i++) {
			scanf("%s",tmp);
			int len = strlen(tmp),j;
			for(j = 0;j < len;j++) if(tmp[j] != '0') break;
			if(j == len) {
				buf[i][0] = '0'; buf[i][1] = 0;
			} else {
				for(int pos = 0;j <= len;j++,pos++) buf[i][pos] = tmp[j];
			}
			str[i] = buf[i];
		}
		quicksort(0,n - 1);
		int ans = 0,now = 0;
		for(int i = 0;i < n;i++) {
			if(i && strcmp(str[i],str[i - 1]) != 0) {
				ans = max(ans,now);
				now = 0;
			}
			now++;
		}
		ans = max(ans,now);
		printf("%d\n",ans);
	}
	return 0;
}

