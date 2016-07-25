#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const int cou = 100000; 
struct point{
	double x,y;
	point(double x=0,double y=0):x(x),y(y) {}
};
double dis(point a,point b)
{
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
int main()
{point a,b,c,now;
int x1,x2,y1,y2,x,y;
	srand(time(NULL));
	while (cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y)
		{double ans = 1e9,sum; 
		x1 = max(int(a.x*100),max(int(b.x*100),int(c.x*100)));
		x2 = min(int(a.x*100),min(int(b.x*100),int(c.x*100)));
		y1 = max(int(a.y*100),max(int(b.y*100),int(c.y*100)));
		y2 = min(int(a.y*100),min(int(b.y*100),int(c.y*100)));
		//cout << x1 << " " << x2 << endl;
		for (int i = 0;i < cou; i++)
			{now.x = (x2 + rand()%(x1-x2))/100.0;
			now.y = (x2 + rand()%(x1-x2))/100.0;
			//cout << now.x << " " << now.y << endl; 
		 	sum = dis(now,a)+dis(now,b)+dis(now,c);
		 	ans = min(sum,ans);
			}
		printf("%.2lf\n",ans);
		}
	return 0;
}
