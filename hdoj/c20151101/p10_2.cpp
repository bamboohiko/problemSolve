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
#define max(a,b) (a>b?a:b)
using namespace std;
int a[1010];
int main() {
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
        int ans = 0,sum,d;
        for (int i = 1;i < n; i++) {
            if (n > 100) i++;
            for (int j = i+1;j <= n; j++) {
                sum = a[i]+a[j];
                for (int k = 1;k <= n; k++)
                    if (k != i && k != j) {
                        d = sum^a[k];
                        ans = ans > d?ans:d;
                    }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
