#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
string st[110];
bool cmp(string a,string b)
{
	return a.size() < b.size(); 
}
void revense(string &a,string &b)
{
	b = "";
	for (int i = a.size()-1;i >= 0; i--)
		b = b + a[i];
} 
bool check(string &p1,string &p2)
{
	for (int i = 1;i < n; i++)
		if (st[i].find(p1) == string::npos && st[i].find(p2) == string::npos) return false;
 	return true; 
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0;i < n; i++)
			cin >> st[i];
		sort(st,st+n,cmp);
		int ans = 0;
		for (int len = st[0].size();len > 0; len--)
		{
			if (ans) break;
			for (int loc = 0;loc + len <= st[0].size(); loc++)
			{
				string p1,p2;
				p1 = st[0].substr(loc,len);
				revense(p1,p2);
				//cout << p1 << endl;
				if (check(p1,p2)) 
				{
					ans = len;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
