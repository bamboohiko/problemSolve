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
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
double dis(double x1,double y1,double x2,double y2) {
    double x = x1-x2,y = y1-y2;
    return sqrt(x*x + y*y);
}
int main() {
    int x,y,x1,y1;
    int t;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&x,&y);
        x1 = y1 = x+y;
        printf("%.0lf\n",dis(x,y,x1,0)*dis(x,y,0,y1));
    }
    return 0;
}
