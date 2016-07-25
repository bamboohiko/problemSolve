#include<iostream>
#include<cstring>
using namespace std;
int a[1010];
int main()
{int t;
	cin >> t;
	while (t--)
		{memset(a,0,sizeof(a));
		int n,k,m,sum = 0,ok = 0,ans = 0;
		cin >> n >> k;
		for (int i = 1;i <= n; i++)
			{cin >> m;
			int iq;
			for (int j = 1;j <= m; j++)
				{cin >> iq;
				if (iq >= k) a[i]++;
				}
			if (a[i]) ok++;
			sum+=a[i];
			}
		if ((ok == 0) && (ok == 1)) cout << 0 << endl;
		else 
			{for (int i = 1;i < n; i++)
				ans+=(sum-=a[i])*a[i];
			cout << ans << endl;
			}
		}
	return 0;
}
