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
const double eps = 1e-6;
struct point{
	int x,y;
};
point a[50100];
bool equals(double x,double y)
{
	return abs(x-y) < eps;
}
void figure(point p1,point p2,double& k,int& d)
{
	if (p1.x == p2.x) {d = 1;return;}
	double x1 = p1.x,x2 = p2.x,y1 = p1.y,y2 = p2.y;
	k = (y2 - y1)/(x2 - x1);
	d = 0;
}
bool cmp(double k1,int d1,double k2,int d2)
{
	if (d1 && d2) return true;
	if (d1 || d2) return false;
	return equals(k1,k2);
}
int main()
{
	int n,loc,d1 = 0,d2 = 0,dis = 0;
	double k1,k2;
	scanf("%d",&n);
	scanf("%d%d",&a[1].x,&a[1].y);
	scanf("%d%d",&a[2].x,&a[2].y);
	figure(a[1],a[2],k1,d1);
	for (int i = 3;i <= n; i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		figure(a[i-1],a[i],k2,d2);
		if (cmp(k1,d1,k2,d2))
		{
			if (dis) {loc = i-3;break;}
		}
		else dis++;
 		k1 = k2;d1 = d2;
	}
	if (!loc) loc = n-dis+1;
	printf("%d %d\n",a[loc].x,a[loc].y);
	return 0;
}
