#include<iostream>
using namespace std;
int a[100010];
int main()
{int t;
	freopen("test.in","r",stdin);
	cin >> t;
	while (t--)
		{int n;
		cin >> n;
		for (int i = 1;i <= n; i++)
			cin >> a[i];
		int ans = 0;
		for (int i = 1;i <= n; i++)
			for (int j = i;j <= n; j++)
				for (int k = i;k <= j; k++)
					ans^=a[k];
		cout << ans << endl;
		}
}
