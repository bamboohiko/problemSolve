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
string a,b;
int main()
{
	int n;
	while (cin >> n)
	{
		//cin >> n;
		memset(G,0,sizeof(G));
		int dis = 0,t1 = -1,t2 = -1;
		cin >> a >> b;
		for (int i = 0;i < n; i++)
			if (a[i] != b[i])
			{
				G[a[i] - 'a'][b[i] - 'a'] = i+1;
				dis++;
			}
		if (dis >= 2)
		{
			for (int i = 0;i < 26; i++)
				for (int j = i+1;j < 26; j++)
					if (G[i][j] && G[j][i])
					{
						dis -= 2;
						t1 = G[i][j];
						t2 = G[j][i];
						if (t1 > t2) swap(t1,t2);
						goto lambel;
					}
			for (int i = 0;i < 26; i++)
				for (int j = 0;j < 26; j++)
					if (G[i][j])
						for (int k = 0;k < 26; k++)
							if (G[j][k])
							{
								dis--;
								t1 = G[i][j];
								t2 = G[j][k];
								if (t1 > t2) swap(t1,t2);
								goto lambel;
							}
			lambel: ;
		}
		printf("%d\n%d %d\n\n",dis,t1,t2);
	}
	return 0;
}
