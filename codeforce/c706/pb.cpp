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
int a[100100];
int main() {
    int n,q,k;
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) scanf("%d",&a[i]);
    sort(a,a+n+1);
    scanf("%d",&q);
    for (int i = 0;i < q; i++) {
        scanf("%d",&k);
        int loc = upper_bound(a,a+n+1,k) - a;
        printf("%d\n",loc-1);
    }
	return 0;
}
