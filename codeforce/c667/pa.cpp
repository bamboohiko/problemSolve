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
typedef long long LL;
int main() {
    double d,h,v,e;
    scanf("%lf%lf%lf%lf",&d,&h,&v,&e);
    double s = pi*(d/2)*(d/2);
    if (v/s <= e) puts("NO");
    else {
        puts("YES");
        printf("%.12lf\n",h/(v/s-e));
    }
	return 0;
}

