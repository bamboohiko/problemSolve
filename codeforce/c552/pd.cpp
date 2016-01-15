#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps = 1e-8;
struct point {
    double x,y;
};
int dcmp(double x) {
    if(fabs(x) < eps) return 0;
    return x < 0?-1:1;
}
bool cmp(double a,double b) {
    return dcmp(a-b)<0;
}
bool cmppoint(point a,point b) {
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}
point p[1010];
double ang[1010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    sort(p+1,p+n+1,cmppoint);
    long long ans = 0;
    for (int i = 1;i <= n; i++) {
        int m = 0;
        for (int j = i+1; j <= n; j++)
            if (i != j) ang[m++] = atan2(p[j].y-p[i].y,p[j].x-p[i].x);
        sort(ang,ang+m,cmp);
        //for (int j = 0;j < m; j++) cout << ang[j] << " ";cout << endl;
        int cou = 0,sum = 1;
        for (int j = 1; j < m; j++)
            if (dcmp(ang[j] - ang[j-1]) == 0) sum++;
            else {
                cou += sum*(sum-1)/2;
                sum = 1;
            }
        cou += sum*(sum-1)/2;
        //cout << cou << endl;
        ans += m*(m-1)/2 - cou;
        //cout << ans << endl;
    }
    printf("%d\n",ans);
	return 0;
}
