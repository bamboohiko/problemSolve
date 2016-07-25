#include<iostream>
using namespace std;
int gcd(int a,int b)
{int t;
	while (b)
		{t=a;
		 a=b;
		 b=t%b;
		}
	return a;
}
int lcm(int a,int b)
{
	return a*b/gcd(a,b);
}
int main()
{int a,b;
	while (cin >> a >> b)
		cout << lcm(a,b) << endl;
}
