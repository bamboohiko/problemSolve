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
typedef long long LL;
struct matrix{
	LL a1,a2,b1,b2;
	matrix mul(matrix& x,matrix& y)
	{
		matrix z;
		z.a1 = x.a1*y.a1 + x.a2*y.b1;
		z.a2 = x.a1*y.a2 + x.a2*y.b2;
		z.b1 = x.b1*y.a1 + x.b2*y.b1;
		z.b2 = x.b1*y.a2 + x.b2*y.b2;
		return z;  
	}
	matrix mod(matrix& x,int n)
	{
		matrix z;
		z.a1 = x
	}
};
int main()
{
	int a,b,n;
	while (scanf("%d%d%d",&a,&b,&n) != EOF)
	{
		
	}
	return 0;
}
