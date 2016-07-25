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
int a[200100];
int bis(int l,int r,int dec,int inc)
{
	
}
int main()
{
	int n,w,h;
	while (scanf("%d%d%d",&n,&w,&h) != EOF)
	{
		long long inc = 0,dec = w*h,ans = w*h,sum = 0;
		memset(a,0,sizeof(a));
		for (int i = 1;i <= n; i++) 
		{
			scanf("%d",&a[w+i]);
			sum += a[w+i];
		}
		int r = sum/w;
		for (int i = 1;i <= n+w; i++)
		{
			if (a[i] > h) inc -= a[i]-h;
			else dec -= h-a[i];
			if (a[w+i] > h) inc += a[w+i]-h;
			else dec += h-a[w+i];
			ans = min(ans,bis(h,r,dec,inc));
			//cout << inc << " " << dec << endl;
		}
		//for (int i = 1;i <= n+w+w; i++) cout << a[i] << " "; cout << endl;
		if (sum >= w*h) printf("%I64d\n",ans);
		else printf("-1\n");
	}
	return 0;
}
