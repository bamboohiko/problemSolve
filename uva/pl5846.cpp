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
int a[1010];
int main() {
    int t,n;
    scanf("%d",&t);
    while (t--) {
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        int ans = 0,k;
        for (int i = 1;i <= n; i++) {
            for (int j = i+1;j <= n; j++) {
                scanf("%d",&k);
                if (k) {
                    a[i]++;a[j]++;
                }
            }
            ans += a[i]*(n-1-a[i]);
        }
        ans = n*(n-1)*(n-2)/6 - ans/2;
        printf("%d\n",ans);
    }
	return 0;
}
