/*
ID: flsnnx1
LANG: C++
TASK: sort3
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int maxn = 1005;

void swap(int &a,int &b) {
	int tmp = a; a = b; b = tmp;
}

int ori[maxn],sorted[maxn];

bool check(int n) {
	for(int i = 1;i <= n;i++) {
		if(ori[i] != sorted[i]) return false;
	}
	return true;
}

int main() {
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
	int n; scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",&ori[i]);
	for(int i = 1;i <= n;i++) sorted[i] = ori[i];
	sort(sorted + 1,sorted + 1 + n);
	int ans = 0;
		//find two
	while(1) {
		bool flag = false;
		for(int i = 1;i <= n;i++) if(ori[i] != sorted[i]) {
			for(int j = 1;j <= n;j++) if(i != j) {
				if(sorted[i] == ori[j] && ori[i] == sorted[j]) {
					swap(ori[i],ori[j]); ans++; flag = true;
				}
			}
		}
		if(!flag) break;
	}
	//find three
	while(1) {
		int a[3] = {-1,-1,-1};
		for(int i = 1;i <= n;i++) if(ori[i] == 1 && ori[i] != sorted[i]) {
			a[0] = i; break;
		}
		for(int i = 1;i <= n;i++) if(ori[i] == 2 && ori[i] != sorted[i]) {
			a[1] = i; break;
		}
		for(int i = 1;i <= n;i++) if(ori[i] == 3 && ori[i] != sorted[i]) {
			a[2] = i; break;
		}
		if(a[0] != -1 && a[1] != -1 && a[2] != -1) {
			sort(a,a + 3);
			for(int i = 0;i < 3;i++) ori[a[i]] = i + 1;
			ans += 2;
		} else break;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
