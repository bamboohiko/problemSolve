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
const LL mod = 1e9 + 7;
int a[100100];
int main() {
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (int i = 1;i < n; i++) scanf("%d",&a[i]);a[n] = 0;
        LL ans = 26;
        for (int i = n-1;i >= 1; i--) {
            if (!a[i]) ans = ans*25%mod;
            else if (a[i] != a[i+1]+1) {
                ans = 0;
                break;
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}

