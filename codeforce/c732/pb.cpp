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
int a[510];
int main() {
    int n,k,ans = 0;
    scanf("%d%d",&n,&k);
    a[0] = k;
    for (int i = 1;i <= n; i++) {
        scanf("%d",&a[i]);
        if (a[i-1] + a[i] < k) {
            ans += k - a[i-1] - a[i];
            a[i] = k - a[i-1];
        }
    }
    printf("%d\n",ans);
    for (int i = 1;i < n; i++) printf("%d ",a[i]);
    printf("%d\n",a[n]);
	return 0;
}
