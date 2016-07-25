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
int a[10010],f[10010];
int main()
{
	int n;
	scanf("%d",&n);
	f[0] = 0;
	int loc = 0;
	for (int i = 1;i <= n; i++) 
	{
		scanf("%d",&a[i]);
		f[i] = max(f[i-1],0) + a[i];
		if (f[i] > f[loc] || !(f[i] || f[loc])) loc = i;
	}
	int la = loc,fi = la-1;
	if (!loc)
	{
		la = n;
		fi = 1;
	}
	else 
	{
			while (fi && f[fi] + a[fi+1] == f[fi+1]) fi--;
			fi++;
	}	
	printf("%d %d %d\n",f[loc],a[fi],a[la]);
	return 0;
}

