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
const double PI = 3.141;
struct point{
	double x,y;
};
point p[1010],pa,pb;
double s;
double dis2(point a,point b) {
	double dx = a.x - b.x,dy = a.y - b.y;
	return dx*dx+dy*dy;
}
bool cmp(point a,point b) {
	return dis2(a,pa) < dis2(b,pa);
}
int main()
{
	int n,ca = 0;
	while (scanf("%d",&n) != EOF && n) {
		scanf("%lf%lf%lf%lf%lf",&pa.x,&pa.y,&pb.x,&pb.y,&s);
		for (int i = 1;i <= n; i++) 
			scanf("%lf%lf",&p[i].x,&p[i].y);
		sort(p+1,p+n+1,cmp);
		p[0] = pa;
		int ans = 0;
		for (int i = 0;i <= n; i++) {
			double d = dis2(p[i],pa);
			if (PI*d > s) break;
			d = s/PI - d;
			int sum = i;
			for (int j = i+1;j <= n; j++) 
				if (dis2(p[j],pb) <= d) sum++;
			ans = max(ans,sum);
		}
		printf("%d. %d\n",++ca,n-ans);
	}
	return 0;
}
