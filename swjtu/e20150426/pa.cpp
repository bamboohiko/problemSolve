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
set<int> dic;
int main()
{
	string st;
	int n;
	while (cin >> n) {
		dic.clear();
		if (n == 0) {
			printf("NO\n");
			continue;
		}
		cin >> st;
		for (int i = 0;i < n; i++) {
			if (st[i] >= 'a' && st[i] <= 'z') dic.insert(st[i] - 'a');
			if (st[i] >= 'A' && st[i] <= 'Z') dic.insert(st[i] - 'A');
		}
		bool ans = true;
		for (int i = 0;i < 26; i++)
			if (!dic.count(i)) {
				ans = false;
				break;
			}
		if (ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
