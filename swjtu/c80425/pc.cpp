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
long long a[100100];
bool fig(long long t,int n,long long k) {
    long long ans = 0;
    for (int i = 1;i <= n; i++)
        if (a[i] > t)
            ans += (a[i] - t - 1)/(k-1) + 1;
    //cout << t << " " << ans << endl;
    if (ans <= t) return true;
    return false;
}
int main()
{
    int n;long long k;
    scanf("%d",&n);
    long long l = 1,r = 0;
    for (int i = 1;i <= n; i++) {
        scanf("%I64d",&a[i]);
        r = max(r,a[i]);
    }
    scanf("%I64d",&k);
    if (k == 1) {
        l = r;
    }
    while (l < r) {
        //cout << l << " " << r << endl;
        int mid = l + ((r - l) >> 1);
        if (fig(mid,n,k)) r = mid;
        else l = mid + 1;
    }
    printf("%I64d\n",l);
	return 0;
}
