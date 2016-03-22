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
    LL n,m,ans = 0;
    scanf("%I64d%I64d",&n,&m);
    if (m > n/2) ans = n*(n-1)/2;
    else ans = (n-1+n-m)*m/2 + (n-m-m)*m + (m-1)*m/2;
    printf("%I64d\n",ans);
	return 0;
}

