#include<iostream>
using namespace std;
long long gcd(long long a,long long b)
{int t;
	while (b)
		{t=a;
		 a=b;
		 b=t%b;
		}
	return a;
}
long long lcm(long long a,long long b)
{
	return a*b/gcd(a,b);
}
int main()
{int m,t;
 long long n,k;
	cin >> t;
	for (int i = 1;i <= t; i++ )
		{cin >> m;n=1;
		for (int j = 1;j <= m; j++) 
			{cin >> k;
			 n=lcm(n,k);
			}
		cout << n << endl;
		}
	return 0;
}
