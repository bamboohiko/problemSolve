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
struct dat{
	int x,y;
};
dat a[110];
bool cmp(dat a,dat b)
{
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
int main()
{int n;
	while (scanf("%d",&n) != EOF && n)
	{
		for (int i = 0;i < n; i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		sort(a,a+n,cmp);
		int sum = 0,fr = 0,ed = 0;
		for (int i = 0;i < n; i++)
			if (fr <= a[i].x && ed >= a[i].y)
			{
				fr = a[i].x;
				ed = a[i].y;
			} 
			else if (ed <= a[i].x)
			{
				sum++;
				fr = a[i].x;
				ed = a[i].y;
			}	
		printf("%d\n",sum);
	}
	return 0;
}
