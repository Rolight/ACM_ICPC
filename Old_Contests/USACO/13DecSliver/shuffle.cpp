#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;

const int maxn = 100001;

int src[maxn],tmp[maxn],p[maxn],tar[maxn];

inline void suffle(int src[],int N) {
	for(int i = 1;i <= N;i++) tmp[p[i]] = src[i];
	for(int i = 1;i <= N;i++) src[i] = tmp[i];
}

int main() {
	ifstream fin("shuffle.in");
	ofstream fout("shuffle.out");
	int N,M,Q,pos;
	fin >> N >> M >> Q;
	pos = N;
	for(int i = 1;i <= M;i++) fin >> p[i];
	for(int i = 1;i <= N;i++) src[i] = i;
	for(int i = 1;i + M - 1 <= N;i++) {
		suffle(src + i - 1,M);
		tar[pos--] = src[i];
	}
	for(int i = N - M + 2;i <= N;i++) tar[pos--] = src[i];
	for(int i = 1;i <= Q;i++) {
		fin >> pos; fout << tar[pos] << endl;
	}
	return 0;
}
