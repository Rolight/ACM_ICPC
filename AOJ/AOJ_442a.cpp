#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 1005;
const int maxl = 255;

char dict[maxn][maxl];
char *pdict[maxn];
char tmp[maxl];

void quicksort(int s,int e) {
	if(s >= e) return;
	int i = s,j = e,mid = (i + j) / 2;
	char std[maxl];
	strcpy(std,pdict[mid]);
	while(1) {
		while(strcmp(pdict[i],std) < 0) i++;
		while(strcmp(pdict[j],std) > 0) j--;
		if(i < j) {
			char *t = pdict[i];
			pdict[i] = pdict[j];
			pdict[j] = t;
			i++; j--;
		} else break;
	}
	quicksort(s,i - 1); quicksort(j + 1,e);
}

int find(char *s,int l,int r) {
	while(l < r) {
		int mid = (l + r) / 2;
		char *now = pdict[mid];
		int ret = strcmp(now,s);
		if(ret < 0) l = mid + 1;
		else if(ret > 0) r = mid;
		else return mid;
	}
	return l;
}

int main() {
	int N,M;
	while(~scanf("%d",&N)) {
		for(int i = 0;i < N;i++) {
			scanf("%s",dict[i]);
			pdict[i] = dict[i];
		}
		quicksort(0,N - 1);
		scanf("%d",&M);
		for(int i = 0;i < M;i++) {
			scanf("%s",tmp);
			int k = find(tmp,0,N - 1);
			int count = 0,len = strlen(tmp);
			while(count < 6 && k < N && strncmp(tmp,pdict[k],len) == 0) {
				if(count == 0 || k == 0 || strcmp(pdict[k],pdict[k - 1]) != 0) {
					puts(pdict[k]); count++;
				}
				k++;
			}
		}
	}
	return 0;
}
