#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAX = 1000000000;
int rec[100000],prime[100000];
int main()
{int n,t = 0;
	n = sqrt(MAX)+1;
	for (int i = 2;i <= n; i++)
		if (!rec[i])
			{for (int j = i+i;j <= n; j+=i)
				rec[j] = 1;
			prime[++t] = i;
			}
	while (cin >> n)
		{int nt = n,ans = 0;
		if (n == 1)
			{cout << ans << endl;
			continue;
			}
		for (int i = 1;i <= t; i++)
			{while (!(n % prime[i])) 
				{ans = prime[i];
				n/=prime[i];
				}
			if (n < prime[i+1]) break;
			}
		if (n > ans) ans = n;
		cout << nt/ans << endl;
		}
	return 0;
}
