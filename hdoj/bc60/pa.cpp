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
long long a[100];
int main() {
    int t,n;
    scanf("%d",&t);
    while (t--) {
        long long ans = 1;
        scanf("%d",&n);
        for (int i = 0;i < n; i++) scanf("%I64d",&a[i]);
        if (n == 1) ans = a[0];
        else {
        sort(a,a+n);
        int k = upper_bound(a,a+n,0) - a;
        if (k < n) {
            for (int i = k;i < n; i++) ans *= a[i];
            while (k > 0 && a[k-1] == 0) k--;
            for (int i = 0;i < k-1; i++) ans *= a[i];
            if (k > 0 && k%2 == 0) ans *= a[k-1];
        } else {
            int kk = k;
            while (kk > 0 && a[kk-1] == 0) kk--;
            if (k <= 1) ans = 0;
            else {
                for (int i = 0;i < k-1; i++) ans *= a[i];
                if (k > 0 && k%2 == 0) ans *= a[k-1];
            }
        }
        }
        printf("%I64d\n",ans);
    }
	return 0;
}
