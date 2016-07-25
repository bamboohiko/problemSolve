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
const int maxn = 30;
typedef long long LL;
int main() {
    int t;
    scanf("%d",&t);
    for (int ca = 1;ca <= t;ca++) {
        int n,k;
        scanf("%d%d",&n,&k);
        LL ans = 1;
        if (k > n) ans = 0;
        else {
            for (int i = n;i > n-k; i--) ans *= i;
            LL c = ans;
            for (int i = k;i > 1; i--) c /= i;
            ans *= c;
        }
        printf("Case %d: %lld\n",ca,ans);
    }
	return 0;
}
