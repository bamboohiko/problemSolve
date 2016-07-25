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
	while (cin >> st)
	{
		int ans = true;
		if (st.size()%3) ans = false;
		else 
		{
			int k = st.size()/3;
			int a = 0,b = k,c = k+k;
			if (st[a] == st[b] || st[a] == st[c] || st[b] == st[c]) ans = false;
			for (int i = 1;i < k; i++)
				if (st[a+i] != st[a] || st[b+i] != st[b] || st[c+i] != st[c]) ans = false;
		}
		if (ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
