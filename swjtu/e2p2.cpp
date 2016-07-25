#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
map<string,int> dic;
vector<string> v;
int main()
{int n,t=0;
	while (cin >> n && n)
		{printf("Case #%d:\n",++t);
		dic.clear();
		v.clear();
		string st;
		for (int i = 1;i <= n; i++)
			{cin >> st;
			if (dic.count(st)) dic[st]++;
			else
				{v.push_back(st);
				dic[st] = 1;
				}
			}
		sort(v.begin(),v.end());
		int ans=0;
		for (int i = 1;i < v.size(); i++)
			if (dic[v[i]] > dic[v[ans]]) ans = i;
		cout << v[ans] << endl;
		}
	return 0;
}
