#include <cstdio>
#include <cstring>

using namespace std;

char dict[10001][26],T[50],*pw[10001];
int n;

void quicksort(int str,int end) {
	if(str >= end) return;
	int i = str,j = end,mid = (i + j) / 2;
	char std[26];
	strcpy(std,pw[mid]);
	while(1) {
		while(strcmp(pw[i],std) < 0) i++;
		while(strcmp(pw[j],std) > 0) j--;
		if(i < j) {
			char *tmp = pw[i];
			pw[i] = pw[j];
			pw[j] = tmp;
			i++; j--;
		} else break;
	}
	quicksort(str,i - 1);
	quicksort(j + 1,end);
}

int main() {
	int len;
	scanf("%d",&n);
	for(int i = 0;i < n;i++) {
		scanf("%s",dict[i]);
		pw[i] = dict[i];
	}
	scanf("%s",T);
	len = strlen(T);
	quicksort(0,n - 1);
	for(int i = 0;i < n;i++) 
		if(strncmp(pw[i],T,len) == 0) puts(pw[i]);
	return 0;
}
