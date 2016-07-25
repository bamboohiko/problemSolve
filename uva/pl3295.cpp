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
typedef long long LL;
int main() {
    int ca = 0;
    LL n,m,p;
    while (scanf("%lld%lld",&n,&m) != EOF) {
        if (n == 0 && m == 0) break;
        n++;m++;p = n*m;
        LL ans = - n*m*(m-1)*(m-2)/6 - m*n*(n-1)*(n-2)/6;
        ans += p*(p-1)*(p-2)/6;
        printf("Case %d: %lld\n",++ca, ans);
    }
	return 0;
}
