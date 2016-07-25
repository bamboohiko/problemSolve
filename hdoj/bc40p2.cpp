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
const int maxn = 100;
const long long mod = 1e9+7;
long long f[maxn + 10][5010],sum[maxn + 10];
int a[maxn + 10];
int main()
{
	f[2][0] = 1;f[2][1] = 1;sum[2] = 1;
	for (int i = 3;i <= maxn; i++) 
    	for (int j = 0;j <= i*(i-1)/2; j++) {   	
        	for (int k = j; k >= j-i+1; k--)
            	f[i][j] = (f[i][j] + f[i-1][k])%mod;
            sum[i] = (sum[i] + f[i][j]*j) % mod;
   		}
   	for (int i = 1;i <= maxn; i++) printf("%lld\n",sum[i]);
    int n;
	while (scanf("%d",&n) != EOF) {
		long long ans = 0;
		for (int i = n;i >= 1; i--) {
			scanf("%d",&a[i]);
			ans = (ans + sum[i-1]*(a[i]-1)%mod)%mod;
			for (int j = a[i];)
				for (int j = n;j > i; j--)
		}
		printf("%lld\n",ans); 
	}
	return 0;
}
