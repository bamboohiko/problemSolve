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
    LL n,m;
    while (scanf("%lld%lld",&n,&m) != EOF && n && m) {
        if (n < m) swap(n,m);
        LL ans = n*m*(m-1) + m*n*(n-1);
        ans += 4*m*(m-1)*(m+1)/3 + 2*(n-m-1)*m*(m-1);
        printf("%lld\n",ans);
    }
	return 0;
}

