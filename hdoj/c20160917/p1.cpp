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
const int maxn = 1e9 + 1;
int a[10001000],sz;
void init() {
    a[0] = 1;
    sz = 1;
    while (a[sz-1] < maxn) {
        int m2 = a[lower_bound(a,a+sz,(a[sz-1]+1)/2.0) - a];
        int m3 = a[lower_bound(a,a+sz,(a[sz-1]+1)/3.0) - a];
        int m5 = a[lower_bound(a,a+sz,(a[sz-1]+1)/5.0) - a];
        int m7 = a[lower_bound(a,a+sz,(a[sz-1]+1)/7.0) - a];
        a[sz++] = min(min(m2*2,m3*3),min(m5*5,m7*7));
    }
    //cout << sz << endl;
}
int main() {
    init();
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        int loc = lower_bound(a,a+sz,n) - a;
        printf("%d\n",a[loc]);
    }
	return 0;
}
