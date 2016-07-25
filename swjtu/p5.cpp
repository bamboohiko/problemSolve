#include<iostream>
using namespace std;
long long gcd(long long a,long long b)
{long long t;
	while (b)
		{t = a%b;
		a = b;
		b = t;
		}
	return a;
}
long long mul(long long a,long long b,long long c,long long m)
{long long k,t = 6;
	k = gcd(t,a);a/=k;t/=k;
	k = gcd(t,b);b/=k;t/=k;
	k = gcd(t,c);c/=k;t/=k;
	return a%m*b%m*c%m;
}
long long mult(long long a,long long b,long long m)
{
	if (a%2) b/=2;
	else a/=2; 	
	return a%m*b%m;
}
long long f(long long n,long long m)
{
	if (n == 0) return 0;
	if (n == 1) return 0;
	if (n == 2) return 1;
	long long nt = n/2-1;m++;
	return mul(n-1,n,2*n-1,m)+m-mul(nt,nt+1,2*nt+1,m)+mult(nt,nt+1,m);
}
int main()
{long long n,m;
	while (cin >> n >> m)
		cout << f(n,m)%(m+1) << endl;
	return 0;
}
