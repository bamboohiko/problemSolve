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
const double pi = 3.1415926;
int main()
{
	double d;
	while (cin >> d && d != -1)
	{
		double ans = 0;
		d /= 180;
		if (d <= 0.5) ans = (1 - d)*(3 - 5*d)/4;
		else ans = (2 - 3*d)*(2 - 3*d)/4;
		printf("%.3lf\n",ans*100);
	}
	return 0;
}
