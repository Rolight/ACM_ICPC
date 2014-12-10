#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

int main() 
{
	freopen("out.txt","w",stdout);
	int n,bc = 0;
	while(cin >> n && n != 0)
	{
		int tar[n + 1],flag = 1;
		while(flag)
		{
			for(int i = 1;i <= n;i++)
			{
				cin >> tar[i];
				if(tar[1] == 0)
				{
					flag = 0;
					break;
				}
			}
			if(!flag) break;
			stack<int> s;
			int spos = 1,tpos = 1;
			bool ok = true;
			while(tpos <= n)
			{
				if(s.empty()) s.push(spos++);
				else if(s.top() == tar[tpos])
				{
					tpos++;
					s.pop();
				}
				else if(spos <= n) s.push(spos++);
				else
				{
					ok = false;
					break;
				}
			}
			if(ok) cout << "Yes";
			else cout << "No";
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
