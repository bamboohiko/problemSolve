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
int a[1000100];
bool rec[1000100];
/*
int big(int l,int r,int k)
{
	while (l < r)
	{
		int mid = l + (r - l)/2;
		if (k >= a[mid + 1]) l = mid+1;
		else r = mid; 
	}
	return l;
}
int small(int l,int r,int k)
{
	while (l < r)
	{
		int mid = l + (r - l)/2;
		if (k <= a[mid]) r = mid;
		else l = mid+1;
	}
	if (k != a[l]) return 0;
	return l;
}
*/
int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m) != EOF)
	{
		memset(rec,0,sizeof(rec));
		int k,sl,sr,l,r;
		for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for (int i = 1;i <= m; i++)
		{
			scanf("%d",&k);
			
			l = 1,r = n;
			while (l < r)
			{
				int mid = l + (r - l)/2;
				if (k <= a[mid]) r = mid;
				else l = mid+1;
			}
			if (k != a[l]) sl = 0;
			else sl = l;
	
			if (!sl || rec[sl]) 
			{
				printf("0\n");
				continue;
			}
			l = 1,r = n;
			while (l < r)
			{
				int mid = l + (r - l)/2;
				if (k >= a[mid + 1]) l = mid+1;
				else r = mid; 
			}
			sr = l;
			//cout << l << " " << r << endl;
			printf("%d\n",sr-sl+1);
			rec[sl] = true;
		}
	}
	return 0;
}
