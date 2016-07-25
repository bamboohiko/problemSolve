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
const int maxn = 2015 + 10;
int f[maxn],a[maxn];
int main() {
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (int i = 1;i < n; i++) {
            scanf("%d",&a[i]);
            f[i] = -INF;
        }
        f[0] = n*a[1];
        for (int j = n-2;j >= 1;j--)
            for (int i = j;i <= n-2; i++) {
                f[i] = max(f[i],f[i-j]+a[j+1]-a[1]);
            }
        printf("%d\n",f[n-2]);
    }
	return 0;
}

