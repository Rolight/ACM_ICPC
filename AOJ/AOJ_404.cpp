#include <cstdio>
#include <cstring>
#define swap(t,a,b) ((t)=(a),(a)=(b),(b)=(t))

using namespace std;

const int maxn = 100001;

char line[maxn][100],*pline[maxn],str[100];
int cxlove;

inline char conv(char c) {
	if(c >= '0' && c <= '9') return c;
	if(c < 'Q') 
		return (c - 'A') / 3 + '2';
	else return (c - 'A' - 1) / 3 + '2';
}

void quicksort(int str,int end) {
	if(str >= end) return;
	int i = str,j = end,mid = (i + j) / 2;
	char std[100],*t;
	strcpy(std,pline[mid]);
	while(1) {
		while(strcmp(pline[i],std) < 0) i++;
		while(strcmp(pline[j],std) > 0) j--;
		if(i < j) {
			swap(t,pline[i],pline[j]);
			i++; j--;
		} else break;
	}
	quicksort(str,i - 1); quicksort(j + 1,end);
}

void pro() {
	gets(str);
	int len = strlen(str),pos = 0;
	for(int i = 0;i < len;i++) {
		if(pos == 3) {
			line[cxlove][pos++] = '-';
			i--;
			continue;
		}
		if((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'Y' && str[i] != 'Q')) {
			line[cxlove][pos++] = conv(str[i]);
		}
	}
	line[cxlove][pos] = 0;
	pline[cxlove] = line[cxlove];
	cxlove++;
}

int main() {
	int T;
	scanf("%d",&T);
	getchar();
	char str[100];
	while(T--) pro();
	int times = 0,count = 0;
	quicksort(0,cxlove - 1);
	for(int i = 1;i < cxlove;i++) {
		if(strcmp(pline[i],pline[i - 1]) == 0) times++;
		else {
			if(times) {
				printf("%s %d\n",pline[i - 1],times + 1);
				count++;
				times = 0;
			}
		}
	}
	if(times) {
		printf("%s %d\n",pline[cxlove - 1],times + 1);
		count++;
		times = 0;
	}
	if(!count) puts("No duplicates.");
	return 0;
}
