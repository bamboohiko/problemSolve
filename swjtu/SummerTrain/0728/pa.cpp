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
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        for (int i = 0;i < n; i++) scanf("%d",&a[i]);
        sort(a,a+n);
        int ans = 0;
        for (int i = n-1;i >= 2; i--)
            for (int j = i-1;j >= 1; j--) {
                int k = lower_bound(a,a+j,a[i]-a[j]) - a;
                if (k != -1 && a[k] == a[i]-a[j]) {
                    ans = a[i];
                    goto lambel;
                }
            }
        lambel: printf("%d\n",ans);
    }
	return 0;
}


