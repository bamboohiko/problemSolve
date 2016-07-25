#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxx = 100000,maxb = 5;
double f[maxx+10][maxb+1];
int main()
{
	for (int i = 1;i <= maxx; i++)
		for (int j = 1;j <= maxb; j++)
		{
			double x = i,b = j;
			f[i][j] =  (1 + x)*x/2*(1 - pow((x-1)/x,b));			
		}
	int t;
	cin >> t;
	while (t--)
	{
		int x,b;
		cin >> x >> b;
		printf("%.3lf\n",f[x][b]);
	}
	return 0;
}
