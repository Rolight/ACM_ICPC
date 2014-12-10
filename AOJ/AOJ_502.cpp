#include <stdio.h>
#include <string.h>

int pow(int a,int t) {
	int ans = 1;
	while(t--) ans *= a;
	return ans;
}

int main() {
	char a[20],output[5][50] = {
		"Daffodil","Class Flower","Grade Flower","OH~","Nothing"
	};
	while(gets(a)) {
		int src,tar = 0,len = strlen(a),cxlove = 4;
		sscanf(a,"%d",&src);
		for(int i = 0;i < len;i++) tar += pow(a[i] - '0',len);
		if(tar == src) cxlove = len - 3;
		puts(output[cxlove]);
	}
	return 0;
}
