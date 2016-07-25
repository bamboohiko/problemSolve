#include<cstdio>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{int t;
	while (b)
		{t = a%b;
		a = b;
		b = t;
		}
	return a;
}
int main()
{int n,m;
	while (scanf("%d%d",&n,&m) != EOF)
		{if (n > m) swap(n,m);
		int k = 1;
		while (k*n+n <= m) k++;
		printf("%d\n",((m-k*n)/gcd(n,m)+k)*n);
		}
	return 0;
}
