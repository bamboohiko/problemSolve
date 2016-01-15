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
double f[110][110][110];
bool fin(int i,int j,int k) {
	int a = (i > 0)?1:0;
	int b = (j > 0)?1:0;
	int c = (k > 0)?1:0;
	return a+b+c <= 1;
}
int main()
{
	int m,n,p;
	scanf("%d%d%d",&m,&n,&p);
	f[m][n][p] = 1;
	for (int i = m;i >= 0; i--)
		for (int j = n;j >= 0; j--)
			for (int k = p;k >= 0; k--)
				//if (!fin(i,j,k))
			     {
					double mul = i*j+j*k+k*i;
					if (!mul) continue;
					//cout << i << " " << j << " " << k << " " << f[i][j][k]<< ends;
					if (j > 0) f[i][j-1][k] += (i*j)/mul*f[i][j][k];//cout << f[i][j-1][k] << endl;
					if (k > 0) f[i][j][k-1] += (j*k)/mul*f[i][j][k];
					if (i > 0) f[i-1][j][k] += (k*i)/mul*f[i][j][k];
				}
	double ans = 0;
	for (int i = 1;i <= m; i++) ans += f[i][0][0];
	printf("%.12lf ",ans);
	ans = 0;
	for (int i = 1;i <= n; i++) ans += f[0][i][0];
	printf("%.12lf ",ans);
	ans = 0;
	for (int i = 1;i <= p; i++) ans += f[0][0][i];
	printf("%.12lf\n",ans);
	return 0;
}
