#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
set<char> dic;
int main()
{
	string st;
	cin >> st;
	int cou = 0,n = 0,m = 0,sum = 0;char ch = st[0];
	if (ch == '?') cou = 1;
	else 
	{
		sum++;
		dic.insert(ch);
	}
	for (int i = 1;i < st.length(); i++)
	{
		if (st[i] == '?') cou++;
		else 
		{
			if (!dic.count(st[i]))
			{
				sum++;
				dic.insert(st[i]);
			}
			if (st[i] == ch) n += cou;
			else m += cou;
			cou = 0;
		} 
	}
	int ans = ((n%2)?-1:1)*((m%2)?-1:1);
	if (m == 0) 
		if (sum%2) cout << "Yes" << endl;
		else cout << "No" << endl; 
	if (m == 1) cout << "Yes" << endl; 
	if (m >= 2) 
		if (ans == -1) cout << "Yes" << endl;
		else cout << "No" << endl; 
	return 0;
}
