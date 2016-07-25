#include<iostream>
using namespace std;
long long modexp(long long a,long long b,long long n)
{long long t=1;
	while (b)
		{if (b%2) t=t*a%n;
		a=a*a%n;
		b/=2; 
		}
	return t;
}
int main()
{long long a,b,n;
	cin >> a >> b >> n;
	cout << modexp(a%n,b,n) << endl;
	return 0;
}
