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
int G[30][30];
int main()
{
	int n,dis = 0,fr = -1,ed = -1;
	string a,b;
	cin >> n;
	cin >> a >> b;
	for (int i = 1;i <= n; i++)
		if (a[i-1] != b[i-1]) 
		{
			dis++;
			G[a[i-1] - 'a'][b[i-1] - 'a'] = i; 
		}
	if (dis >= 2)
	{
		int ok = 1;
		for (int i = 0;i < 26; i++)
			for (int j = i+1;j < 26; j++)
				if (G[i][j] && G[j][i])
				{
					fr = G[i][j];
					ed = G[j][i];
					dis -= 2;
					ok = 0;
					goto lambel;
				}
			for (int i = 0;i < 26; i++)
				for (int j = 0;j < 26; j++)
					if (G[i][j])
						for (int k = 0;k < 26;k++)
							if (G[j][k])
							{
								fr = G[i][j];
								ed = G[j][k];
								dis -= 1;
								goto lambel;
							}
		lambel: ; 
	} 
	printf("%d\n%d %d\n",dis,fr,ed);
	return 0;
}
