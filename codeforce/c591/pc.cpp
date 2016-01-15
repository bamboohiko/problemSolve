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
int a[500100];
int main() {
    int n,k;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
    int ans = 0;
    for (int i = 1;i <= n; ) {
        int l = i,r;
        while (l < n && a[l + 1] == a[l]) l++;
        r = l+1;
        if (r >= n) break;
        while (r < n && a[r+1] != a[r]) r++;
        //cout << l << " " << r <<endl;
        ans = max(ans,(r-l) >> 1);
        if ((r-l)%2 == 1) {
            int mid = (l + r) >> 1;
            for (int j = l+1;j <= mid; j++) a[j] = a[l];
            for (int j = mid+1;j < r; j++) a[j] = a[r];
        } else
        for (int j = l+1;j < r; j += 2) a[j] = a[l];
        i = r+1;
    }
    printf("%d\n",ans);
    printf("%d",a[1]);
    for (int i = 2;i <= n; i++) printf(" %d",a[i]);
    printf("\n");
	return 0;
}
