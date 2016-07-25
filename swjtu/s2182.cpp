#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
using namespace std;
map<string,int> dic;
int main()
{int n,k = 0;
	while (cin >> n && n)
	 	{printf("Case #%d:\n",++k);
		string ans,st;
	 	int m = 0;
	 	dic.clear();
		 for (int i = 1;i <= n; i++)
	 		{cin >> st;
	 		if (!dic.count(st)) dic[st] = 1;
	 		else dic[st]++;
	 		if (dic[st] > m || (dic[st] == m && st < ans)) 
	 			{m = dic[st];
	 			ans = st;
	 			}
	 		}
	 	cout << ans << endl;
	 	}
	return 0;
}
