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
    int t,n;
    scanf("%d",&t);
    for (int ca = 1;ca <= t; ca++) {
        scanf("%d",&n);
        int m = 0,sum = 0,k;
        for (int i = 1;i <= n; i++) {
            scanf("%d",&k);
            m = max(m,k);
            sum += k;
        }
        int d = sum/2,ans;
        if (m-d <= d/2) ans = d;
        else {
            ans = (sum-m)*2;
            if (d&1) ans++;
        }
        printf("Case #%d: %d\n",ca,ans);
    }
	return 0;
}
