#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
const int maxn = 1000001;
string dict[maxn];
vector<string *> pdict;

bool cmp(string *a,string *b) {
	return (*a) < (*b);
}

int main() {
	int W,N,th;
	string str;
	ifstream fin("auto.in");
	ofstream fout("auto.out");
	fin >> W >> N;
	for(int i = 0;i < W;i++) {
		fin >> dict[i];
		pdict.push_back(&dict[i]);
	}
	sort(pdict.begin(),pdict.end(),cmp);
	for(int i = 0;i < N;i++) {
		fin >> th >> str;
		vector<string *>::iterator iter = upper_bound(pdict.begin(),pdict.end(),&str,cmp);
		iter = iter + th - 1;
		if(iter >= pdict.end()) {
			fout << -1 << endl;
			continue;
		}
		string now = **iter;
		if(now.size() < str.size()) {
			fout << -1 << endl;
			continue;
		}
		for(int i = 0;i < str.size();i++) if(str[i] != now[i]) {
			fout << -1 << endl;
			continue;
		}
		fout << *iter - dict + 1 << endl;
	}
	return 0;
}
