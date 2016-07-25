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
double a[10100];
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i = 1;i <= n; i++) scanf("%lf",&a[i]);
    double l = 0,r = INF;
    while (r-l > eps) {
        LL sum = 0;
        double mid = (l + r)/2;
        for (int i = 1;i <= n; i++) sum += (int)(a[i]/mid);
        if (sum >= k) l = mid;
        else r = mid;
    }
    printf("%.2f\n",floor(r*100)/100);
	return 0;
}

