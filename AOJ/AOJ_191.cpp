#include <cstdio>
#include <cstring>

using namespace std;

char num[3000];

int main() {
	int T,k,len,i,j;
	scanf("%d",&T);
	while(T--) {
		scanf("%s%d",num,&k);
		len = strlen(num);
		num[len] = 127; len++;
		i = j = 0;
		while(k) {
			j = i + 1;
			while(num[j] == -1) j++;
			if(~num[i] && num[i] < num[j]) {
				num[i] = -1;
				k--; i = 0;
				continue;
			}
			i = j;
		}
		for(i = 0;i < len - 1;i++) if(~num[i]) putchar(num[i]);
		puts("");
	}
	return 0;
}
