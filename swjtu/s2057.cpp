#include<iostream>
using namespace std;
int dp[2010];
int main()
{int t;
	cin >> t;
	dp[0] = 0;
	for (int i = 1; i <= 1800; i++)
		dp[i] = dp[i-1]+(i-1);
	while (t--)
		{int n,m,k;
		cin >> n >> m >> k;
		cout << dp[n*m*k] << endl;
		}
	return 0;
}
