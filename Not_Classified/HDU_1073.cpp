#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstdio>

using namespace std;
const string end_flag = "END";
string buf, nowstr;
string input, answer;

bool isempty(char c) {
	return c == '\t' || c == '\n' || c == ' ';
}

void Judge(string &wa, string &ac) {

	//cout << "Now input is " << wa << endl;
	//cout << "Now ans   is " << ac << endl;
	bool PE = false, WA = false;
	int wa_len = wa.size(), ac_len = ac.size();
	int wa_pos = 0, ac_pos = 0;
	while (ac_pos < ac_len) {
		if (wa[wa_pos] == ac[ac_pos]) {
			wa_pos++; ac_pos++;
		}
		else if (!isempty(wa[wa_pos]) && !isempty(ac[ac_pos])) {
			WA = true; break;
		}
		else if (isempty(wa[wa_pos])) {
			PE = true; wa_pos++;
		}
		else {
			PE = true; ac_pos++;
		}
	}
	if (ac_pos == ac_len && wa_pos == wa_len) {
		if (WA) cout << "Wrong Answer" << endl;
		else if (PE) cout << "Presentation Error" << endl;
		else cout << "Accepted" << endl;
	}
	else {
		while (wa_pos < wa_len && isempty(wa[wa_pos])) wa_pos++;
		while (ac_pos < ac_len && isempty(ac[ac_pos])) ac_pos++;
		if (ac_pos == ac_len && wa_pos == wa_len) cout << "Presentation Error" << endl;
		else cout << "Wrong Answer" << endl;
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T; cin >> T;
	getline(cin, buf);
	for (int i = 0; i < T; i++) {
		input = answer = "";
		getline(cin, buf);
		while (getline(cin, buf), buf != end_flag) answer += buf + '\n';
		getline(cin, buf);
		while (getline(cin, buf), buf != end_flag) input += buf + '\n';
		Judge(input, answer);
	}
	return 0;
}