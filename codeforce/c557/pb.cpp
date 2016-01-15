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
const int MAXN = 2e5 + 100;
double a[MAXN];
int main()
{
    int n;double w,sum;
    scanf("%d%lf",&n,&w);
    for (int i = 0;i < n+n; i++)
        scanf("%lf",&a[i]);
    sort(a,a+n+n);
    if (a[0]*2 <= a[n]) sum = a[0]*3*n;
    else sum = a[n]*1.5*n;
    printf("%lf",min(sum,w));
	return 0;
}
