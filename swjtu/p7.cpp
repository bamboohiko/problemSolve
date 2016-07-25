#include<iostream>
#include<cstring>
using namespace std;
long long f[100010];
int main()
{int t;
	freopen("test.in","r",stdin);
	scanf("%d",&t);
	while (t--)
		{int n;
		long long ans = 0;
		scanf("%d",&n);
		memset(f,0,sizeof(f));
		for (int i = 0;i < (n+1)/2; i++)
			{f[i+1]=f[i]+n-2*i;
			f[n-i]=f[i+1];
			}
		for (int i = 1;i <= n; i++)
			{long long x;
			scanf("%lld",&x);
			if (f[i]%2) ans^=x;
			}
		printf("%lld\n",ans);
		}
	return 0;
}
