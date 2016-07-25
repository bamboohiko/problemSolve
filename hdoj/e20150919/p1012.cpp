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
const int maxn = 5e6 + 100;
const long long inf = 1e7;
long long a[maxn];
int main() {
    int t,n;
    long long a,b;
    while (t--) {
        scanf("%d%lld%lld",&n,&a,&b);
        int loc = 0;
        for (int i = 0;i < n; i++) {
            scanf("%d",&a[i]);
            x = min(x,abs(a[i]));
        }
        sort(a,a+n);
        int ans = a*a[0]*a[0] + b*a[1];
        if (n <= 4) {
            for (int i = 0;i < n; i++)
                for (int j = 0;j < n; j++)
                    if (i != j) {
                        ans = max(ans,a*a[i]*a[i] + b*a[j]);
                    }
        } else {

        }
    }
	return 0;
}

