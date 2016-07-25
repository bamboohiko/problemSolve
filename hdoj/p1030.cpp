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
void area(int k,int& r,int& c)
{
	if (k == 1)
	{
		r = 1;c = 1;return;
	}
	r = trunc(sqrt(k-1)) + 1;
	c = k - (r-1)*(r-1);
}
int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m) != EOF)
	{
		if (n > m) swap(n,m);
		int r1,c1,r2,c2;
		area(n,r1,c1);
		area(m,r2,c2);
		int ans = abs((c2-c1) - (r2-r1));
		if (ans > r2 - r1)
			ans += r2 - r1;
		else
		{
			if ((r2-r1+ans)%2) 
			{
				ans = (r2 - r1)*2;
				if (c1%2) ans--;
				else ans++;
			}
			else ans = (r2 - r1)*2;
		}
  		printf("%d\n",ans);
 	}
	return 0;
}
