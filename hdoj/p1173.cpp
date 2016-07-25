#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
double r[1001000],c[1001000];
int main()
{int n;
	while (cin >> n && n)
		{for (int i = 0; i < n; i++)
			cin >> r[i] >> c[i];
		sort(r,r+n);
		sort(c,c+n);
		if (n%2) 
			printf("%.2lf %.2lf\n",r[(n-1)/2],c[(n-1)/2]);
		else
			printf("%.2lf %.2lf\n",r[n/2],c[n/2]);
		}
	return 0;
}

