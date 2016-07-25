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
int a[1001000][2];
void find(int n,int k)
{
	int l = 1,r = n,la = 0,ans = 0;
	while (l < r)
	{
		int i = l,j = r,fr = 1-la;
		for (int loc = r;loc > l; loc--)
			if (a[loc][la] > a[l][la]) a[j--][fr] = a[loc][la];
			else a[i++][fr] = a[loc][la];
		if (k == i) 
		{
			ans = a[l][la];
			break;
		}   
		if (k < i) r = i-1;
		else l = j+1;
		la = fr; 
	}
	if (l == r) ans = a[l][la];
	printf("%d\n",ans);
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n; i++)
		scanf("%d",&a[i][0]);
	if (k > n) printf("-1\n");
	else find(n,k);
	return 0;
}
