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
struct point{
	long long x,y;
	const point operator -(const point& rhs)
	{
		point ans;
		ans.x = x - rhs.x;
		ans.y = y - rhs.y;
		return ans;
	}
	const bool operator <(const point& rhs)
	{
		return x*rhs.y - y*rhs.x < 0; 
	}
	const bool operator == (const point& rhs)
	{
		return x*rhs.y - y*rhs.x == 0;
	}
};
point a[1010],s[1010];
bool cmp(point a,point b)
{
	return a.x*b.y - b.x*a.y < 0;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while (t--)
	{
		int ans = 0;
		 scanf("%d",&n);
		 for (int i = 1;i <= n; i++)
		 	scanf("%d%d",&a[i].x,&a[i].y);
		 for (int i = 1;i < n; i++)
		 {
		 	for (int j = i+1;j <= n; j++)
		 	{
		 		s[j-i] = a[j]-a[i];
		 		//cout << s[j-i].x << " " << s[j-i].y << endl;
		 	}	
			sort(s+1,s+n-i+1,cmp);
		 	int sum = 1;
		 	for (int j = 2;j <= n-i; j++)
		 		if (s[j] == s[j-1]) 
		 			sum++;
		 		else 
		 		{
		 			ans += sum*(sum-1) >> 1;
		 			sum = 1;
				}
			ans += sum*(sum-1) >> 1;
		 }
		 printf("%d\n",ans);
	}
	return 0;
}
