#include <cstdio>
#include <cstring>

const int maxn = 32;

int bin[maxn],len,K;

void tobin(int num) {
	for(int i = 0;i < maxn;i++) {
		if(num & (1 << i)) {
			bin[i] = 1;
			K++;
			len = i + 1;
		}
		else bin[i] = 0;
	}
}

int todec() {
	int ans = 0;
	for(int i = 0;i < len;i++) if(bin[i]) {
		ans += (1 << i);
	}
	return ans;
}

int main() {
	int T,n; scanf("%d",&T);
	while(T--) {
		K = 0;
		scanf("%d",&n); tobin(n);
		if(K  == 0) continue;
		int ok = 0,c1 = 0;
		for(int i = 0;i < len - 1;i++) {
			if(bin[i] == 1 && bin[i + 1] == 0) {
				bin[i] = 0; bin[i + 1] = 1; ok = 1;
				for(int j = 0;j < i;j++) {
					if(c1) bin[j] = 1,c1--;
					else bin[j] = 0;
				}
				break;
			} else if(bin[i]) c1++;
		}
		if(!ok) {
			bin[len] = 1; bin[len - 1] = 0;
			for(int i = 0;i < len;i++) {
				if(i < K - 1) bin[i] = 1;
				else bin[i] = 0;
			}
			len++;
	 	}
		printf("%d\n",todec());
	}
	return 0;
}
