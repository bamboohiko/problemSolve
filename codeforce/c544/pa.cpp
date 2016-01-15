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
	int n;
	string st;
	scanf("%d",&n);
	cin >> st;
	for (int i = 0;i < st.length(); i++)
		dic.insert(st[i]);
	if (dic.size() >= n) {
		dic.clear();
		dic.insert(st[0]);
		printf("YES\n");
		cout << st[0];
		for (int i = 1;i < st.length(); i++) {
			if (!dic.count(st[i]) && dic.size() < n) cout << endl;
			dic.insert(st[i]);
			cout << st[i];
		}
	}
	else printf("NO\n");
	return 0;
}
