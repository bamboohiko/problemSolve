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
string st;
int cou[30];
int main()
{
	int t,k;
	scanf("%d",&t);
	while (t--)
	{
		long long ans = 0;
		memset(cou,0,sizeof(cou));
		cin >> st >> k;
		int head = 0;
		for (int i = 0;i < st.size(); i++)
		{
			cou[st[i] - 'a']++;
			while (cou[st[i] - 'a'] > k)
				cou[st[head++] - 'a']--;
			ans += i - head + 1;
		}
		cout << ans << endl;
	}
	return 0;
}
