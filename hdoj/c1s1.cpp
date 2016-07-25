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
//int a[100010];
int main()
{
	/*
	int a,b;
	while (scanf("%d%d",&a,&b) != EOF)
		printf("%d\n",a+b);
	*/
	/*
	int t,a,b;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",a+b);
	}
	*/
	/*
	int a,b;
	while (scanf("%d%d",&a,&b) != EOF && (a || b))
		printf("%d\n",a+b);
	*/
	/*
	int n;
	while (scanf("%d",&n) != EOF && n)
	{
		int sum = 0,x;
		for (int i = 1;i <= n; i++)
		{
			scanf("%d",&x);
			sum += x;
		}
		printf("%d\n",sum); 
	}
	*/
	/*
	int t,n;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		int sum = 0,x;
		for (int i = 1;i <= n; i++)
		{
			scanf("%d",&x);
			sum += x;
		}
		printf("%d\n",sum);
	}
	*/
	/*
	int n;
	while (scanf("%d",&n) != EOF)
	{
		int sum = 0,x;
		for (int i = 1;i <= n; i++)
		{
			scanf("%d",&x);
			sum += x;
		}
		printf("%d\n",sum);
	}
	*/
	/*
	int a,b;
	while (scanf("%d%d",&a,&b) != EOF)
		printf("%d\n\n",a+b);
	*/
	int t,n;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		int sum = 0,x;
		for (int i = 1;i <= n; i++)
		{
			scanf("%d",&x);
			sum += x;
		}
		printf("%d\n",sum);
		if (t) printf("\n"); 
	}
	return 0;
}

