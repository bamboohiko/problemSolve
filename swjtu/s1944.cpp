#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int f[110],sav[110];
int find(int k)
{int top = 0;
	while (f[k] != k)
		{sav[top++] = k;
		k = f[k];
		}
	while (top--) sav[top] = k; 
	return k;
}
int main()
{int t;
	cin >> t;
	while (t--)
		{int n,m,x,y;
		scanf("%d%d",&n,&m);
		int ans = n;
		for (int i = 1;i <= n; i++) f[i] = i;
		for (int i = 1;i <= m; i++)
			{scanf("%d%d",&x,&y);
			x = find(x);y = find(y);
			if (x != y) 
				{ans--;
				f[x] = y;
				}	
			}
		cout << ans << endl;
		}
	return 0;
}
