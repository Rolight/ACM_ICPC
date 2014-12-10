#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int len;

struct DNA {
	char sx[51];
	int val;
	void getval() {
		val = 0;
		for(int i = 0;i < len;i++) {
			for(int j = i - 1;j >= 0;j--) 
				if(sx[i] < sx[j]) val++;
		}
	}
};

DNA d[101],*pd[101];

bool cmp(DNA *a,DNA *b) {
	return a->val < b->val;
}

int main() {
	int n;
	while(~scanf("%d%d",&len,&n)) {
		for(int i = 0;i < n;i++) {
			scanf("%s",d[i].sx);
			d[i].getval();
			pd[i] = d + i;
		}
		stable_sort(pd,pd + n,cmp);
		for(int i = 0;i < n;i++) puts(pd[i]->sx);
	}
	return 0;
}
