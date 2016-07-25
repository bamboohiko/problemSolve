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
const int maxn = 5e4 + 10;
string st[maxn];
bool cmp(string a,string b) {
	return a + b > b + a;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	for (int ca = 1;ca <= t;ca++) {
		scanf("%d",&n);
		for (int i = 0;i < n; i++) 
			cin >> st[i];
		sort(st,st+n,cmp);
		printf("Case #%d: ",ca);
		int rec = 1;
		for (int i = 0;i < n; i++) 
			if (rec) {
				for (int j = 0;j < st[i].size(); j++)
					if (st[i][j] != '0') {
						cout << st[i].substr(j);
						rec = 0;
						break;
					} 
			} else {
				cout << st[i];
			}
		if (rec) cout << "0";
		cout << endl;
	}
	return 0;
}
