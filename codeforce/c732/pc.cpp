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
    LL b,d,s;
    scanf("%I64d%I64d%I64d",&b,&d,&s);
    LL com = min(min(b,d),s),ans = 0;
    b -= com;d -= com;s -= com;
    LL m = max(max(b,d),s);
    LL d1 = b+d+s-m;
    if (b > 0) b -= d1;
    if (d > 0) d -= d1;
    if (s > 0) s -= d1;
    LL d2 = b+d+s;
    if (d2 > 0) d2--;
    else if (d1 > 0) d1--;
    printf("%I64d\n",d2*2+d1);
	return 0;
}
