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
int a[100100];
int main() {
    int t,n,s;
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n,&s);
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
        int l = 1,sum = 0,ans = n+1;
        for (int i = 1;i <= n; i++) {
            sum += a[i];
            while (sum-a[l] >= s) sum -= a[l++];
            if (sum >= s) ans = min(ans,i-l+1);
        }
        if (ans == n+1) ans = 0;
        printf("%d\n",ans);
    }
	return 0;
}

